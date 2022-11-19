#include <Arduino.h>
//#include "Keyboard.h"
#include "Wire.h"
#include <Arduino_APDS9960.h>
#include <BleKeyboard.h>

BleKeyboard Keyboard;
volatile bool flag1 = false;
volatile bool flag2 = false;
#define SDA_1 26
#define SCL_1 27

#define SDA_2 15
#define SCL_2 5

TwoWire I2Cone = TwoWire(0);
TwoWire I2Ctwo = TwoWire(1);
APDS9960 left(I2Cone, 0);
APDS9960 right(I2Ctwo, 2);
int previousButtonState = HIGH; // for checking the state of a pushButton
int counter = 0;

void g_ISR1();
void g_ISR2();

void setup()
{
  Serial.begin(9600);
  I2Cone.begin(SDA_1, SCL_1, 100000); 
  I2Ctwo.begin(SDA_2, SCL_2, 100000);
  //initialize control over the keyboard:
 Keyboard.begin();
  left.begin();
  right.begin();
  left.setGestureSensitivity(80);
  right.setGestureSensitivity(80);

  attachInterrupt(digitalPinToInterrupt(0), g_ISR1, RISING);
  attachInterrupt(digitalPinToInterrupt(2), g_ISR2, RISING);
 
}

void loop()
{
  if (left.gestureAvailable())
  {
    // a gesture was detected, read and print to Serial Monitor
    int gesture = left.readGesture();

    switch (gesture)
    {
    case GESTURE_UP:
      Serial.println("Detected UP gesture");
      break;

    case GESTURE_DOWN:
      Serial.println("Detected DOWN gesture");
      break;

    case GESTURE_LEFT:
      Serial.println("Detected LEFT gesture");
     Keyboard.press(KEY_LEFT_ARROW);
     Keyboard.releaseAll();
      break;

    case GESTURE_RIGHT:
      Serial.println("Detected RIGHT gesture");
      Keyboard.press(KEY_RIGHT_ARROW);
      Keyboard.releaseAll();
      break;

    default:
      // ignore
      break;
    }
  }
    if (right.gestureAvailable())
  {
    // a gesture was detected, read and print to Serial Monitor
    int gesture = right.readGesture();

    switch (gesture)
    {
    case GESTURE_UP:
      Serial.println("Detected UP gesture");
      break;

    case GESTURE_DOWN:
      Serial.println("Detected DOWN gesture");
      break;

    case GESTURE_LEFT:
      Serial.println("Detected LEFT gesture");
      Keyboard.press(KEY_LEFT_ARROW);
      Keyboard.releaseAll();
      break;

    case GESTURE_RIGHT:
      Serial.println("Detected RIGHT gesture");
      Keyboard.press(KEY_RIGHT_ARROW);
      Keyboard.releaseAll();
      break;

    default:
      // ignore
      break;
    }
  }
}

void g_ISR1()
{
  flag1 = true;
}

void g_ISR2()
{
  flag2 = true;
}