

int led0=3;
int led1=4;
int led2=5;
int count=0;
int val0=0;
int val1=0;
int val2=0;

void setup() {
  // put your setup code here, to run once:
  pinMode(led0,OUTPUT);
  pinMode(led1,OUTPUT);
  pinMode(led2,OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  count=count+10;
  delay(10);
  if(count%10==0)
  {
    val0=!val0;
    digitalWrite(led0,val0);
  }
  if(count%100==0)
  {
    val1=!val1;
    digitalWrite(led1,val1);    
  }

  if(count%1000==0)
  {
    val2=!val2;
    digitalWrite(led2,val2);
  }
  

}
