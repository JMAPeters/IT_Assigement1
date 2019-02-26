void System3(){  
  lcd.clear();
  lcd.setCursor(0,0);
  lcd.print(minDist);
  lcd.setCursor(5,0);
  lcd.print(distToDoor);
if (((isMotion())|| distance < distToDoor - 10)&& magnetON()){ //of distance is kleiner dan deur
  state = inUseUnknow;
}
else{
  if (magnetON()){
    state = outOfUse;
    distToDoor = distance;
    minDist = distToDoor; //aanpassen naar max door distance
    lcd.setCursor(5,1);
    lcd.print("outOfUse");
  }
  else {
    state = cleaning;
    lcd.setCursor(5,1);
    lcd.print("cleaning");
  }
}

if (state != outOfUse){//wanneer er iemand is check input en screen
    if (currentMillis - previousMillis >= interval){
    previousMillis = currentMillis;
    minDist = min(minDist, getDistance());
  }
}

if (((minDist < distToDoor - 20) && minDist > 50) && state != outOfUse && state != cleaning){
  state = inUse1;
  lcd.setCursor(5,1);
  lcd.print("standing");
}

if (minDist < 50 && state != outOfUse && state != cleaning){
  state = inUse1;
  lcd.setCursor(5,1);
  lcd.print("sitting");
}
};
