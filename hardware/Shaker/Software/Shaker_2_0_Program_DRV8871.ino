// ESP32-S3 Motor Incubator Control with LCD & RGB LED

#include <Wire.h>
#include <LiquidCrystal_I2C.h>
#include <Adafruit_NeoPixel.h>

const int potPin = 4;    // Potentiometer to GPIO4 (ADC)
const int pwmPin = 18;   // DRV8871 IN1 (PWM)
const int dirPin = 19;   // DRV8871 IN2 (direction, set to LOW for forward)
const int avgSamples = 10;  // ADC averaging
const int MAX_RPM = 255;   // Max estimated RPM at full pot

// UPDATED: This is your new "Zero" point.
const int MIN_POT_THRESHOLD = 1264;  

Adafruit_NeoPixel rgbLed(1, 48, NEO_GRB + NEO_KHZ800);  // RGB LED on GPIO48 (1 pixel)
LiquidCrystal_I2C lcd(0x27, 20, 4);  // I2C address (change to 0x3F if needed)

unsigned long lastMessageTime = 0;  // For recurrent message

void setup() {
  Serial.begin(115200);  // USB debug (disconnect after)
  pinMode(potPin, INPUT);
  pinMode(pwmPin, OUTPUT);
  pinMode(dirPin, OUTPUT);
  
  digitalWrite(pwmPin, LOW);  // Ensure motor starts low/off
  digitalWrite(dirPin, LOW);  // Set direction to forward
  
  Wire.begin(21, 17);  // SDA 21, SCL 17
  
  // I2C Scanner for LCD detection
  Serial.println("Scanning I2C...");
  byte error, address;
  int nDevices = 0;
  for (address = 1; address < 127; address++) {
    Wire.beginTransmission(address);
    error = Wire.endTransmission();
    if (error == 0) {
      Serial.print("I2C device at 0x");
      if (address < 16) Serial.print("0");
      Serial.println(address, HEX);
      nDevices++;
    }
  }
  if (nDevices == 0) Serial.println("No I2C devices!");
  
  lcd.init();
  lcd.backlight();
  lcd.clear();
  
  randomSeed(esp_random()); // ESP32 true RNG
  
  // 5-second spiral animation
  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print("Spiral Animation");
  delay(600);
  spiral();
  
  // Print messages and simultaneous 5-second LED blink
  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print("Welcome!");
  lcd.setCursor(0, 1);
  lcd.print("Shaker 2.0");
  lcd.setCursor(0, 3);
  lcd.print("Starting!");
  
  rgbLed.begin();
  rgbLed.setBrightness(50);  // Low brightness
  unsigned long blinkStart = millis();
  int cycle = 0;
  while (millis() - blinkStart < 5000) {
    switch (cycle % 7) {
      case 0: rgbLed.setPixelColor(0, rgbLed.Color(255, 0, 0)); break;  // Red
      case 1: rgbLed.setPixelColor(0, rgbLed.Color(0, 255, 0)); break;  // Green
      case 2: rgbLed.setPixelColor(0, rgbLed.Color(0, 0, 255)); break;  // Blue
      case 3: rgbLed.setPixelColor(0, rgbLed.Color(255, 255, 0)); break;  // Yellow
      case 4: rgbLed.setPixelColor(0, rgbLed.Color(255, 0, 255)); break;  // Purple
      case 5: rgbLed.setPixelColor(0, rgbLed.Color(0, 255, 255)); break;  // Cyan
      case 6: rgbLed.setPixelColor(0, rgbLed.Color(255, 255, 255)); break;  // White
    }
    rgbLed.show();
    cycle++;
    delay(143);  // ~1s per full cycle
  }
  rgbLed.clear(); rgbLed.show();  // Turn off
  
  // Simple motor test
  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print("Testing the motor");
  Serial.println("Testing motor driver on GPIO18...");
  for (int i = 0; i < 5; i++) {
    analogWrite(pwmPin, 64);  // Low PWM (25% duty, slow speed)
    delay(500);
    analogWrite(pwmPin, 0);   // Off
    delay(500);
  }
  Serial.println("Test complete—check if motor/LED blinked.");
  lcd.setCursor(0, 1);
  lcd.print("Driver Test Done");
  delay(2000);
  lcd.clear();
}

void loop() {
  int potValue = 0;
  for (int i = 0; i < avgSamples; i++) {
    potValue += analogRead(potPin);
    delay(1);
  }
  potValue /= avgSamples;
  
  int speedPwm = 0;
  int approxRpm = 0;

  // --- CHANGED LOGIC START ---
  // If pot is 1264 or lower, force everything to 0.
  if (potValue <= MIN_POT_THRESHOLD) {
    speedPwm = 0;
    approxRpm = 0;
  } else {
    // Re-map the values. 
    // The "input" range is now 1264 to 4095.
    // The "output" range is 0 to 255 for PWM and RPM.
    speedPwm = map(potValue, MIN_POT_THRESHOLD, 4095, 0, 255);
    approxRpm = map(potValue, MIN_POT_THRESHOLD, 4095, 0, MAX_RPM);
  }
  // --- CHANGED LOGIC END ---

  // Calculate percentage based on PWM
  int speedPercent = map(speedPwm, 0, 255, 0, 100);
  
  analogWrite(pwmPin, speedPwm);  // Update PWM
  
  // Main display
  lcd.setCursor(0, 0);
  lcd.print("Speed: ");
  lcd.print(speedPercent);
  lcd.print("%    "); // Extra spaces to clear previous digits
  
  lcd.setCursor(0, 1);
  lcd.print("Approx RPM: ");
  lcd.print(approxRpm);
  lcd.print("    ");
  
  lcd.setCursor(0, 2);
  lcd.print("Pot Value: ");
  lcd.print(potValue);
  lcd.print("    ");
  
  // Recurrent "Shaking in progress " every 10s (with blink animation '*')
  if (millis() - lastMessageTime >= 10000) {
    lastMessageTime = millis();
    lcd.setCursor(0, 3);
    lcd.print("Shaking in progress *");
    delay(500);
    lcd.setCursor(20, 3);
    lcd.print(" ");  // Clear '*' (assuming 20 cols)
    delay(500);
    lcd.setCursor(0, 3);
    lcd.print("Shaking in progress  ");
  }
  
  // Serial debug
  Serial.print("Pot: ");
  Serial.print(potValue);
  Serial.print(" | PWM: ");
  Serial.print(speedPwm);
  Serial.print(" | Approx RPM: ");
  Serial.println(approxRpm);
  
  delay(100);  // Loop rate
}

// ANIMATION FUNCTION (5s limit, slowed down for better visibility)
void spiral() {
  lcd.clear();
  int top = 0, bottom = 3, left = 0, right = 19;
  char block = char(255);
  unsigned long start = millis();
  while (millis() - start < 5000 && top <= bottom && left <= right) {
    // Top row
    for (int i = left; i <= right; i++) {
      lcd.setCursor(i, top);
      lcd.print(block);
      delay(60);  // Increased delay for slower, more visible animation
    }
    top++;
    // Right column
    for (int i = top; i <= bottom; i++) {
      lcd.setCursor(right, i);
      lcd.print(block);
      delay(60);
    }
    right--;
    // Bottom row
    for (int i = right; i >= left; i--) {
      lcd.setCursor(i, bottom);
      lcd.print(block);
      delay(60);
    }
    bottom--;
    // Left column
    for (int i = bottom; i >= top; i--) {
      lcd.setCursor(left, i);
      lcd.print(block);
      delay(60);
    }
    left++;
  }
}