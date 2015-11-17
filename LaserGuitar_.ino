#include <SPI.h>
#include <SdFat.h>
#include <SdFatUtil.h> 
#include <SFEMP3Shield.h>
#define inPin0 0
#define inPin1 1
#define inPin2 2
#define inPin3 3
#define inPin4 4
#define inPin5 5
//#define debug

SdFat sd;
SFEMP3Shield MP3player;
volatile int state = 0;
const int buttonPin = 2;    
int buttonState = 0;       


void setup(void) {
  attachInterrupt(digitalPinToInterrupt(buttonPin),buttonpress, FALLING);
 #ifdef debug
  Serial.begin(9600);
  Serial.println();
  #endif
  sd.begin(SD_SEL, SPI_HALF_SPEED);
  MP3player.begin();
  pinMode(buttonPin, INPUT);
  pinMode(inPin0, INPUT);
  pinMode(inPin1, INPUT);
  pinMode(inPin2, INPUT);
  pinMode(inPin3, INPUT);
  pinMode(inPin4, INPUT);
  pinMode(inPin5, INPUT);

  
}
 
void loop(void) {
 
  int pinRead0 = analogRead(inPin0);
  int pinRead1 = analogRead(inPin1);
  int pinRead2 = analogRead(inPin2);
  int pinRead3 = analogRead(inPin3);
  int pinRead4 = analogRead(inPin4);
  int pinRead5 = analogRead(inPin5);
 
 #ifdef debug
  Serial.print(pinRead0);
  Serial.print("  ");
  Serial.print(pinRead1);
  Serial.print("  ");
  Serial.print(pinRead2);
  Serial.print("  ");
  Serial.print(pinRead3);
  Serial.print("  ");
  Serial.print(pinRead4);
  Serial.print("  ");
  Serial.print(pinRead5);
  Serial.print("  ");
  Serial.println(state);
  delay(200);
  #endif
  
//int state = 0 define state?
  
  buttonState = digitalRead(buttonPin);


   switch (state) {
    //state= case #?
 
    case 1:
    
   if (pinRead0 < 50)
  {
    MP3player.playTrack(1);
  
  }
  if (pinRead1 < 50)
  {
     MP3player.playTrack(2);
  }  
   if (pinRead2 < 50)
  {
     MP3player.playTrack(3);
  
  }  
 if (pinRead3 < 50)
  {
     MP3player.playTrack(4);
  
  }  
 if (pinRead4 < 50)
  {
     MP3player.playTrack(5);
  
  }  
 if (pinRead5 < 50)
  {
     MP3player.playTrack(6);
  }  
      //do something when state equals 1
      break;
    case 2:

     if (pinRead0 > 50)
  {
    MP3player.playTrack(7);
  
  }
  if (pinRead1 > 10)
  {
     MP3player.playTrack(8);
  }  
   if (pinRead2 > 10)
  {
     MP3player.playTrack(9);
  
  }  
 if (pinRead3 > 10)
  {
     MP3player.playTrack(10);
  
  }  
 if (pinRead4 > 10)
  {
     MP3player.playTrack(11);
  
  }  
 if (pinRead5 > 10)
  {
     MP3player.playTrack(12);
  }  
      //do something when state equals 2
      break;
    default: 
     Serial.println("error");
 //set case to 1
      // if nothing else matches, do the default
      // default is optional
    break;
  }
  
 if (state>2)
 {
  state = 1;
 }



}

   void buttonpress() {
  state++; 
   }

  

