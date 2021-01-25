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
