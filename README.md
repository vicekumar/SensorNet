# SensorNet

This is a small project which uses the ESP-NOW communication protocol to transfer sensor data (PH, temperature, conductivity, water level, etc...) from a hydroponics system to a base station.

## Hardware

Since ESP-NOW is a protocol supporting inter-ESP32/8266 communication, this project requires at least 2 ESP boards - one receiver, and at least one transmitter. It is possible to have more ESP boards operate as a mesh since ESP-NOW can also be used as a broadcast protocol

