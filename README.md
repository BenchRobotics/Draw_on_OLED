Before uploading the code, make sure you have:

Arduino IDE installed (Download here)

ESP32 board support installed in Arduino IDE:

Go to File > Preferences

Add this URL to Additional Board URLs:
https://raw.githubusercontent.com/espressif/arduino-esp32/gh-pages/package_esp32_index.json

Open Tools > Board > Board Manager, search for ESP32, and install it

📚 Install Required Libraries
Go to Sketch > Include Library > Manage Libraries, and install:

Adafruit GFX

Adafruit SH110X

Search for each by name and click Install.

🔌 Wiring (I2C)
Connect your SH1107 OLED to the ESP32:

OLED Pin	ESP32 Pin
VCC	3.3V
GND	GND
SCL	GPIO 22
SDA	GPIO 21

⬆️ Uploading the Code
Open the .ino file in Arduino IDE

Select your board:
Tools > Board > ESP32 Dev Module

Select the correct COM port under Tools > Port

Click Upload (the ➜ button)

Once uploaded, open the Serial Monitor to see WiFi connection status and IP address.
