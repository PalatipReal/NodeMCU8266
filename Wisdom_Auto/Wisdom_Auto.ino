/*********
  Rui Santos
  Complete project details at http://randomnerdtutorials.com  
*********/

#include <ESP8266WiFi.h>
#include <DNSServer.h>
#include <ESP8266WebServer.h>
#include <WiFiManager.h>         // https://github.com/tzapu/WiFiManager
#include <BlynkSimpleEsp8266.h>
#include <SimpleTimer.h>   //including the library of SimpleTimer

#define BLYNK_PRINT Serial
SimpleTimer timer;
char auth[] = "23cf63cbbe544e2a989b7810a4338207";
const int DELAY = 2000;
const int STARTUP_DELAY = 500;
// Set web server port number to 80
WiFiServer server(80);

void setup() {
  pinMode(D0, OUTPUT);
  pinMode(D1, OUTPUT);
  pinMode(D2, OUTPUT);
  pinMode(D5, OUTPUT);
  pinMode(D6, OUTPUT);
  pinMode(D7, OUTPUT);

  Serial.begin(115200);
  
  // Initialize the output variables as outputs
  // WiFiManager
  // Local intialization. Once its business is done, there is no need to keep it around
  WiFiManager wifiManager;
  
  // Uncomment and run it once, if you want to erase all the stored information
  //wifiManager.resetSettings();
  
  // set custom ip for portal
  //wifiManager.setAPConfig(IPAddress(10,0,1,1), IPAddress(10,0,1,1), IPAddress(255,255,255,0));

  // fetches ssid and pass from eeprom and tries to connect
  // if it does not connect it starts an access point with the specified name
  // here  "AutoConnectAP"
  // and goes into a blocking loop awaiting configuration
  wifiManager.autoConnect("AutoConnectAP");
  // or use this for auto generated name ESP + ChipID
  //wifiManager.autoConnect();
  
  // if you get here you have connected to the WiFi
  Serial.println("Connected.");
  
  server.begin();

  Blynk.config(auth);
  delay(STARTUP_DELAY);
}

void loop(){
    // put your main code here, to run repeatedly:
  Blynk.run();
  timer.run();  
  yield();
  delay(DELAY);
 
}


BLYNK_WRITE(V0){
  int pinValue = param.asInt();
  Serial.println(pinValue);
  digitalWrite(D0, pinValue); // turn the LED on.
  
  if(pinValue == 1){
   Serial.println("Pump1 Off");}
  else {
    Serial.println("Pump1 On");}
  }
  
  BLYNK_WRITE(V1){
  int pinValue = param.asInt();
  Serial.println(pinValue);
  digitalWrite(D1, pinValue); // turn the LED on.
  
  if(pinValue == 1){
   Serial.println("Pump2 Off");}
  else {
    Serial.println("Pump2 On");}
  }

  
  BLYNK_WRITE(V2){
  int pinValue = param.asInt();
  Serial.println(pinValue);
  digitalWrite(D2, pinValue); // turn the LED on.
  
  if(pinValue == 1){
   Serial.println("Pump3 Off");}
  else {
    Serial.println("Pump3 On");}
  }
  
  BLYNK_WRITE(V3){
  int pinValue = param.asInt();
  Serial.println(pinValue);
  digitalWrite(D5, pinValue); // turn the LED on.
  
  if(pinValue == 1){
   Serial.println("Pump4 Off");}
  else {
    Serial.println("Pump4 On");}
  }

    BLYNK_WRITE(V4){
  int pinValue = param.asInt();
  Serial.println(pinValue);
  digitalWrite(D6, pinValue); // turn the LED on.
  
  if(pinValue == 1){
   Serial.println("Pump5 Off");}
  else {
    Serial.println("Pump5 On");}
  }

    BLYNK_WRITE(V5){
  int pinValue = param.asInt();
  Serial.println(pinValue);
  digitalWrite(D7, pinValue); // turn the LED on.
  
  if(pinValue == 1){
   Serial.println("Pump6 Off");}
  else {
    Serial.println("Pump6 On");}
  }
