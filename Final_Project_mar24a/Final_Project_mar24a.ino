#include "arduino_secrets.h"


const int pResistorPin = A0;
const int ledPin = 9;       

#include "thingProperties.h"

void setup() {
    pinMode(ledPin, OUTPUT);  
  pinMode(pResistorPin, INPUT);

  // Initialize serial and wait for port to open:
  Serial.begin(9600);
  // This delay gives the chance to wait for a Serial Monitor without blocking if none is found
  delay(1500); 

  

  // Connect to Arduino IoT Cloud
  ArduinoCloud.begin(ArduinoIoTPreferredConnection);
  //threshold=70;
  light = analogRead(pResistorPin);
  
 
  setDebugMessageLevel(2);
  ArduinoCloud.printDebugInfo();
}

void loop() {
  ArduinoCloud.update();
  
  
  if (light < threshold) {
    digitalWrite(ledPin, HIGH);
    Serial.print(light);
    Serial.println(" TURN ON YOUR LIGHT, IT'S NEARLY NIGHT");
    ifttt_counter;
    delay(1500);
    
 }
  else {
  
   digitalWrite(ledPin, LOW);
    Serial.print(light);
    Serial.println("IT'S TO BRIGHT FOR The LIGHT");
    ifttt_counter;
    delay(1500);
    
  
  }



}





/*
  Since Light is READ_WRITE variable, onLightChange() is
  executed every time a new value is received from IoT Cloud.
*/
void onLightChange()  {
  // Add your code here to act upon Light change
}
/*
  Since Threshold is READ_WRITE variable, onThresholdChange() is
  executed every time a new value is received from IoT Cloud.
*/
void onThresholdChange()  {
  // Add your code here to act upon Threshold change
}


/*
  Since IftttCounter is READ_WRITE variable, onIftttCounterChange() is
  executed every time a new value is received from IoT Cloud.
*/
void onIftttCounterChange()  {
  // Add your code here to act upon IftttCounter change
}