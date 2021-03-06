/*Keypadの処理をまとめ
  
全部で3モード

  1.ActiveMode 任意の周波数を出すことができる。テスト用
  2.PassiveMode SQ1からのCVとGATEを受け取って打鍵する.デフォはこれ
  3.ManualMode 正転・反転・交互等の動作テスト用
  
  ※正転(normalRotate)はBELL_P_PINがHIGH,BELL_N_PINがLOWのこと、
  反転(Reverse)は逆.モータードライバを用いてるのでこの変数名にした.
  もっと良い変数名があれば変えたい
 
  */

void receiveKeypadActiveMode() {

  int buttonValue = analogRead(A0); //LCDKeypadのボタン読み込み
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

  int buttonValue = analogRead(A0); //LCDKeypadのボタン読み込み
  localKey = keypad.getKey();
  if (localKey != SAMPLE_WAIT && localKey != OLD_localKey)
  {
    // 「右」が押されたときの処理
    if (localKey == RightKey) {

      lcdCrearPrint("@altRotate");
      alternatelyRotation();

      //      lcdCrearPrint("@RotationTimes++");
      //      rotationTimes++;
      //      lcdRotationTimesPrint();

    }
    // 「左」が押されたときの処理
    if (localKey == LeftKey) {

      lcdCrearPrint("@rinrin");
      freq = 16;
      pwmController(1000);
      delay(2000);
      pwmController(1000);
      delay(2000);

      //      lcdCrearPrint("@RotationTimes--");
      //      rotationTimes--;
      //      lcdRotationTimesPrint();

    }
    // 「上」が押されたときの処理
    if (localKey == UpKey) {
      lcdCrearPrint("@RotIntTime+10");
      rotationIntervalTime = rotationIntervalTime + 10;
      lcdRotationIntervalTimePrint();

    }
    // 「下」が押されたときの処理
    if (localKey == DownKey) {

      lcdCrearPrint("@RotIntTime-10");
      rotationIntervalTime = rotationIntervalTime - 10;
      lcdRotationIntervalTimePrint();

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

  int buttonValue = analogRead(A0); //LCDKeypadのボタン読み込み
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
      lcdCrearPrint("@rinrin");
      freq = 16;
      pwmController(1000);
      delay(2000);
      pwmController(1000);
      delay(2000);

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
