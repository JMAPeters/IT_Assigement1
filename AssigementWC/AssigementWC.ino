//Libraries 
#include <LiquidCrystal.h>
#include <NewPing.h>
#include <OneWire.h>
#include <DallasTemperature.h>

//Variables
  //LCD
const int rs = 7, en = 6, d4 = 5, d5 = 4, d6 = 3, d7 = 2;
LiquidCrystal lcd(rs, en, d4, d5, d6, d7);

  //Distance Sensor
#define trigPin 9
#define echoPin 8
#define maxDis 200
NewPing sonar(trigPin, echoPin, maxDis);

  //Motion Sensor
int motionPin = 10;
int motionState = LOW;
int motionVal = LOW;

  //Light Sensor
#define lightPin A1

  //Temperature Sensor
OneWire oneWire(A2);
DallasTemperature TempSensor(&oneWire);
float temp = 0;
int tempInterval = 2000;

  // Magnetic Sensor
#define magnetPin 11

  //Buttons
#define buttonsPin A0
int lastButtonState = 4;
unsigned long lastDebounceTime = 0;
unsigned long debounceDelay = 100;
unsigned long timeWhenPressed = 0;
bool button1 = false;
bool button2 = false;
bool button3 = false;
bool Pressed = false;

  //Motor AirWick
#define motorPin 12

  //Led Green
#define LedGreen 13

  //Led RGB
#define LedRGB_R A3
#define LedRGB_G A4
#define LedRGB_B A5

  //Menu
enum State { main, settings, delaySettings};
    State state = main;
    byte menuPointer = 0;
    byte menuSize = 4;
    const char* menuItems[4]={
      "Spraying delay",
      "Reset shots",
      "item 3",
      "item 4"
    };
    int NoS = 2400;
    int minSprayDelay = 2000;
    int maxSprayDelay = 15000 - minSprayDelay + 1000;
    int sprayDelay = minSprayDelay;

  //Time
unsigned long currentMillis = 0;
unsigned long previousMillis = 0;
unsigned long previousMillis2 = 0;
long interval = 500;

void setup() {
  pinMode(motionPin, INPUT);
  pinMode(magnetPin, INPUT);
  pinMode(motorPin, OUTPUT);
  pinMode(LedGreen, OUTPUT);
  pinMode(LedRGB_R, OUTPUT);
  pinMode(LedRGB_G, OUTPUT);
  pinMode(LedRGB_B, OUTPUT);
  
  lcd.begin(16, 2);
  TempSensor.begin();
}

void loop() {
  currentMillis = millis();
  
  Input();
  
  if (currentMillis - previousMillis >= interval){
    previousMillis = currentMillis;
    Screen();
  }

  if (currentMillis - previousMillis2 >= tempInterval){
    previousMillis2 = currentMillis;
    getTemp();
  }
  
  //is er iemand?
  //ja
  //meet wat die persoon doet & print screen
  //nee
  //doe niets
}
