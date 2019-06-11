int led=3;
int count=0;
int val;
unsigned long int sec=millis(); 


void setup() {
  // put your setup code here, to run once:
  pinMode(led,OUTPUT);
  Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
  if(Serial.available()==0)
  {
    sec=millis();

    if(sec%val==0)
    {
      Serial.println(val);
      //Serial.println(sec);
      digitalWrite(led,HIGH);
      delay(100);
      digitalWrite(led,LOW);
    } 

      if(sec%10000==0)
      {
        Serial.println(val);
      }
  }

  else
  {
    val=(Serial.readStringUntil('\n')).toInt();  
  }

  
}
