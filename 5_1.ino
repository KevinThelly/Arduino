
int led[3]={3,4,5};
int buttonleft=6;
int buttonright=2;
int current=1;
int leftstate=0;
int rightstate=0;

void setup() {
  // put your setup code here, to run once:
  pinMode(led[0],OUTPUT);
  pinMode(led[1],OUTPUT);
  pinMode(led[2],OUTPUT);
  pinMode(buttonleft,INPUT);
  pinMode(buttonright,INPUT);
  Serial.begin(9600);

}

void loop() {
  // put your main code here, to run repeatedly:

  int left=digitalRead(buttonleft);
  int right=digitalRead(buttonright);
  digitalWrite(led[0],LOW);
  digitalWrite(led[1],LOW);
  digitalWrite(led[2],LOW);

  if(left==HIGH)
  {
    if(leftstate==0)
    {
      digitalWrite(13,HIGH);
      current--;
      if(current<0)
      {
        current = 2;
      }    
    }
    leftstate=1;
  }
  else
  {
    leftstate=0;
  }
  
//toggle right-----

  if(right==HIGH)
  {
    if(rightstate==0)
    {
      current++;
      if(current>2)
      {
        current=0;
      }   
    }
    rightstate=1;
  }
  else
  {
    rightstate=0;
  }


  digitalWrite(led[current],HIGH);
  Serial.println(current);

}
