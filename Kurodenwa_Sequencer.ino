#include <LiquidCrystal.h>
#include <DFR_Key_ROBO.h>  // キーパッドライブラリ（DFRobotキーパッドシールド用）

//--------------------
// キー入力の設定

DFR_Key keypad;

// キー入力用変数
int localKey = 0;
int OLD_localKey = 0;

//--------------------
// キー入力値に対する設定

const int NoneKey   = 0;
const int SelectKey = 1;
const int LeftKey   = 2;
const int UpKey     = 3;
const int DownKey   = 4;
const int RightKey  = 5;

//--------------------
// LCDのピン番号設定

//Pin assignments for SainSmart LCD Keypad Shield
LiquidCrystal lcd(8, 9, 4, 5, 6, 7);

//--------------------
// 出力用ピン番号設定

const int BELL_P_PIN = 2;
const int BELL_N_PIN = 3;

//--------------------
// PWM設定

int modeSwitch = 1;
int freq = 16;
float dutyCycle_P = 0.5; //dutyCycle_N = (1-DutyCycle_P)で計算
long previousMillis = 0;
bool bellState = true;
bool pwmLimitationCheckFlg = true;

//SQ1_MODE設定
int RotationTimes = 1;
int i = 0;
int RotationIntervalTime = 10;


const long ONE_SECOND = 1000;

void setup()
{
  pinMode(A0, INPUT);
  pinMode(13, INPUT_PULLUP);
  pinMode(BELL_N_PIN, OUTPUT);
  pinMode(BELL_P_PIN, OUTPUT);

  Serial.begin(9600);
  lcd.begin(16, 2);
  lcd.clear();
  lcd.print("Kurodenwa_Hack");
}

void loop()
{
  int buttonValue = analogRead(A0); //LCDKeypadのボタン読み込み

  if (modeSwitch == 0) {
    receiveKeypadActiveMode();
    pwmController();
  } else if (modeSwitch == 1) {
    receiveKeypadPassiveMode();
    receiveSq1Mode();
  } else if (modeSwitch == 2) {
    receiveKeypadManualMode();
  }
}
