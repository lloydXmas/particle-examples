#include "application.h"

/*
After cloud synchonization

Mon Jul 20 06:27:47 2015
Mon Jul 20 06:27:47 2015
Mon Jul 20 06:27:47 2015
Mon Jul 20 06:27:48 2015
Mon Jul 20 06:27:48 2015
Mon Jul 20 06:27:48 2015
Mon Jul 20 06:27:48 2015
Mon Jul 20 06:27:48 2015
Mon Jul 20 06:27:49 2015
Mon Jul 20 06:27:49 2015

USB power supply removed
Powering on after some Time

Mon Jul 20 06:52:57 2015
Mon Jul 20 06:52:58 2015
Mon Jul 20 06:52:58 2015
Mon Jul 20 06:52:58 2015
Mon Jul 20 06:52:58 2015
Mon Jul 20 06:52:58 2015
Mon Jul 20 06:52:59 2015
Mon Jul 20 06:52:59 2015
Mon Jul 20 06:52:59 2015
*/
SYSTEM_MODE(MANUAL);

#define wifiButton (D0)

void setup(){
  pinMode(D7,OUTPUT);
  pinMode(wifiButton,INPUT_PULLDOWN); //<--- Any GPIO pin works fine too
  Serial.begin(9600);
  delay(1000);
  if(digitalRead(wifiButton) == HIGH){
    Spark.connect();
    Spark.syncTime();
  }
}

void loop(){
  digitalWrite(D7,!digitalRead(D7));
  Serial.println(Time.timeStr());
  delay(200);
}
