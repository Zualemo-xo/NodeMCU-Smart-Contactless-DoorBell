
/* Nodemcu ESP8266 & Blynk */
#include <ESP8266WiFi.h>
#include <BlynkSimpleEsp8266.h>
#include <SimpleTimer.h>

#define BLYNK_PRINT Serial    // Comment this out to disable prints and save space

char auth[] = "";

/* WiFi credentials */

char ssid[] = "";
char pass[] = "";
SimpleTimer timer;
/*BlynkTimer timer;*/
int IRsensor = D2; // IR Sensor Connected
int Buzzer = D1; 

void setup() 
{
  Serial.begin(115200);
  Blynk.begin(auth, ssid, pass);
  pinMode(IRsensor, INPUT_PULLUP);
  pinMode(D3, INPUT);
  pinMode(Buzzer, OUTPUT);
  
  timer.setInterval(1000L, Sensor);
  timer.setInterval(1000L, FromApp);
}

void loop() 
{
  timer.run(); // Initiates SimpleTimer
  Blynk.run();
}

void Sensor()
{

while( digitalRead(IRsensor) == LOW) 
{
  digitalWrite(Buzzer, HIGH);
  delay(2000); // Buzzer remains ON for 2 seconds.
  Blynk.begin(auth, ssid, pass); // this again connects the Blynk application. 
}

  
}

void FromApp()
{

 if(digitalRead(D3) == HIGH) // D3 is gp0 on the blynk app
 {
digitalWrite(Buzzer, HIGH);
 }
 if(digitalRead(D3) == LOW)
 {
digitalWrite(Buzzer, LOW);
 }
   
}
