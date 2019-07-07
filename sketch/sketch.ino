#include <ESP8266WiFi.h>
#include <WiFiClient.h>
#include <ESP8266WebServer.h>
#include <ESP8266mDNS.h>

#include "./config.h"
#include "./html.h"

const int buttonPin = D0; // Pin 16;
const int relayPin = D7;  // Pin 13;
const int ledPin = D6;  // Pin 13;

bool state = false;
bool buttonWasPressed = false;

ESP8266WebServer server(80);

void setOutput(bool output) {
  // I'm using the "state" as a logical flag, such that:
  //  true  = relay on
  //  false = relay off

  // However, the relay board activates when the input is pulled LOW, such that:
  //  LOW   = relay on
  //  HIGH  = relay off

  // Hence, the boolean is being negated
  digitalWrite(relayPin, !output);
  digitalWrite(ledPin, output);
}

void setup(void) {
  pinMode(buttonPin, INPUT_PULLDOWN_16);
  pinMode(ledPin, OUTPUT);
  pinMode(relayPin, OUTPUT);

  // Start with the relay off
  setOutput(state);

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
    server.send(
      200,
      "application/json",
      (String)"{\"switch\": " + (state ? "true" : "false") + "}");
  });

  server.on("/on.json", HTTP_POST, []() {
    state = true;
    server.send(200, "application/json", (String)"{\"switch\": true}");
  });

  server.on("/off.json", HTTP_POST, []() {
    state = false;
    server.send(200, "application/json", (String)"{\"switch\": false}");
  });

  server.onNotFound([]() {
    server.send(404, "text/plain", "Page not found");
  });

  server.begin();
  Serial.println("HTTP server started");
}

void loop(void) {
  setOutput(state);

  if (!buttonWasPressed && digitalRead(buttonPin) == HIGH) {
    buttonWasPressed = true;
    state = !state;
    delay(50);
  }

  if (buttonWasPressed && digitalRead(buttonPin) == LOW) {
    buttonWasPressed = false;
    delay(50);
  }

  server.handleClient();
  MDNS.update();
}

