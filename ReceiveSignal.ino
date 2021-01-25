void receiveSq1Mode()
{
  int sq1Value = digitalRead(13);

  if (sq1Value == HIGH)
  {
    for (; i < RotationTimes; i++) {  //sq1の1パルスでRotationtimes回ベルを鳴らす
      if (i > 0) {
        delay(RotationIntervalTime);
      }
      alternatelyRotation();
    }
    //      Serial.println("sq1Value==HIGH");
  } else if (sq1Value == LOW) {  //パルスがLOWに入ると打った回数リセット
    i = 0;
    //    Serial.println("sq1Value==LOW");
  }
}

void receiveKeypadActiveMode() {

  localKey = keypad.getKey();
  if (localKey != SAMPLE_WAIT && localKey != OLD_localKey)
  {
    // 「右」が押されたときの処理
    if (localKey == RightKey) {
      lcdCrearPrint("@Up(10Hz)");
      freq = freq + 10;
      lcdFreqPrint();
    }
    // 「左」が押されたときの処理
    if (localKey == LeftKey) {
      lcdCrearPrint("@Down(-10Hz)");
      freq = freq - 10;
      lcdFreqPrint();
    }
    // 「上」が押されたときの処理
    if (localKey == UpKey) {
      lcdCrearPrint("@Up(1Hz)");
      freq++;
      lcdFreqPrint();
    }
    // 「下」が押されたときの処理
    if (localKey == DownKey) {
      lcdCrearPrint("@Down(-1Hz)");
      freq--;
      lcdFreqPrint();
    }
    // 「SELECT」が押されたときの処理
    if (localKey == SelectKey)
    {
      lcdCrearPrint("PassiveMode(sq1)");
      modeSwitch = 1;
    }
    OLD_localKey = localKey;
  }
}

void receiveKeypadPassiveMode() {
  localKey = keypad.getKey();
  if (localKey != SAMPLE_WAIT && localKey != OLD_localKey)
  {
    // 「右」が押されたときの処理
    if (localKey == RightKey) {
      lcdCrearPrint("@RotIntTime+10");
      RotationIntervalTime = RotationIntervalTime + 10;
      lcdRotationIntervalTimePrint();
    }
    // 「左」が押されたときの処理
    if (localKey == LeftKey) {
      lcdCrearPrint("@RotIntTime-10");
      RotationIntervalTime = RotationIntervalTime - 10;
      lcdRotationIntervalTimePrint();
    }
    // 「上」が押されたときの処理
    if (localKey == UpKey) {
      lcdCrearPrint("@RotationTimes++");
      RotationTimes++;
      lcdRotationTimesPrint();
    }
    // 「下」が押されたときの処理
    if (localKey == DownKey) {
      lcdCrearPrint("@RotationTimes--");
      RotationTimes--;
      lcdRotationTimesPrint();
    }
    // 「SELECT」が押されたときの処理
    if (localKey == SelectKey)
    {
      lcdCrearPrint("ManualMode");
      modeSwitch = 2;
    }
    OLD_localKey = localKey;
  }
}

void receiveKeypadManualMode() {
  localKey = keypad.getKey();
  if (localKey != SAMPLE_WAIT && localKey != OLD_localKey)
  {
    // 「右」が押されたときの処理
    if (localKey == RightKey) {
      lcdCrearPrint("@reverseRotation");
      reverseRotation();
    }
    // 「左」が押されたときの処理
    if (localKey == LeftKey) {
      lcdCrearPrint("@normalRotation");
      normalRotation();
    }
    // 「上」が押されたときの処理
    if (localKey == UpKey) {
      lcdCrearPrint("@alternatelyRotation");
      alternatelyRotation();
    }
    // 「下」が押されたときの処理
    if (localKey == DownKey) {
      lcdCrearPrint("@stopRotation");
      stopRotation();
    }
    // 「SELECT」が押されたときの処理
    if (localKey == SelectKey)
    {
      lcdCrearPrint("ActiveMode");
      modeSwitch = 0;
      lcdFreqPrint();
    }
    OLD_localKey = localKey;
  }
}
