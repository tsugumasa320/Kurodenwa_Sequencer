//SQ1_MODE関連の処理

void sq1ModeController() {
  sq1ModeLimitation();
  if (sq1ModeLimitationCheckFlg == true) {
    sq1ModeTimingSwitch();
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
    receiveSq1Cv();
    for (; rotatedTimes < rotationTimes; rotatedTimes++) {  //sq1の1パルスでRotationtimes回ベルを鳴らす
      if (rotatedTimes > 0) {
        delay(rotationIntervalTime);
      }
      alternatelyRotation();
    }
    //      Serial.println("sq1Value==HIGH");
  } else if (sq1Value == LOW) {  //パルスがLOWに入ると打った回数リセット
    rotatedTimes = 0;
    //    Serial.println("sq1Value==LOW");
  }
}

void receiveSq1Cv()
{ //CV値の値によってGATE一回あたりの打鍵回数を変える
  int sq1Cv = analogRead(SQ1_CV_PIN);
  //  Serial.println(sq1Cv);

  if (0 <= sq1Cv && sq1Cv <= 341) {
    rotationTimes = 1;
  } else if (341 < sq1Cv && sq1Cv <= 682 ) {
    rotationTimes = 2;
  } else if (682 < sq1Cv && sq1Cv <= 1023 ) {
    rotationTimes = 3;
  }
}
