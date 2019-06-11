#include<Servo.h>
Servo myservo;  

int pos = 0;   
int pot=A0;

void setup() {
  myservo.attach(5);  
  pinMode(pot,INPUT);
  Serial.begin(9600);
}

void loop() {
  //while(Serial.available()==0);
  
  float level=analogRead(pot);
  
  //float level = (Serial.readStringUntil('\n')).toInt();
  float rotate=(level*180)/1023;
 // rotate= constrain(rotate, 0, 180);
//int  rotate=map(level, 0,1023,0,180);
  //delay(200);
  Serial.println(level);
  Serial.println(rotate);
  myservo.write(rotate);
  delay(500);
  
  
}
