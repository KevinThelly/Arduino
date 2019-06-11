
 
  int ldrpin=A0 ;
  int ledpin=5;
  int val=0;
  void setup() {
  // put your setup code here, to run once:
pinMode(ldrpin,INPUT);
pinMode(ledpin,OUTPUT);
Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
  
  val=analogRead(ldrpin);
  val= constrain(val, 0, 100);
  int level=map(val, 0,100,255,0);
    analogWrite(ledpin, level);
  Serial.println(level);
  Serial.println(val);
  
 // Serial.print(digitalRead(ldrpin));
}
