int button=2;
int led0=3;
int led1=4;
int led2=5;
int led=13;
int count=0;
int state=1;
int r[3]={0,0,0};

void setup() {
  // put your setup code here, to run once:
  pinMode(button,INPUT);
  pinMode(led,OUTPUT);
  pinMode(led0,OUTPUT);
  pinMode(led1,OUTPUT);
  pinMode(led2,OUTPUT);
  Serial.begin(9600);
}

void binaryv(int number)
{
  int binaryv=0;
  int i=0;
  r[0]=0;
  r[1]=0;
  r[2]=0;
  //int temp=0;
  while(number!=0)
  {
    if(number%2!=0)
    {
      r[i]=1;
    }
    else
    {
      r[i]=0;
    }
    i++;
    number=number/2;
  }
  
}

void loop() {
  // put your main code here, to run repeatedly:
  int value=digitalRead(button);
  if(value==HIGH)
  {
    digitalWrite(led, HIGH);
    if(state==0)
    {
      count=count+1;      
    }
    state=1;
  }
  else
  {
    state=0;
    digitalWrite(led,LOW);
  }
  if(count==8)
  {
    count=0;
  }
  binaryv(count);
  
  Serial.print(r[2]);
  Serial.print(r[1]);
  Serial.println(r[0]);
  Serial.println(count);
  digitalWrite(led0,r[2]);
  digitalWrite(led1,r[1]);
  digitalWrite(led2,r[0]);
  
}
