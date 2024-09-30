/*
    This is a basic example of how DashIO message can be used on an ESP32.
    You will need to install the DashioESP library, which in turn uses the DashIO library.
    Bluetooth LE (BLE) is used for communication in this example.

    For detailed documentation and examples, please see: https://dashio.io/guide-arduino-esp32/

    In the example below, the classes DashDevice and MessageData are from the DashIO library.
    1) DashDevice holds all the IoT device information and is used to create messages to send to
       the Dash IoT app (e.g. getKnobMessage and getDialMessage)
    2) MessageData holds the data that is received from the Dash IoT app.
*/

#include "DashioESP.h"

DashDevice dashDevice("ESP32_Type");
DashBLE    ble_con(&dashDevice, true);

int dialValue = 0;

// Function to create Status messages when requested by the Dash IoT app
void processStatus(ConnectionType connectionType) {
    String message((char *)0);
    message.reserve(1024);

    message = dashDevice.getKnobMessage("KB01", dialValue);
    message += dashDevice.getDialMessage("D01", dialValue);

    ble_con.sendMessage(message);
}

// Callback to process incoming messages from the Dash IoT app
void processIncomingMessage(MessageData * messageData) {
    switch (messageData->control) {
    case status:
        processStatus(messageData->connectionType);
        break;
    case knob:
        // If we get a "knob" message from the IoT app, store the value to the
        // dial and send the same value back to a dial on the dash IoT app
        if (messageData->idStr == "KB01") {
            dialValue = messageData->payloadStr.toFloat();
            String message = dashDevice.getDialMessage("D01", dialValue);
            ble_con.sendMessage(message);
        }
        break;
    }
}

void setup() {
    Serial.begin(115200);
    
    ble_con.setCallback(&processIncomingMessage);       // Set incoming message processing callback
    ble_con.begin();                                    // Start the BLE connection
    dashDevice.setup(ble_con.macAddress(), "Joe Name"); // unique deviceID, and device name
}

void loop() {
    ble_con.run(); // Run the BLE connection
}