
# Draw on OLED WiFi

You can draw on the 1.3" or 0.9" OLED display like an IPAD. It is very annoying making the UI for OLED, so I made a small ESP32 program and an Android app that will allow me to draw the UI on the OLED screen. These are your normal OLEDs used with Arduino and ESP32.

ESP32 microcontroller to connect to a WiFi network and receive UDP packets to control an OLED display (SSD1306 or SH1107). The received packets contain pixel coordinates and their state (ON/OFF), enabling remote manipulation of the display. 

[Full tutorial at Bench Robotics](https://benchrobotics.com/arduino/drawing-on-esp32-oled-screen/)

![Project Demo](https://github.com/BenchRobotics/Draw_on_OLED/blob/main/DSC00402.JPG)

## There are two programs
### 1. Oled_Draw_Wifi_SSD1306
Use this for a 0.9" 128X64 OLED display, most common.
![0.9" SSD1306 OLED](https://github.com/BenchRobotics/Draw_on_OLED/blob/main/SSD1306-OLED-Display-Pinout.jpg)

### 2. Oled_Draw_Wifi_1_3_inch
Use this if you have a 1.3" SH1107 display; it is bigger. Not so common to get.
![1.3" SH1107 OLED](https://github.com/BenchRobotics/Draw_on_OLED/blob/main/1-3_inch_SH1107.png)

## Requirements

### Libraries
Ensure you have the following libraries installed in your Arduino IDE:
- [WiFi](https://www.arduino.cc/en/Reference/WiFi)
- [WiFiUdp](https://www.arduino.cc/en/Reference/WiFiUDP)
- [Adafruit GFX Library](https://github.com/adafruit/Adafruit-GFX-Library)
- [Adafruit SSD1306 Library](https://github.com/adafruit/Adafruit_SSD1306)
- [Adafruit SH110X Library](https://github.com/adafruit/Adafruit_SH110X)

To install them:
1. Open Arduino IDE.
2. Go to `Sketch > Include Library > Manage Libraries`.
3. Search for each library and click `Install`.

## Hardware Wiring

![Circuit Diagram](https://github.com/BenchRobotics/Draw_on_OLED/blob/main/oled_circuit.jpg)


Connect the SSD1306 OLED or the SH1107 OLED display to the ESP32 using I2C:

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



