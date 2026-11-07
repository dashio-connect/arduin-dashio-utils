# DashIO

So, what is **DashIO**? It is a quick effortless way to connect your IoT device to your phone, tablet or iPad using the free **Dash IoT** app. It allows easy setup of controls such as Dials, Text Boxes, Charts, Graphs, Notifications..., from your IoT device. You can define the look and layout of the controls on your phone from your IoT device. There are three methods to connect to your phone; Bluetooth Low Energy (BLE), TCP or MQTT.

What is **dash** then? **dash** is an IoT platform based on an MQTT server with extra bits added in to allow you to store data, manage your devices, send notifications, share your devices, and save your **Dash** app setup.


## Discord Community

[![](https://img.shields.io/discord/1313341785430429747?color=5865F2&logo=Discord&style=flat-square)](https://discord.gg/fqvhNV3GQB)

Be a part of the DashIO community by joining our [Discord Server](https://discord.gg/fqvhNV3GQB)

## Documentation

For the big picture on **DashIO**, take a look at our website: <a href="https://dashio.io">dashio.io</a>

For all documentation and software guides: <a href="https://dashio.io/documents">dashio.io/documents</a>

## Dash IoT Application

The **Dash** app is free and available for both Apple and Android devices. Use it to create beautiful and powerful user interfaces to you IoT devices.


<img src="https://dashio.io/wp-content/uploads/2020/11/IMG_4154.jpeg" width="200" />

<img src="https://dashio.io/wp-content/uploads/2020/12/IMG_4203.jpeg" width="600" />

## Release Notes

For previous releases, please refer to <a href="https://github.com/dashio-connect/arduino-dashio">github.com/dashio-connect/arduino-dashio</a>, which is now obsolete.

### 1.2.6 (not released yet)

- Incoming *SAF* messages are now recognised, as control type *storeAndForward*, instead of being dropped as unknown. This is for the *SAF END* message from the **dash** server (`\t<deviceID>\tSAF\tEND\n`). The server sends it after a device's *WHO*, following the Store and Forward messages held for the device in the same payload, or on its own when none are held, so a device that sleeps knows when it can go back to sleep. Check for it in the incoming message callback with `messageData->control == storeAndForward && messageData->idStr == SAF_END_ID`.
- Fix incoming messages being misread when several arrive together in one MQTT or BLE payload (e.g. the held Store and Forward messages the **dash** server sends when a device connects). Every message after the first lost its first two characters, so it kept fields from the message before it (a *SAF END* arrived carrying the previous text box value) and got the wrong BLE connection handle.

### 1.2.5 (30 October 2026)

- Added *MessageData::setBufferSize()* to change the size of a connection's incoming message buffer after construction. Used by DashioESP for *DashioMQTT::incomingBufferSize*.
- Added *DashioDevice::getConfigNAmessage()*
- Fix compile error on AVR boards (*uint*)

### 1.2.4 (9 July 2025)

- Better handling of dashboardID in config messages

### 1.2.3 (8 March 2025)

- Code optimisation
- Update const naming to avoid conflicts

### 1.2.2 (16 October 2024)

- New TextBox message helper functions for Int and Float
- Support for Table Control that will soon be released
- Minor efficiency improvements

### 1.2.1 (1 October 2024)

- Updated library properties

### 1.2.0 (30 September 2024)

- Release to Arduino library




