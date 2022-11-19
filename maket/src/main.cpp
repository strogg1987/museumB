#include <Arduino.h>
#include "BleKeyboard.h"
// номера портов для светодиодов
const int ledPin0 = 15;
const int ledPin1 = 2;
const int ledPin2 = 4;
const int ledPin3 = 16;
const int ledPin4 = 17;
const int ledPin5 = 5;
const int ledPin6 = 18;
const int ledPin7 = 19;
const int ledPin8 = 21;
const int ledPin9 = 22;
const int ledPin10 = 1;

// задаём свойства ШИМ-сигнала
const int freq = 1000;
const int ledChannel0 = 0;
const int ledChannel1 = 1;
const int ledChannel2 = 2;
const int ledChannel3 = 3;
const int ledChannel4 = 4;
const int ledChannel5 = 5;
const int ledChannel6 = 6;
const int ledChannel7 = 7;
const int ledChannel8 = 8;
const int ledChannel9 = 9;
const int ledChannel10 = 10;
// inputs00000000000
const int input0 = 13;
const int input1 = 12;
const int input2 = 14;
const int input3 = 27;
const int input4 = 26;
const int input5 = 25;
const int input6 = 33;
const int input7 = 32;
const int input8 = 35;
const int input9 = 34;
const int input10 = 39;
BleKeyboard bleKeyboard;
int readInput();
void setup()
{
  bleKeyboard.begin();
  ledcSetup(ledChannel0, freq, 8);
  ledcSetup(ledChannel1, freq, 8);
  ledcSetup(ledChannel2, freq, 8);
  ledcSetup(ledChannel3, freq, 8);
  ledcSetup(ledChannel4, freq, 8);
  ledcSetup(ledChannel5, freq, 8);
  ledcSetup(ledChannel6, freq, 8);
  ledcSetup(ledChannel7, freq, 8);
  ledcSetup(ledChannel8, freq, 8);
  ledcSetup(ledChannel9, freq, 8);
  ledcSetup(ledChannel10, freq, 8);
  ledcAttachPin(ledPin0, ledChannel0);
  ledcAttachPin(ledPin1, ledChannel1);
  ledcAttachPin(ledPin2, ledChannel2);
  ledcAttachPin(ledPin3, ledChannel3);
  ledcAttachPin(ledPin4, ledChannel4);
  ledcAttachPin(ledPin5, ledChannel5);
  ledcAttachPin(ledPin6, ledChannel6);
  ledcAttachPin(ledPin7, ledChannel7);
  ledcAttachPin(ledPin8, ledChannel8);
  ledcAttachPin(ledPin9, ledChannel9);
  ledcAttachPin(ledPin10, ledChannel10);
  pinMode(input0, INPUT_PULLDOWN);
  pinMode(input1, INPUT_PULLDOWN);
  pinMode(input2, INPUT_PULLDOWN);
  pinMode(input3, INPUT_PULLDOWN);
  pinMode(input4, INPUT_PULLDOWN);
  pinMode(input5, INPUT_PULLDOWN);
  pinMode(input6, INPUT_PULLDOWN);
  pinMode(input7, INPUT_PULLDOWN);
  pinMode(input8, INPUT_PULLDOWN);
  pinMode(input9, INPUT_PULLDOWN);
  pinMode(input10, INPUT_PULLDOWN);
  for (int i = 0; i < 10; i++)
  {
    ledcWrite(i, 64);
  }
  // put your setup code here, to run once:0000
}

void loop()
{
  // put your main code here, to run repeatedly:
  int state = readInput();
    switch (state)
    {
    case 0:
      bleKeyboard.press('0');
      bleKeyboard.releaseAll();
      ledcWrite(state, 200);
      delay(5000);
      ledcWrite(state, 64);
      break;

    case 1:
      bleKeyboard.press('1');
      bleKeyboard.releaseAll();
      ledcWrite(state, 200);
      delay(5000);
      ledcWrite(state, 64);
      break;

    case 2:
      bleKeyboard.press('2');
      bleKeyboard.releaseAll();
      ledcWrite(state, 200);
      delay(5000);
      ledcWrite(state, 64);
      break;

    case 3:
      bleKeyboard.press('3');
      bleKeyboard.releaseAll();
      ledcWrite(state, 200);
      delay(5000);
      ledcWrite(state, 64);
      break;
    case 4:
      bleKeyboard.press('4');
      bleKeyboard.releaseAll();
      ledcWrite(state, 200);
      delay(5000);
      ledcWrite(state, 64);
      break;

    case 5:
      bleKeyboard.press('5');
      bleKeyboard.releaseAll();
      ledcWrite(state, 200);
      delay(5000);
      ledcWrite(state, 64);
      break;

    case 6:
      bleKeyboard.press('6');
      bleKeyboard.releaseAll();
      ledcWrite(state, 200);
      delay(5000);
      ledcWrite(state, 64);
      break;

    case 7:
      bleKeyboard.press('7');
      bleKeyboard.releaseAll();
      ledcWrite(state, 200);
      delay(5000);
      ledcWrite(state, 64);
      break;

    case 8:
      bleKeyboard.press('8');
      bleKeyboard.releaseAll();
      ledcWrite(state, 200);
      delay(5000);
      ledcWrite(state, 64);
      break;

    case 9:
      bleKeyboard.press('9');
      bleKeyboard.releaseAll();
      ledcWrite(state, 200);
      delay(5000);
      ledcWrite(state, 64);
      break;

    case 10:
      bleKeyboard.press('-');
      bleKeyboard.releaseAll();
      ledcWrite(state, 200);
      delay(5000);
      ledcWrite(state, 64);
      break;
    default:
      break;
    }
  
}

int readInput()
{
  if (digitalRead(input0))
  {
    return 0;
  }
  if (digitalRead(input1))
  {
    return 1;
  }
  if (digitalRead(input2))
  {
    return 2;
  }
  if (digitalRead(input3))
  {
    return 3;
  }
  if (digitalRead(input4))
  {
    return 4;
  }
  if (digitalRead(input5))
  {
    return 5;
  }
  if (digitalRead(input6))
  {
    return 6;
  }
  if (digitalRead(input7))
  {
    return 7;
  }
  if (digitalRead(input8))
  {
    return 8;
  }
  if (digitalRead(input9))
  {
    return 9;
  }
  if (digitalRead(input10))
  {
    return 10;
  }
  else
    return 12;
}