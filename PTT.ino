//Includes the Keyboard Library, so the device will be recognized as an HID.
#include <Keyboard.h>

//Defines where the LED is connected to the Arduino.
int red = 3;
int green = 6;
int blue = 9;

//Defines where the buttons are connected to the Arduino.
int ptt = A0;
int button1 = A1;
int button2 = A2;
int button3 = A3;

void setup() {

  //Starts Serial Communication
  Serial.begin(9600);

  //Tells the Arduino to use LED as output.
  pinMode(red, OUTPUT);
  pinMode(green, OUTPUT);
  pinMode(blue, OUTPUT);

  //Tells the Arduino to use buttons as INPUT.
  pinMode(ptt, INPUT);
  pinMode(button1, INPUT);
  pinMode(button2, INPUT);
  pinMode(button3, INPUT);
}

void loop() {
  
  //Sets LED to show RED, indicating Standby.
  analogWrite(red, 0);
  analogWrite(green, 255);
  analogWrite(blue, 255);

  //Reads PTT trigger. If pressed, will execute action down the line.
  if(digitalRead(ptt) == HIGH){
    
    Keyboard.press(KEY_LEFT_CTRL);  //Presses Left CTRL.
    Serial.print("PTT");            //Sends information to Serial Monitor

    //Turns LED green
    analogWrite(red,255);
    analogWrite(green,0);
    analogWrite(blue,255);
  }
  //If PTT trigger is not pressed, will execute action down the line:
  else{
    Keyboard.release(KEY_LEFT_CTRL); //Release Left CTRL.
  }

  //Reads Upper button. If pressed, will execute action down the line.
  if(digitalRead(button1) == HIGH){
    
    Keyboard.press(KEY_RIGHT_CTRL);  //Presses Right CTRL.
    Serial.print("BUTTON 1");            //Sends information to Serial Monitor

    //Turns LED dimm white.
    analogWrite(red,200);
    analogWrite(green,200);
    analogWrite(blue,200);
  }
  //If Upper Button is not pressed, will execute action down the line:
  else{
    Keyboard.release(KEY_RIGHT_CTRL); //Release Right CTRL.
  }

    //Reads Middle Button. If pressed, will execute action down the line.
  if(digitalRead(button2) == HIGH){
    
    Keyboard.press(KEY_HOME);  //Presses HOME.
    Serial.print("BUTTON 2");            //Sends information to Serial Monitor

    //Turns LED purple
    analogWrite(red,0);
    analogWrite(green,255);
    analogWrite(blue,0);
  }
  //If Middle Button is not pressed, will execute action down the line:
  else{
    Keyboard.release(KEY_HOME); //Release HOME key.
  }

    //Reads Bottom button. If pressed, will execute action down the line.
  if(digitalRead(button3) == HIGH){
    
    Keyboard.press(KEY_END);  //Presses Left CTRL.
    Serial.print("BUTTON 3");            //Sends information to Serial Monitor

    //Turns LED dimm RED (it might seem like we've turned the LED black, but due to Arduino duty cicle, it remains slightly RED due to the standby red light
    analogWrite(red,255);
    analogWrite(green,255);
    analogWrite(blue,255);
  }
  //If Bottom button is not pressed, will execute action down the line:
  else{
    Keyboard.release(KEY_END); //Release END key.
  }
  delay(30); //States a delay to not overpool the computer.
  }
