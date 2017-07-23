#include <Servo.h>
Servo ServoX;
const int threshValue = 100;
static int once = 0;
static int previousValue;
static int newValue;
static int x = 90;

void setup() 
{
  Serial.begin(9600); 
  ServoX.attach(9);
}

void loop() 
{
  if(once == 0)
  {
    newValue = analogRead(A5);
    Serial.println(newValue);
  }
  
  ServoX.write(x);
  
  valueUpdate();
  
  Serial.println(newValue);
  delay(200); 
    
  if(previousValue <= threshValue && newValue > threshValue)
  {
      switch(x)
      {
        case 90:
            x = 180;
            break;
        
        case 180:
            x = 90;
            break;

        default:
            break;
      }
  }
  once = 1;
}

void valueUpdate()
{
  previousValue = newValue;
  newValue = analogRead(A5);
  return;
}

