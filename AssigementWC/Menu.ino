void Input(){
  buttonInput();
  switch (state){
    case main:{
      if (button1){
        state = settings;
      }
      if (button3){
        spray();
      }
      break;
    }
    case settings:{
      if (button1)
        {
          switch (menuPointer) {
            case 0:
              //spray delay
              state = delaySettings;
              break;
            case 1:
              // reset NoS
              NoS = 2400;
              state = main;
              break;
            default:
              break;
          }
        }
      //Scroll
      if (button2)
        menuPointer = ((menuPointer + menuSize + 1) % menuSize);
      //Back
      if (button3)
        state = main;
        //manual spray
      break;
    }
    case delaySettings:{
      if (button2){
        sprayDelay = ((sprayDelay - minSprayDelay + maxSprayDelay + 1000) % (maxSprayDelay)) + minSprayDelay;
      }
      if (button3){
        state = settings;
      }
      break;
    }
    default:
      break;
  }
}
    
void Screen(){
  lcd.clear();
  switch (state){
    case main:{
        lcd.setCursor(0,0);
        lcd.print("->");
        lcd.print("Settings");
        lcd.setCursor(0,1);
        lcd.print("NoS:");
        lcd.print(NoS);
        lcd.setCursor(9,1);
        lcd.print(temp);
        lcd.print("'C");
       break;
    }
    case settings: {
        lcd.setCursor(0,0);
        lcd.print("->");
        lcd.print(menuItems[menuPointer]);
        lcd.setCursor(0,1);
        lcd.print("  ");
        lcd.print(menuItems[((menuPointer + menuSize + 1) % menuSize)]);
      break;
    }
    case delaySettings: {
        lcd.setCursor(0,0);
        lcd.print("Delay: ");
        lcd.print(sprayDelay / 1000);
        lcd.print(" sec");
       break;
    }
  }
}
