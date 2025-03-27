#include <Arduino.h>
#include <esp_now.h>
#include <WiFi.h>
#include <esp_wifi.h>
// MAC Address of the receiver: a0:85:e3:4c:5a:ac
// MAC Address of the transmitter: 98:3d:ae:b5:fd:58

// Protos
void readMacAddr(uint8_t* macAddr);

void setup() {

  Serial.begin(115200);

  // Hardware debug LED
  pinMode(LED_BUILTIN, OUTPUT);
  while (!Serial) {
    digitalWrite(LED_BUILTIN, HIGH);
    delay(500);
    digitalWrite(LED_BUILTIN, LOW);
    delay(500);
  }

  WiFi.mode(WIFI_STA);
  WiFi.enableSTA(true);

  uint8_t macAddr[6]; 
  readMacAddr(macAddr);

  while (macAddr == NULL) {
    Serial.println("Failed to read MAC address. Retrying...");
    delay(5000);
    readMacAddr(macAddr);
  }

  Serial.printf("[DEFAULT] ESP32 MAC Address:%02x:%02x:%02x:%02x:%02x:%02x\n", macAddr[0], macAddr[1], macAddr[2], macAddr[3], macAddr[4], macAddr[5]);
  
}

void loop() {
}

void readMacAddr(uint8_t* macAddr) {
  esp_err_t returnCode = esp_wifi_get_mac(WIFI_IF_STA, macAddr); // returns ESP_OK if successful
  if (returnCode != ESP_OK) {
    macAddr = NULL;
  }
}