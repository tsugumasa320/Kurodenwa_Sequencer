# 黒電話シーケンサー

黒電話シーケンサーは、黒電話のベルを  
ステップシーケンサーで鳴らせるように改造した楽器です。  
繰り返されるベルの音色と細かく変化するリズムパターンが特徴です。  
また、カーボンマイクからオーディオ出力することができます  

# DEMO

https://twitter.com/tsugumasa320/status/1363341776581320707

# Features

黒電話のベルを市販のステップシーケンサーから鳴らすことが出来ます  
以下の３モードがあります  
  
◇PassiveMode  
 GATE入力でベルの打鍵タイミングを  
 CV入力で1ステップ毎のベルの打鍵回数を制御しています。（1~3回)  
  
◇ActiveMode  
 1Hz~50Hzの周波数で鳴らすことが出来ます  
 (50Hz以上はベルが壊れそうなので制限しています)  
  
◇ManualMode  
 正転・反転・交互等の動作をそれぞれ動作させることができます  
   
Korg SQ-1の場合、GATE出力が14Vの信号が来るので、分圧して5Vに落としてます  
  
# Requirement
  
・Arduino Uno  
・DFRobot KeyShield  
 (Gravity: Arduino LCD シールド - Arduino 用 1602 LCD キーパッドシールド)   
・電源トランス　ＨＴ－１２０５(ベル用)  
・電源トランス　ＡＣ－１０  (マイク用)
・モータードライバー  
　(HiLetgo BTS7960 43A HブリッジPWM駆動ハイパワー自動車モータードライブモジュール電流制限)  
・Korg SQ-1  
・SQ-1 to Arduino用アッテネーター  
　(抵抗分圧で14Vを5Vへ)※自作  

<img width="633" alt="スクリーンショット 2021-12-31 13 43 43" src="https://user-images.githubusercontent.com/35299183/147803815-0990fdb7-8f53-40ab-9ab7-962452f84eae.png">

<!--
◆ ベル部
        +--------------+
        |              |
  +-----+ Korg SQ-1    |
  |     |              |
  |     +--------------+
  |
  |  +-------------------+
  |  | +---------------+ |
  |  | |               | |
  |  | |  LCD Keypad   | |
  |  | |               | |
  |  | +-------^-------+ |
  |  |         | disp    |                                 +-----------------+
  |  | +-------+-------+ | +----------------+  +---------+ | +-------------+ |
  |  | |               | | |                |  |         | | |             | |
  +---+>  Arduino Uno  +--+> Motor Driver  +--+>  Trans  +--+>    Bell     | |
     | |               | | |                |  |         | | |             | |
     | +---------------+ | +----------------+  +---------+ | +-------------+ |
     |         Main Board|                                 |           Phone |
     +--------------------                                 +-----------------+

◆ マイク部
     +---------------------------------------------+
     | +---------------+         +--------------+  |  +---------+
     | |               |  ON/OFF |              |  |  |         |
     | | Phone Switch  +--------+>  Microphone  +----+>  Trans  +--+>  Audio out
     | |               |         |              |  |  |         |
     | +---------------+         +--------------+  |  +---------+
     |                                       Phone |
     +---------------------------------------------+

-->

# Note

・ベル駆動用の昇圧トランスが熱くなる  
・カーボンマイクがノイズを拾いやすい  

# Author

作成情報を列挙する  

* 作成者 湯谷承将  
* E-mail tsugumasa320@gmail.com  

# License
ライセンスを明示する  

"Kurodenwa Sequencer" is under [GNU GENERAL PUBLIC LICENSE]  
 (https://ja.wikipedia.org/wiki/GNU_General_Public_License).  
