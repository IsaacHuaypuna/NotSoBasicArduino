//Lucy Armengol
//New Ping
//This code makes an led light up when it detects something less than 10 centimeters away. I used the NewPing library.
 
#include <NewPing.h> //Downloads the NewPing library, which makes it a lot more efficent
 
#define TRIGGER_PIN 12
#define ECHO_PIN 11
#define MAX_DISTANCE 200
 
int ledPin = 8;
int cm; //makes cm an interger
 
NewPing myHCSR04(TRIGGER_PIN, ECHO_PIN, MAX_DISTANCE); //replaces the sensor function used in Hello Functions
 
void setup() {
 Serial.begin(9600);
 pinMode(TRIGGER_PIN, OUTPUT);
 pinMode(ECHO_PIN, INPUT);
 pinMode(ledPin, OUTPUT);
}
 
void loop() {
  cm = myHCSR04.ping_cm();
 
  if (cm !=0){ //will run if distance doesn't equal zero
    if (cm < 10){ //will run if distance is less than ten
      ledOn(); //uses function that turns led on
    }
  else{
    ledOff(); //uses function that turns led off if the if statement is not true
  }
  }
     Serial.println(cm);
     delay(50); //prints distance at a readable speed
}
 
void ledOn(){
  digitalWrite(ledPin, HIGH); //turns led on
}
 
void ledOff(){
  digitalWrite(ledPin, LOW); //turns led off
}