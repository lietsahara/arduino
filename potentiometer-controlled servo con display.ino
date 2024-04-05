/*for servo motor control*/
#include <Servo.h>
Servo servo1;//object creation

int servopin=3;//servo signal pin connected to 3
int potentiometer=A0;


/*for output*/
const int maxi=600;
const int mins=0;
void setup() {
Serial.begin(9600);
/*servo*/
servo1.attach(servopin);//connecting obj. to pin
}

void loop() {
  /*reading printing*/
int sensorreading=analogRead(A0);
int range = map(sensorreading, mins, maxi,0, 3);
switch(range){
  case 0:
    Serial.println("low");
    break;
  case 1:
    Serial.println("med");
    break;
  case 2:
    Serial.println("high");
    break;
  case 3:
    Serial.println("higher");
    break;
}
  
delay(3000);
/*servo control*/
int reading=analogRead(A0);
int angle=map(reading, 0, 1023, 0, 180);//if 0 moves to 0 degrees and 1023 to 180 degrees 

servo1.write(angle);
}
