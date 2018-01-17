//
// Created by pilox on 11.1.18.
//
#include <Arduino.h>

#include <RCSwitch.h>
RCSwitch mySwitch = RCSwitch();
int hozdead= 500 ;
int verdead= 500 ;
int distanc= 20 ;
int data;
int val = 0;
int val2 = 0;
void setup() {
    Serial.begin(9600);
    mySwitch.enableTransmit(8);
}
void loop() {
   
    val = analogRead(2);
    val2 = analogRead(3);
   
data=10000;
  //UP 1
if (val> verdead+distanc){data=data+map(val,530,1023,0,9)*100+1000;}
//DOWN 2
if (val< verdead-distanc){data=data+map(val,490,0,0,9)*100+2000;}
//RIGHT 3
if (val2> hozdead+distanc){data=data+map(val2,530,1024,0,8)+10;}
//LEFT 4
if (val2< hozdead-distanc){data=data+map(val2,490,0,0,8)+20;}

mySwitch.send(data, 23);
}