/*
I2C slave demo
Demostrate the use of I@C bus
Slave receives character from Master and responds
*/
//Include arduino Wire library for i2C
#include <Wire.h>
 //Define Slave I2C Address
#define SLAVE_ADDR 9

//define slave answer size
#define ANSWERSIZE 5

//Define string with response to master
String answer = "Hello";

void setup() {
  // Initialize I2C communication as Slave
  Wire.begin(SLAVE_ADDR);

  //Function to run when data requested from master
  Wire.onRequest(requestEvent);

  //Function to run when data received from master
  Wire.onReceive(receiveEvent);

  //Setup Serial Monitor
  Serial.begin(9600);
  Serial.println("I2C Slave Demonstration");  
}

void receiveEvent() {
 //Read whle data received
 while(Wire.available()){
   char x = Wire.read();
   Serial.print(x);
   Serial.println();
}
//print t serial monitor
Serial.println("Receive Event");
}

void requestEvent() {
 //setup byte variable in the correct size
 byte response[ANSWERSIZE];

 //Format answer as array
 for(byte i=0;i<ANSWERSIZE;i++){
    response[i] = (byte)answer.charAt(i);
 }
 
 //Send response back to master
 Wire.write(response, sizeof(response));

 //print to serial monitor
 Serial.println("Request event");
}


void loop() {
  // Time Delay in loop
  delay(50);
}
