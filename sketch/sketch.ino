#include <ESP8266WiFi.h>
#include <WiFiClient.h>
#include <ESP8266WebServer.h>
#include <ESP8266mDNS.h>

#include "./config.h"
#include "./html.h"

const int buttonPin = 16;
const int ledPin = 13;

bool state = LOW;
bool buttonWasPressed = false;

ESP8266WebServer server(80);

void setup(void) {
  pinMode(buttonPin, INPUT_PULLDOWN_16);
  pinMode(ledPin, OUTPUT);

  Serial.begin(115200);
  WiFi.mode(WIFI_STA);
  WiFi.begin(SSID, PASSWORD);

  Serial.println("");
  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
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
    server.send(200, "application/json", (String)"{\"switch\": " + (state ? "true" : "false") + "}");
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
  digitalWrite(ledPin, state);

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

