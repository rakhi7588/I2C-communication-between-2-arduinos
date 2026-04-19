I2C Communication Demo (Arduino)

This project demonstrates simple I2C communication between two Arduino boards using the Wire library.

How it works
Master sends a character ('A') to the Slave
Slave receives it and prints it
Master then requests data
Slave responds with "Hello"
Master reads and displays the response

Connections between two Arduinos
(A4)SDA → (A4)SDA
(A5)SCL → (A5)SCL
GND → GNDs
