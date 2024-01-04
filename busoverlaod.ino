#define IR_SENSOR_PIN 2 
#include <Wire.h>
#include <LiquidCrystal_I2C.h>
#include <NewPing.h>
//code modified by Sujnan D Devadiga @NMAMIT

const int buzzerPin = 4;
const int redLedPin = 7;
const int greenLedPin = 8;

const int threshold = 10;

int passengerCount = 0;

LiquidCrystal_I2C lcd(0x27, 16, 2);

void setup() {
  Serial.begin(9600);
  lcd.begin(16, 2);
  lcd.backlight(); 
  pinMode(IR_SENSOR_PIN, INPUT); 
  pinMode(buzzerPin, OUTPUT);
  pinMode(redLedPin, OUTPUT);
  pinMode(greenLedPin, OUTPUT);

  digitalWrite(redLedPin, LOW);
  digitalWrite(greenLedPin, HIGH);

  while (true) {
    busOverloadAnimation();
    runCycle();
  }
}

void runCycle() {
  passengerCount = 0;
  lcd.clear();
  delay(1000);

  bool objectDetected = false;

  while (true) {
    int irSensorValue = digitalRead(IR_SENSOR_PIN);

    if (irSensorValue == HIGH) {
      if (!objectDetected) {
        passengerCount++;
        objectDetected = true;
        digitalWrite(redLedPin, LOW);
        digitalWrite(greenLedPin, HIGH);
        updateLCD();

        if (passengerCount == threshold) {
          activateAlert();
          break;
        }
      }

      // Wait until the object is no longer detected
      while (digitalRead(IR_SENSOR_PIN) == HIGH) {
        delay(100);
      }
    } else {
      digitalWrite(redLedPin, HIGH);
      digitalWrite(greenLedPin, LOW);
      objectDetected = false;
      updateLCD();
    }

    delay(100);
  }
}

void busOverloadAnimation() {
  lcd.clear();

  String message = "Bus Overload Detection System";
  int messageLength = message.length();

  for (int i = 0; i < 16; i++) {
    lcd.clear();
    lcd.setCursor(0, 0);

    if (i < messageLength) {
      lcd.print(message.substring(i) + message.substring(0, i));
    }

    delay(200);
  }
  lcd.clear();
}

void activateAlert() {
  digitalWrite(buzzerPin, HIGH);
  digitalWrite(redLedPin, HIGH);
  digitalWrite(greenLedPin, LOW);
  updateLCD();
  lcd.setCursor(0, 1);
  lcd.print("Bus Full!!");
  Serial.println("Bus Full Alert! Buzzer Activated. Red LED On. Green LED Off. Passenger Count Reset.");
  delay(6000); 
  digitalWrite(buzzerPin, LOW);
  digitalWrite(greenLedPin, HIGH);
  updateLCD();
  Serial.println("Bus Full Alert Ended. Red LED Off. Green LED On. Passenger Count Reset.");
}

void updateLCD() {
  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print("Passenger Count:");
  lcd.setCursor(0, 1);
  lcd.print(passengerCount);

  Serial.print("Passenger Count: ");
  Serial.println(passengerCount);
}
