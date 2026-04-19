/*
I2C Master Demo
Demostrates the use of I@C bus
MAster sends charater and gets reply from slave
*/

#include <Wire.h>
#define SLAVE_ADDR 9 //define slave address
#define ANSWERSIZE 5 //define answer size

void setup() {
//Initiaize I2C communication as Master
Wire.begin();
//setup serial monitor
Serial.begin(9600);
Serial.println("I2C Master Demonstration");
}
void loop(){
delay(50);
Serial.println("Write data to slave");

// Write a character to slave
Wire.beginTransmission(SLAVE_ADDR);
Wire.write('A');// write is used to send data over I2C bus
Wire.endTransmission();

Serial.println("Receive data");
//Read response frm Slave
//read back 5 characters
Wire.requestFrom(SLAVE_ADDR, ANSWERSIZE);
//Add characters to string
String response = "";
while (Wire.available()){
  char b = Wire.read();//read is used for receiving data
  response += b;
}
//print to the serial monitor
Serial.println(response);

}