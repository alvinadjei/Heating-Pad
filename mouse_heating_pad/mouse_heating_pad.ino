#include <Wire.h> 
#include <LiquidCrystal_I2C.h>

LiquidCrystal_I2C lcd(0x27,16,2);  // set the LCD address to 0x27 for a 16 chars and 2 line display

const int heatPin = 11; // pin that controls the heating pad
const int tempPin = A0; // pin that reads temp sensor value
const int potPin = A1; // pin that reads potentiometer value
const int sensorVoltage = 5.0; // mV; if temp sensor is plugged into the 5.5V pin
// const int sensorVoltage = 3.3; // mV; if temp sensor is plugged into the 3.3V pin

// Bounds between which to keep mouse body temp (36.6 +/- 0.5)
const float lowerBound = 36.1;
const float upperBound = 37.1;

int reading; // temp sensor --> ADC reading (0-1023)
float voltage; // convert tempReading to millivolts
float degreesC; // convert mv to degrees C
float degreesF; // convert mv to degrees F

int pot; // potentiometer pin reading

int heat; // energy sent to heating pad

void setup() {
  heat = 155; // initial signal to heating pad
  
  lcd.init();                      // initialize the lcd 
  lcd.backlight();

  Serial.begin(9600);
}

void loop() {
  reading = analogRead(tempPin); // read analog pin
  voltage = (reading / 1023.0) * sensorVoltage * 1000; // convert to millivolts
  degreesC = (voltage - 500) / 10; // convert to degrees C
  degreesF = (degreesC * 9/5) + 32; // convert to degrees F
  
  // if the pad is too cold
  if (degreesC < lowerBound) {
    heat += 10; // increase heat slightly
  }

  // Don't increase heat past 255
  if (heat > 255) {
    heat = 255;
  }
  
  // if the pad is too hot
  else if (degreesC > upperBound) {
    heat -= 10; //
  }

  // Don't decrease heat past 0
  if (heat < 0) {
    heat = 0;
  }
  
  // Failsafe:
  if ((degreesC < 20 && heat < 100) || (degreesC > 40.0 && heat > 200)) { // Mouse is way too cold or hot
    heat = 155;
  }
  
  // Normalize 10-bit potentiometer reading to be between 0 and 1
  pot = analogRead(potPin);
  float pot_norm = pot / 1023.0;

  // Control actualHeat value with potentiometer (failsafe)
  float actualHeat = heat * pot_norm;

  analogWrite(heatPin, actualHeat); // Send appropriate heat level to heating pad

  // Convert actualHeat (0-255) to percentage
  int heatDisplay = map(actualHeat, 0, 255, 0, 100);

  // Print to LCD display
  lcd.setCursor(0, 0);
  lcd.print("Heat input: ");
  lcd.print(heatDisplay);
  lcd.print("%");
  lcd.setCursor(0, 1);
  lcd.print("Temp: ");
  lcd.print(degreesC);
  lcd.print(" C");

  // Print to serial output
  
  Serial.print("Heat: ");
  Serial.print(heatDisplay);
  Serial.print("%");
  Serial.print("\n");

  Serial.print("ADC Reading: ");
  Serial.print(reading);
  Serial.print("; Millivolts: ");
  Serial.print(voltage);
  Serial.print("mV; Degrees C: ");
  Serial.print(degreesC);
  Serial.print("; Degrees F: ");
  Serial.print(degreesF);
  Serial.print("\n");

  delay(1000);
  lcd.clear();
}