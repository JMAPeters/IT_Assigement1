void System(){  
if (((isMotion())|| distance < distToDoor - 10)&& magnetON()){ //of distance is kleiner dan deur
  state = inUseUnknow;
  lcd.display();
}
else{
  if (magnetON()){
    if (state != outOfUse){
      if (state == inUse1){
        spray();
      }
      if (state == inUse2){
        spray();
        spray();
      }
    }
    state = outOfUse;
    timerSet = false;
    distToDoor = distance;
    minDist = distToDoor;
    lcd.noDisplay();
  }
  else {
    state = cleaning;
    lcd.display();
  }
}

if (state != outOfUse){
  Input();
  if (currentMillis - previousMillis >= interval){
    previousMillis = currentMillis;
    Screen();
    minDist = min(minDist, getDistance());
  }
}

if (((minDist < distToDoor - 20) && minDist > 50) && state != outOfUse && state != cleaning){
  state = inUse1;
}

if (minDist < 50 && state != outOfUse && state != cleaning){
  if (!timerSet){
    timerSet = true;
    timeWhenSomebodySitdown = currentMillis;
    state = inUse1;
  }
  if (currentMillis - timeWhenSomebodySitdown > 15000){
    state = inUse2;
  }
}
};
