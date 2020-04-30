void setup()
{
  #include <Keyboard.h>  // Includes the Keyboard library.
  
  pinMode(9, OUTPUT);    // Defines Pin 9 as output. PLUG THE RED PART OF THE LED IN THIS PIN.
  pinMode(10, OUTPUT);   // Defines Pin 10 as output PLUG THE GREEN PART OF THE LED IN THIS PIN.
  pinMode(11, OUTPUT);   // Defines Pin 11 as output PLUG THE BLUE PART OF THE LED IN THIS PIN.

  pinMode(18, INPUT);    // Defines Pin 18 as output
  pinMode(19, INPUT);    // Defines Pin 18 as output
  pinMode(20, INPUT);    // Defines Pin 18 as output
  pinMode(21, INPUT);    // Defines Pin 18 as output
  Serial.begin(9600);    // Starts Serial Port (to get debug information through IDE)
}

void loop()
{
  
  //Keep in mind: this code was designed to work with common anode RGB LED. So, when you want some color ON, you turn the digital pins OFF.)
  //Sets up LED full RED, to indicate when it is on)
  digitalWrite(9, 0);
  digitalWrite(10, 1);
  digitalWrite(11, 1);

  //Reads the main trigger status. If pressed, will give it a keyboard stroke.
  if (digitalRead(9) == HIGH) {
    //Sends keyboard command to print ")" if trigger is pressed.
    Keyboard.write(41)
    //Turns LED Green
    analogWrite(9, 1);
    analogWrite(10, 0);
    analogWrite(11, 1);
    //Sends information through Serial Monitor
    Serial.println("PTT ON");
  }

  //Reads the upper button status. If pressed, will give it a keyboard stroke.
  if (digitalRead(9) == HIGH) {
    //Sends keyboard command to print "*" if trigger is pressed.
    Keyboard.write(42)
    //Turns LED White
    digitalWrite(9, 1);
    digitalWrite(10, 1);
    digitalWrite(11, 1);
    //Sends information through Serial Monitor
    Serial.println("BUTTON 1 ON");
  }

  //Reads the middle button status. If pressed, will give it a keyboard stroke.
  if (digitalRead(9) == HIGH) {
    //Sends keyboard command to print "+" if trigger is pressed.
    Keyboard.write(43)
    //Turns LED Purple
    digitalWrite(9, 0);
    digitalWrite(10, 1);
    digitalWrite(11, 0);
    //Sends information through Serial Monitor
    Serial.println("BUTTON 2 ON");
  }

  //Reads the lower button status. If pressed, will give it a keyboard stroke.
  if (digitalRead(9) == HIGH) {
    //Sends keyboard command to print "&" if trigger is pressed.
    Keyboard.write(38)
    //Turns LED Blue
    digitalWrite(9, 0);
    digitalWrite(10, 0);
    digitalWrite(11, 1);
    //Sends information through Serial Monitor
    Serial.println("BUTTON 2 ON");
  }
  
  delay(10); //Delays the next execution, so the computer doesn't get overflown. Can (and should) be removed if yout machine can handle the pooling from Arduino.
}
