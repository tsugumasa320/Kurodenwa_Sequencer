void sq1ModeController() {
  sq1ModeLimitation();
  if (sq1ModeLimitationCheckFlg == true) {
//    receiveSq1Cv();
    sq1ModeTimingSwitch();
  }
}

void receiveSq1Cv()
{
  int sq1Cv = analogRead(sq1CvPin);

  if (0 <= sq1Cv && sq1Cv <= 341) {
    rotationTimes = 1;
  } else if (341 < sq1Cv && sq1Cv <= 682 ) {
    rotationTimes = 2;
  } else if (682 < sq1Cv && sq1Cv <= 1023 ) {
    rotationTimes = 3;
  }
}

void sq1ModeLimitation() {
  if (5 > rotationTimes && freq > 0 ) {
    if ( 100 >= rotationIntervalTime && rotationIntervalTime >= 10) {
      sq1ModeLimitationCheckFlg = true;
    } else {
      sq1ModeLimitationCheckFlg = false;
      lcdCrearPrint("Out of range");
      delay(100);
    }
  }
}

void sq1ModeTimingSwitch() {
  int sq1Value = digitalRead(13);
  if (sq1Value == HIGH)
  {
    for (; i < rotationTimes; i++) {  //sq1の1パルスでRotationtimes回ベルを鳴らす
      if (i > 0) {
        delay(rotationIntervalTime);
      }
      alternatelyRotation();
    }
    //      Serial.println("sq1Value==HIGH");
  } else if (sq1Value == LOW) {  //パルスがLOWに入ると打った回数リセット
    i = 0;
    //    Serial.println("sq1Value==LOW");
  }
}
