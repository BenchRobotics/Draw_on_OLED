#include <WiFi.h>                    // Include WiFi library for ESP32
#include <WiFiUdp.h>                // Include UDP support library
#include <Adafruit_GFX.h>           // Core graphics library
#include <Adafruit_SH110X.h>        // OLED display library for SH1107

// OLED display configuration
#define SCREEN_WIDTH 128            // OLED screen width in pixels
#define SCREEN_HEIGHT 64            // OLED screen height in pixels
#define OLED_RESET -1               // No reset pin used

// WiFi credentials
const char* ssid = "ground";        // Your WiFi network name
const char* password = "12345678";  // Your WiFi password

// UDP configuration
WiFiUDP udp;                        // Create a UDP object
const int udpPort = 12345;          // Port to listen for incoming UDP packets

// OLED display object: SH1107 display with 64x128 resolution
Adafruit_SH1107 display = Adafruit_SH1107(64, 128, &Wire);  // Width and height reversed due to rotation

void setup() {
  Serial.begin(115200);             // Start serial communication for debugging

  // Initialize OLED display
  display.begin(0x3C);              // Start the display at I2C address 0x3C
  display.clearDisplay();           // Clear the screen buffer
  display.display();                // Push buffer to screen
  display.setRotation(1);           // Rotate display so (0,0) is at top-left

  // Connect to WiFi
  WiFi.begin(ssid, password);       // Start WiFi connection
  Serial.println("Connecting to WiFi...");
  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");              // Print dots while waiting
  }
  Serial.println("\nConnected to WiFi");
  Serial.print("IP Address: ");
  Serial.println(WiFi.localIP());   // Print local IP once connected

  // Start listening for UDP packets
  udp.begin(udpPort);
  Serial.printf("Listening on UDP port %d\n", udpPort);
}

void loop() {
  // Check if there's an incoming UDP packet
  int packetSize = udp.parsePacket();
  if (packetSize) {
    char incomingPacket[255];       // Buffer to hold the incoming packet
    int len = udp.read(incomingPacket, sizeof(incomingPacket) - 1); // Read packet
    if (len > 0) {
      incomingPacket[len] = '\0';   // Null-terminate the string
    }

    // Parse the incoming data (expected format: "x,y,state")
    int x, y, state;
    sscanf(incomingPacket, "%d,%d,%d", &x, &y, &state); // Extract integers
    Serial.println(incomingPacket); // Print the raw packet

    // Draw pixel on OLED if it's within screen bounds
    if (x >= 0 && x < SCREEN_WIDTH && y >= 0 && y < SCREEN_HEIGHT) {
      display.drawPixel(x, y, state ? SH110X_WHITE : SH110X_BLACK); // Set or clear pixel
      display.display();         // Update the display
    }
  }
}
