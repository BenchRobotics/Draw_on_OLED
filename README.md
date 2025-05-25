
# WiFi OLED UDP Display

This project allows an ESP32 microcontroller to connect to a WiFi network and receive UDP packets to control an OLED display (SSD1306). The received packets contain pixel coordinates and their state (ON/OFF), enabling remote manipulation of the display.

## Requirements

### Libraries
Ensure you have the following libraries installed in your Arduino IDE:
- [WiFi](https://www.arduino.cc/en/Reference/WiFi)
- [WiFiUdp](https://www.arduino.cc/en/Reference/WiFiUDP)
- [Adafruit GFX Library](https://github.com/adafruit/Adafruit-GFX-Library)
- [Adafruit SSD1306 Library](https://github.com/adafruit/Adafruit_SSD1306)

To install them:
1. Open Arduino IDE.
2. Go to `Sketch > Include Library > Manage Libraries`.
3. Search for each library and click `Install`.

## Hardware Wiring

Connect the SSD1306 OLED display to the ESP32 using I2C:

| OLED Pin | ESP32 Pin |
|----------|----------|
| VCC      | 3.3V     |
| GND      | GND      |
| SCL      | GPIO22   |
| SDA      | GPIO21   |

## Uploading the Program

1. Open the Arduino IDE.
2. Select `ESP32` as the board (`Tools > Board`).
3. Choose the appropriate COM port (`Tools > Port`).
4. Copy the provided code into the Arduino sketch.
5. Click the **Upload** button.

## Connecting to WiFi & Getting ESP32 IP Address

Once the program is uploaded:

1. Open the **Serial Monitor** (`Tools > Serial Monitor`).
2. Set the baud rate to **115200**.
3. The ESP32 will attempt to connect to the WiFi network.
4. Once connected, it will print the assigned **IP Address**.
5. Use this IP for sending UDP packets to control the OLED display.

## Usage

Send UDP packets to the ESP32 in the following format: x,y,state

- `x, y` → Pixel coordinates (must be within 128x64).
- `state` → `1` for ON, `0` for OFF.

Example UDP message: 10,20,1

This will turn on the pixel at (10,20).

## Notes

- Ensure the OLED display supports **I2C communication**.
- The default UDP port is `12345`; change it in the code if necessary.
- Debugging messages can be viewed in the **Serial Monitor**.

---



