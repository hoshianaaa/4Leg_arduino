#include <FlexiTimer2.h>
#include <Servo.h>
#include "gyro.h"


Servo servo[12];
const int LED_R = 20;
const int LED_L = A12;
const int SW_R = 30;//右スイッチ
const int SW_L = 44;//左スイッチ

double data[3];

void flash() {
  static int flag;
  static int degree;

  if (flag == false) {
    for (int i = 0; i < 12; i++)servo[i].write(degree);
    degree++;
    if (degree == 180)flag = true;
  }
  else
  {
    for (int i = 0; i < 12; i++)servo[i].write(degree);
    degree--;
    if (degree == 0)flag = false;

  }
}


void setup() {
  Serial.begin(9600);
  for (int i = 0; i < 12; i++) {
    servo[i].attach(13 - i);
  }
  pinMode(LED_R, OUTPUT);
  pinMode(LED_L, OUTPUT);
  pinMode(SW_R, INPUT_PULLUP);
  pinMode(SW_L, INPUT_PULLUP);

  FlexiTimer2::set(15, 1.0 / 1000, flash); // 15 * 1ms ごとにタイマー割込み
  FlexiTimer2::start();

  gyro_init();
}


void loop() {

  if (digitalRead(SW_R) == HIGH)digitalWrite(LED_R, HIGH);
  else digitalWrite(LED_R, LOW);

  gyro_read(data);

  for(int i=0;i<3;i++){
    Serial.print(data[i]);
    Serial.print(" ");
  }
  Serial.println("");
  
}
