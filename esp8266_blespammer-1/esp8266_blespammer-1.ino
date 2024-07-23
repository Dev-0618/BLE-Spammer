                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                void setup() {
  Serial.begin(9600); // Start serial communication with the HM-10 module
  delay(1000); // Wait for HM-10 to initialize

  sendCommand("AT"); // Check if the HM-10 module is responding
  delay(500);
  sendCommand("AT+RENEW"); // Restore factory settings
  delay(500);
  sendCommand("AT+RESET"); // Reset the module
  delay(1000); // Wait for reset to complete
}

void loop() {
  const char* messages[] = {
    "ATRIA",
    "ISE",
    "ALVIN",
    "HACKING",
    "DEVICE HACKED",
    "DEVICE SPAMMED",
    "RANDOM NAMES",
    "HELLO MAM"
  };

  const int messageCount = sizeof(messages) / sizeof(messages[0]);

  for (int i = 0; i < messageCount; i++) {
    setAdvertisingName(messages[i]);
    delay(2000); // Wait for 2 seconds before changing the message
  }
}

void setAdvertisingName(const char* name) {
  sendCommand(String("AT+NAME") + name); // Set the device name
  delay(500); // Ensure the command is processed
  sendCommand("AT+RESET"); // Reset to apply changes
  delay(1000); // Wait for reset to complete and start advertising
}

void sendCommand(const String& command) {
  Serial.print(command);
  Serial.print("\r\n");
  delay(100); // Allow time for the module to process the command
}
