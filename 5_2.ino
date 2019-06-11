int led1=3;
int led2=4;
int led3=5;
int t1,t2,t3;

 int ledval1=0;
int ledval2=0;
int ledval3=0;

unsigned long int sec=millis();

void setup() {
  // put your setup code here, to run once:
  pinMode(led1,OUTPUT);
  pinMode(led2,OUTPUT);
  pinMode(led3,OUTPUT);
  Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
  String a[6];
  String b="     ";
  String s;
  int k=0,j=0,count=0,i=0;
  
  if(Serial.available()){
  s=Serial.readStringUntil('\n');
  Serial.println(s);
   
  while(s[i]){
    if(s[i]!=' ')
    {
      b[k]=s[i];
      k++;
    }
    else
    {
      a[count]=b;
      b="      ";
      k=0;
      count+=1;      
    }
    i++;
  }
  a[count]=b;
  t1=a[1].toInt();
  t2=a[3].toInt();
  t3=a[5].toInt();
  Serial.println(t1);
  Serial.println(t2);
  Serial.println(t3);
  
  }

  sec=millis();
 
  
  if(sec%t1==0)
  {
     ledval1=!ledval1;
    digitalWrite(led1,ledval1);
   // Serial.println(sec);
  }

  if(sec%t2==0)
  { 
    ledval2=!ledval2;
    digitalWrite(led2,ledval2);
  }

  if(sec%t3==0)
  {
     ledval3=!ledval3;
    digitalWrite(led3,ledval3);
  }
  
}
