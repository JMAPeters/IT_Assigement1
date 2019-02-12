//Libraries 
  //LCD
#include <LiquidCrystal.h>

//Variables
  //LCD
const int rs = 7, en = 6, d4 = 5, d5 = 4, d6 = 3, d7 = 2;
LiquidCrystal lcd(rs, en, d4, d5, d6, d7);

  //Distance Sensor
const int trigPin = 8;
const int echoPin = 9;
long duration;
int distance;

  //Motion Sensor

  //Light Sensor

  //Temperature Sensor

  // Magnetic Sensor

  //Button 1

  //Button 2

  //Button 3

  //Led Green

  //Led RGB

  //Motor AirWick


void setup() {
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
 
  lcd.begin(16, 2);
  Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:

}
