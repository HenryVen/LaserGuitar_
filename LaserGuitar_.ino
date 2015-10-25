#define inPin0 0
#define inPin1 1
#define inPin2 2
void setup(void) {
 
  Serial.begin(9600);
  Serial.println();
  pinMode(8,OUTPUT);
  
}
 
void loop(void) {
  int pinRead0 = analogRead(inPin0);
  int pinRead1 = analogRead(inPin1);
   int pinRead2 = analogRead(inPin2);
   
  /*
  Serial.print(pinRead0);
  Serial.print("  ");
  Serial.print(pinRead1);
  Serial.print("  ");
  Serial.print(pinRead2);
  Serial.println();
  
  delay(100);

  */ 
   if (pinRead0 < 10)
  {
     digitalWrite(8,HIGH);
  tone(8,500,100);
  
  }
  if (pinRead1 < 10)
  {
     digitalWrite(8,HIGH);
  tone(8,500,500);
  }  
   if (pinRead2 < 10)
  {
     digitalWrite(8,HIGH);
  tone(8,350,500);
  
  }  

}
 
  

