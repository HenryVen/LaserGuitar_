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
#define debug

SdFat sd;
SFEMP3Shield MP3player;
volatile int state = 0;
const int buttonPin = 2;
int pinStates [6] = {0, 0, 0, 0, 0, 0};
int cutoff = 60;
int lasttrack = -999;
// Read Pins, store into Array
int repeat = 1;

void setup(void) {
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
  pinMode(5, INPUT);

}

void loop(void) {


  if (digitalRead(5) == HIGH)
  {
    state = state + 1;


    if (state > 3)
    {
      state = 0;
    }
  }

  for (int j = 0; j < 6; j++) {
    pinStates[j] = analogRead(j);
  }
  for (int i = 0; i < 6; i++) {
    if (pinStates[i] < cutoff && repeat == 1) {
      MP3player.stopTrack();
      MP3player.playTrack(6 * state + (i + 1));
      lasttrack = i;
      repeat = 0;
    }
    if (!MP3player.isPlaying())
    {
      lasttrack = -999;
    }
    if (MP3player.isPlaying() && analogRead(i) > cutoff )
    {
      repeat = 1;
    }
  }



#ifdef debug
  for (int k = 0; k < 6; k++) {
    Serial.print(pinStates[k]);
    Serial.print(" ");
  }
  Serial.println(state);
  delay(200);
#endif


}

void buttonpress() {
  state++;
  if (state > 2)
  {
    state = 0;
  }

}
