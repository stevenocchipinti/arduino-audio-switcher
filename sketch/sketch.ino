#include <ESP8266WiFi.h>
#include <WiFiClient.h>
#include <ESP8266WebServer.h>
#include <ESP8266mDNS.h>

#include "./config.h"
#include "./html.h"

const int buttonPin = D5;       // Pin 14
const int ledPin = D6;          // Pin 12
const int relaysPin = D7;       // Pin 13
const int blindsUpPin = D1;     // Pin 5
const int blindsDownPin = D2;   // Pin 4

bool relays = false;            // Accurate state of the relays
String blinds = "unknown";      // Last known state of the blinds
bool buttonWasPressed = false;  // Used for debouncing

ESP8266WebServer server(80);

void setRelays() {
  // I'm using the "state" as a logical flag, such that:
  //    true  = relay on
  //    false = relay off
  // However, the relay board activates when the input is pulled LOW, such that:
  //    LOW   = relay on
  //    HIGH  = relay off
  // Hence, the boolean is being negated
  digitalWrite(relaysPin, !relays);
  digitalWrite(ledPin, relays);
}

String stateJSON() {
  return (String)"{"
    + "\"speakers\": " + (relays ? "true" : "false") + ","
    + "\"blinds\": \"" + blinds + "\""
    + "}";
}

void setup(void) {
  pinMode(buttonPin, INPUT_PULLUP);
  pinMode(ledPin, OUTPUT);
  pinMode(relaysPin, OUTPUT);
  pinMode(blindsUpPin, OUTPUT);
  pinMode(blindsDownPin, OUTPUT);

  // Start with the relays off
  setRelays();

  Serial.begin(115200);
  WiFi.mode(WIFI_STA);
  WiFi.begin(SSID, PASSWORD);

  Serial.println("");
  bool flashIndicator = LOW;
  while (WiFi.status() != WL_CONNECTED) {
    Serial.print(".");
    digitalWrite(ledPin, flashIndicator);
    flashIndicator = !flashIndicator;
    delay(250);
  }
  Serial.println("");
  Serial.print("Connected to ");
  Serial.println(SSID);
  Serial.print("IP address: ");
  Serial.println(WiFi.localIP());

  if (MDNS.begin("esp8266")) {
    Serial.println("MDNS responder started");
  }

  server.on("/", HTTP_GET, []() {
    String html = HTML;
    server.send(200, "text/html", html);
  });

  server.on("/state.json", HTTP_GET, []() {
    server.send(200, "application/json", stateJSON());
  });

  server.on("/on.json", HTTP_POST, []() {
    relays = true;
    server.send(200, "application/json", stateJSON());
  });

  server.on("/off.json", HTTP_POST, []() {
    relays = false;
    server.send(200, "application/json", stateJSON());
  });

  server.on("/up.json", HTTP_POST, []() {
    digitalWrite(blindsUpPin, HIGH);
    delay(100);
    digitalWrite(blindsUpPin, LOW);
    blinds = "up";
    server.send(200, "application/json", stateJSON());
  });

  server.on("/down.json", HTTP_POST, []() {
    digitalWrite(blindsDownPin, HIGH);
    delay(100);
    digitalWrite(blindsDownPin, LOW);
    blinds = "down";
    server.send(200, "application/json", stateJSON());
  });

  server.onNotFound([]() {
    server.send(404, "text/plain", "Page not found");
  });

  server.begin();
  Serial.println("HTTP server started");
}

void loop(void) {
  setRelays();

  if (!buttonWasPressed && digitalRead(buttonPin) == LOW) {
    buttonWasPressed = true;
    relays = !relays;
    delay(50);
  }

  if (buttonWasPressed && digitalRead(buttonPin) == HIGH) {
    buttonWasPressed = false;
    delay(50);
  }

  server.handleClient();
  MDNS.update();
}

