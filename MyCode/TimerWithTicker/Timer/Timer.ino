
#include <ESP8266WiFi.h>
#include <Ticker.h>  //Ticker Library
Ticker blinker;
//=======================================================================
void changeState()
{
  digitalWrite(LED, !(digitalRead(LED)));  //Invert Current State of LED  
}
//=======================================================================
//                               Setup
//=======================================================================
void setup()
{
    Serial.begin(115200);
    Serial.println("");
    pinMode(LED,OUTPUT);
    //Initialize Ticker every 0.5s
    blinker.attach(0.5, changeState); //Use <strong>attach_ms</strong> if you need time in ms
}
//=======================================================================
//                MAIN LOOP
//=======================================================================
void loop()
{
}
//=======================================================================
