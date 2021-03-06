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
// 入力用ピン番号設定

const int SQ1_GATE_PIN = 13;
const int SQ1_CV_PIN = A1;
const int LCD_KEYPAD_PIN = A0;

// 出力用ピン番号設定

const int BELL_P_PIN = 2;
const int BELL_N_PIN = 3;

//--------------------
// 起動時のMode設定

int modeSwitch = 1;

//--------------------
// PWM設定

int freq = 16;
float dutyCycle_P = 0.5; //dutyCycle_N = (1-DutyCycle_P)で計算
long previousMillis = 0;
bool bellState = true;
bool pwmLimitationCheckFlg = true;

//--------------------
//SQ1_MODE設定

int rotatedTimes = 0;
int rotationTimes = 1;
int rotationIntervalTime = 30;
bool sq1ModeLimitationCheckFlg = true;

const long ONE_SECOND = 1000;

//--------------------

void setup()
{
  
  //ピン設定
  pinMode(LCD_KEYPAD_PIN, INPUT);
  pinMode(SQ1_CV_PIN, INPUT); //Todo:PULLUPさせる？
  pinMode(SQ1_GATE_PIN, INPUT_PULLUP);
  pinMode(BELL_N_PIN, OUTPUT);
  pinMode(BELL_P_PIN, OUTPUT);

  Serial.begin(9600);
  lcd.begin(16, 2);
  lcd.clear();
  lcd.print("Kurodenwa_Hack");
}

void loop()
{

  if (modeSwitch == 0) {
    receiveKeypadActiveMode();
    pwmController(0); //引数はミリ秒駆動.0でずっとActive
  } else if (modeSwitch == 1) {
    receiveKeypadPassiveMode();
    sq1ModeController();
  } else if (modeSwitch == 2) {
    receiveKeypadManualMode();
  }
}
