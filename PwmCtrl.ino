void pwmController() {

  pwmLimitation();
  if (pwmLimitationCheckFlg == true) {
    pwmTimingSwitch();
  }
}

void pwmLimitation() {
  if (50 > freq && freq > 0 )
  { //周波数0Hz以下と50Hz以上は出力しない
    pwmLimitationCheckFlg = true;
  } else {
    pwmLimitationCheckFlg = false;
    lcdCrearPrint("Out of range");
    lcdFreqPrint();
    delay(100);
  }
}

void pwmTimingSwitch()
{
  unsigned long currentMillis = millis();
  long interval_P = ONE_SECOND / freq * dutyCycle_P ; // ex:1000(ms)/16(Hz)*0.5  = 31.25(ms/Hz)
  long interval_N = ONE_SECOND / freq * ( 1 - dutyCycle_P );

  if (bellState == false )
  {
    if (currentMillis - previousMillis > interval_P)
    {
      previousMillis = currentMillis;
      normalRotation();
    }
  } else if (bellState == true )
  {
    if (currentMillis - previousMillis > interval_N)
    {
      previousMillis = currentMillis;
      reverseRotation();
    }
  }
}

void normalRotation()
{
  digitalWrite(BELL_P_PIN, HIGH);
  digitalWrite(BELL_N_PIN, LOW);
  bellState = true;
  Serial.println(bellState);
}

void reverseRotation()
{
  digitalWrite(BELL_P_PIN, LOW);
  digitalWrite(BELL_N_PIN, HIGH);
  bellState = false;
  Serial.println(bellState);
}

void alternatelyRotation()
{
  if (bellState == false )
  {
    normalRotation();
  } else if (bellState == true ) {
    reverseRotation();
  }
}

void stopRotation()
{
  digitalWrite(BELL_P_PIN, LOW);
  digitalWrite(BELL_N_PIN, LOW);
  Serial.println("-");
}
