#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>
#include <DHT.h>
#include <SoftwareSerial.h>

#define SCREEN_WIDTH 128
#define SCREEN_HEIGHT 64
#define LED_PIN 8
// OLED display declaration
Adafruit_SSD1306 display(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, -1);

// DHT11 Sensor Pin and Type
#define DHTPIN 7          
#define DHTTYPE DHT11      

DHT dht(DHTPIN, DHTTYPE);  

// HC-05 Bluetooth pins (using SoftwareSerial)
#define RX_PIN 10
#define TX_PIN 11
SoftwareSerial BTSerial(RX_PIN, TX_PIN);  

void setup() {
  // Start serial communication for debugging and Bluetooth communication
  Serial.begin(38400);
  BTSerial.begin(38400); // Default baud rate for HC-05
  pinMode(LED_PIN, OUTPUT);
  digitalWrite(LED_PIN, LOW);
  // Initialize OLED display
  if(!display.begin(SSD1306_SWITCHCAPVCC, 0x3C)) {
    Serial.println(F("SSD1306 allocation failed"));
    for(;;);
  }
  delay(2000);
  display.clearDisplay();

  // Initialize the DHT11 sensor
  dht.begin();

  // Display static message on OLED
  display.setTextSize(1);
  display.setTextColor(WHITE);
  display.setCursor(0, 10);
  display.println("Initializing...");
  display.display();
}

void loop() {
  // Read humidity and temperature from DHT11
  float humidity = dht.readHumidity();
  float temperature = dht.readTemperature();

  // Check if any reading failed
  if (isnan(humidity) || isnan(temperature)) {
    Serial.println(F("Failed to read from DHT sensor"));
    return;
  }

  // Print readings to Serial Monitor for debugging
  Serial.print(F("Humidity: "));
  Serial.print(humidity);
  Serial.print(F("%\t"));
  Serial.print(F("Temperature: "));
  Serial.print(temperature);
  Serial.println(F("C"));

  // Display the sensor readings on the OLED screen
  display.clearDisplay();
  display.setCursor(0, 0);
  display.print("Temp: ");
  display.print(temperature);
  display.println(" C");
  display.print("Humidity: ");
  display.print(humidity);
  display.println(" %");
  display.display();

  // Send sensor data over Bluetooth (HC-05)
  BTSerial.print("Temp: ");
  BTSerial.print(temperature);
  BTSerial.print(" C\t");
  BTSerial.print("Humidity: ");
  BTSerial.print(humidity);
  BTSerial.println(" %");
 
  // Turn the LED on (indicates data is being sent)
  digitalWrite(LED_PIN, HIGH);

  // Wait for 1 second (simulating a delay between data transmissions)
  delay(2000);

  // Turn the LED off (indicates no data is being sent)
  digitalWrite(LED_PIN, LOW);
  // Wait for 2 seconds before taking another reading
  delay(2500);
}