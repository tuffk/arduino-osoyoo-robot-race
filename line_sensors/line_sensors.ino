// main file
#define MSENS A0
#define LSENS A1
#define RSENS A2
#include <Servo.h>
Servo head;
head.attach(SERVO_PIN); //servo

void setup() {
  // put your setup code here, to run once:
  pinMode(MSENS,INPUT);
  pinMode(LSENS,INPUT); 
  pinMode(RSENS,INPUT); 
  head.attach(SERVO_PIN); //servo
  Serial.begin(9600);
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
  
  get_direction(read_sensor_values()); // this reads the value of the sensor and inputs it to the direction deciding function
  do_IR_Tick();
  delay(10);
}
