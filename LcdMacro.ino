void lcdCrearPrint(String msg) 
{  
  Serial.println(msg);
  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print(msg);
}

void lcdFreqPrint() 
{
  lcd.setCursor(0, 1);
  lcd.print("freq:");
  lcd.print(freq);
  lcd.print(" State:");
  lcd.print(modeSwitch);
}

void lcdRotationTimesPrint() 
{
  lcd.setCursor(0, 1);
  lcd.print("RotTimes:");
  lcd.print(RotationTimes);
}

void lcdRotationIntervalTimePrint() 
{
  lcd.setCursor(0, 1);
  lcd.print("RotIntTime:");
  lcd.print(RotationIntervalTime);
}
