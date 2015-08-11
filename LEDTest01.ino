// color swirl! connect an RGB LED to the PWM pins as indicated
// in the #defines
// public domain, enjoy!

#define REDPIN 5
#define GREENPIN 6
#define BLUEPIN 3

#define FADESPEED 5     // make this higher to slow down

char command;
int value;


void setup() 
{
  pinMode(REDPIN, OUTPUT);
  pinMode(GREENPIN, OUTPUT);
  pinMode(BLUEPIN, OUTPUT);

  Serial.begin(57600);
}


void loop() 
{
  if (Serial.available() > 1) 
  {
    command = Serial.read();
    value = Serial.read() -48;
    Serial.println(value, DEC);

    if(command == 'R')
    {
      analogWrite(REDPIN, value * 25);
    }
    else if(command == 'G')
    {
      analogWrite(GREENPIN, value * 25);
    }
    else if(command == 'B')
    {
      analogWrite(BLUEPIN, value * 25);
    }
  }

}
