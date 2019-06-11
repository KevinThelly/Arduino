
int red= 5;
int yellow=10;
int white=13;
int ldrpin=A0;

void setup() {
  // put your setup code here, to run once:
  pinMode(red, OUTPUT);
  pinMode(white,OUTPUT);
  pinMode(yellow,OUTPUT);
  pinMode(ldrpin,INPUT);
  Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
  int val= analogRead(ldrpin);
  Serial.println(val);
  if(val<=50)
  {
    digitalWrite(white, HIGH);
    digitalWrite(red, LOW);
    digitalWrite(yellow, LOW);
    
  }

  else if(val >=450)
  {
    digitalWrite(yellow, HIGH);  
    digitalWrite(red, LOW);
    digitalWrite(white, LOW);  
  }

  else
  {
    digitalWrite(red, HIGH);
    digitalWrite(white, LOW);
    digitalWrite(yellow, LOW);
  }




  
}
