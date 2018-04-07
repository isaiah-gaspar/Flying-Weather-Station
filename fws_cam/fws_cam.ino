
// © Adafruit Industries https://learn.adafruit.com/timelapse-spy-camera
 /*
  * Edited by Isaiah Gaspar
  * 
  * Date: 3/31/18
  * 
  */

//IG Changed pins to work with teensy 3.2
int trig = 23;
int led = 13;

void setup() {
  
  // initialize the digital pins as output.
  pinMode(led, OUTPUT);
  
  pinMode(trig, OUTPUT);
  
  digitalWrite(led, HIGH);
  
  digitalWrite(trig, HIGH);
}

// Hold HIGH and trigger quick (<250ms) LOW to take a photo. Holding LOW and trigger HIGH starts/stops video recording
void loop() {
  
  digitalWrite(trig, LOW);
  digitalWrite(led, LOW);
  
//IG Changed time
  delay(50);
  
  digitalWrite(trig, HIGH);
  digitalWrite(led, HIGH);
  
  //Delay between pictures
  
//IG Changed time  
  delay(500);
}

