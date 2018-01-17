//
// Created by pilox on 12.1.18.
//

#include <Arduino.h>
#include <RCSwitch.h>
#include <Servo.h>
RCSwitch mySwitch = RCSwitch();
int pos = 0;
int value;
/*
int leds[]={4,5,8,9};
int ledsState[]={0,0,0,0};
*/

Servo myservo;

void setup() {
    myservo.attach(9);
    Serial.begin(9600);
    myservo.write(90);
   
/*
    for (int i = 0; i < 4; ++i) {
        pinMode(leds[i],OUTPUT);
    }
*/
    mySwitch.enableReceive(0);
}
void loop() {
//Serial.println("jedna");
    if (mySwitch.available()) {
  //Serial.println("dva");
        value = mySwitch.getReceivedValue();
        
        if (value > 0) {
            //long data = mySwitch.getReceivedValue();
            Serial.println(value);
          //  myservo.write(((String(value)).substring(4)).toInt()*10+90);
/*
            switch (data) {
                case 1:

                    ledsState[0]={1};
                    ledsState[1]={0};
                    ledsState[2]={0};
                    ledsState[3]={0};
                    break;
                case 2:

                    ledsState[0]={0};
                    ledsState[1]={1};
                    ledsState[2]={0};
                    ledsState[3]={0};
                    break;
                case 4:

                    ledsState[0]={0};
                    ledsState[1]={0};
                    ledsState[2]={1};
                    ledsState[3]={0};
                    break;
                case 5:

                    ledsState[0]={1};
                    ledsState[1]={0};
                    ledsState[2]={1};
                    ledsState[3]={0};
                    break;
                case 6:

                    ledsState[0]={0};
                    ledsState[1]={1};
                    ledsState[2]={1};
                    ledsState[3]={0};
                    break;
                case 8:

                    ledsState[0]={0};
                    ledsState[1]={0};
                    ledsState[2]={0};
                    ledsState[3]={1};
                    break;
                case 9:

                    ledsState[0]={1};
                    ledsState[1]={0};
                    ledsState[2]={0};
                    ledsState[3]={1};
                    break;
                case 10:

                    ledsState[0]={0};
                    ledsState[1]={1};
                    ledsState[2]={0};
                    ledsState[3]={1};
                    break;
                default:

                    ledsState[0]={0};
                    ledsState[1]={0};
                    ledsState[2]={0};
                    ledsState[3]={0};
            }

            for (int i = 0; i < 4; ++i) {
                digitalWrite(leds[i],ledsState[i]);

            }
*/
        }
        mySwitch.resetAvailable();


    }
}