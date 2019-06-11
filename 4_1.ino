int led0=3;
int led1=4;
int led2=5;
char x;

void setup() {
  // put your setup code here, to run once:
  pinMode(led0,OUTPUT);
  pinMode(led1,OUTPUT);
  pinMode(led2,OUTPUT);
  Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
  while(Serial.available()==0);
  String val=Serial.readStringUntil('\n');

  int i=0;
  int letter=0;
  int number=0;
  int count=0;
  while(val[i])
  {
    x=val[i];
    if((x>='a' && x<='z') || (x>='A' && x<='Z')) 
    {
      letter=1;
      count++;
    }
    else if( x>='0' && x<='9')
    {
      number=1;
    }
    else
    {
      number=1;
      letter=1;
    }
   i++;  
  }
  if(letter==1 && number==0 && count>4)
  {
    digitalWrite(led0,HIGH);
    delay(100);
    digitalWrite(led0,LOW);
    Serial.println("String");    
  }
  else if(letter==0 && number==1)
  {
    digitalWrite(led1,HIGH);
    delay(100);
    digitalWrite(led1,LOW);
    Serial.println("number");    
  }
  else if((letter==1 && number==1) || count<=4 )
  {
    digitalWrite(led2,HIGH);
    delay(100);
    digitalWrite(led2,LOW);
    Serial.println("garbage");
  }  
//Serial.println(number);
//Serial.println(letter);
  
}
