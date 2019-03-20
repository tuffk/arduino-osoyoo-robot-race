// main file
#define MSENS A0
#define LSENS A1
#define RSENS A2
#include <Servo.h>
#include "configuration.h"
#include <IRremote.h>
IRrecv IR(IR_PIN);
decode_results IRresults; 

Servo head;

bool PUTO = true;
bool choosing_mode=false;

void setup() {
  // put your setup code here, to run once:
  pinMode(MSENS,INPUT);
  pinMode(LSENS,INPUT); 
  pinMode(RSENS,INPUT);
  pinMode(dir1PinL, OUTPUT);
  pinMode(dir2PinL, OUTPUT);
  pinMode(speedPinL, OUTPUT);
  pinMode(dir1PinR, OUTPUT);
  pinMode(dir2PinR, OUTPUT);
  pinMode(speedPinR, OUTPUT);
  head.attach(SERVO_PIN); //servo
  
  pinMode(IR_PIN, INPUT);
  digitalWrite(IR_PIN, HIGH);
  IR.enableIRIn();
 
}



int read_sensor_values()
{
  signed char light_snesors = 0;
  /*
  sensor[0]=digitalRead(MSENS);
  sensor[1]=digitalRead(LSENS);
  sensor[2]=digitalRead(RSENS);
  */
  light_snesors += (digitalRead(MSENS)) << 1;
  light_snesors += (digitalRead(LSENS)) << 0;
  light_snesors += (digitalRead(RSENS)) << 2;
  return light_snesors;
}


void loop() {
  // put your main code here, to run repeatedly:
  if(PUTO)
  {
    get_direction(read_sensor_values()); // this reads the value of the sensor and inputs it to the direction deciding function
  }else{
    do_IR_Tick();
  }
  delay(10);
}
