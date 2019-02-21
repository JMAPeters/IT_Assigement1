bool isMotion(){
  if (digitalRead(motionPin) == HIGH)
    return true;
  else
    return false;
}

int getDistance(){
  return sonar.ping_cm();
}

bool magnetON(){
  if (digitalRead(magnetPin) == HIGH)
    return true;
  else
    return false;
}

void getTemp(){
  TempSensor.requestTemperatures();
  temp = TempSensor.getTempCByIndex(0);
}

int getLightValue(){
  return analogRead(lightPin);
}

void spray(){
  //digitalWrite(motorPin, HIGH);
  //Timer tussen zetten
  //digitalWrite(motorPin, LOW);
  NoS--;
}

void buttonInput(){
  int buttonState = (analogRead(buttonsPin) * (5.0 / 1024.0));
  if (buttonState != lastButtonState){
    if (buttonState == 0 && Pressed == false){
      button1 = true;
      Pressed = true;
      timeWhenPressed = currentMillis;
    }
    if (buttonState == 2 && Pressed == false){
      button2 = true;
      Pressed = true;
      timeWhenPressed = currentMillis;
    }
    if (buttonState == 3 && Pressed == false){
      button3 = true;
      Pressed = true;
      timeWhenPressed = currentMillis;
    }
  }
  else{
    if (lastButtonState != 4){
      button1 = false;
      button2 = false;
      button3 = false;
      if (currentMillis - timeWhenPressed >= 50){
        Pressed = false;
      }
    }
  }
  lastButtonState = buttonState;
}
