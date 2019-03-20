
//Define L298N Dual H-Bridge Motor Controller Pins
#define dir1PinL  2    //Motor direction
#define dir2PinL  4    //Motor direction
#define speedPinL 6    // Needs to be a PWM pin to be able to control motor speed

#define dir1PinR  7    //Motor direction
#define dir2PinR  8   //Motor direction
#define speedPinR 5    // Needs to be a PWM pin to be able to control motor speed
#define DEF_SPEED 130 // 


void motor_move(int l1, int l2, int r1, int r2, int speedl, int speedr){
  analogWrite (speedPinR,speedr);
  analogWrite (speedPinL,speedl);
  digitalWrite(dir1PinL,l1);
  digitalWrite(dir2PinL,l2);
  digitalWrite(dir1PinR,r1);
  digitalWrite(dir2PinR,r2);
    
}
void wait(){
  motor_move(LOW,LOW,LOW,LOW,0,0);
}
void advance(int s=DEF_SPEED){
  motor_move(LOW,HIGH,LOW,HIGH,s,s);
}

void reverse(int s=DEF_SPEED){
  motor_move(HIGH,LOW,HIGH,LOW,s,s);
}
void left(int s=DEF_SPEED, int s2=60){
  motor_move(LOW,HIGH,LOW,HIGH,s2,s+30);
}
void right(int s=DEF_SPEED, int s2=60){
    motor_move(LOW,HIGH,LOW,HIGH,s+30,s2);
}
void sharpRight(int s=DEF_SPEED, int s2=DEF_SPEED){
  motor_move(HIGH,LOW,LOW,HIGH,s,s2);
}
void sharpLeft(int s=DEF_SPEED, int s2=DEF_SPEED){
  motor_move(LOW,HIGH,HIGH,LOW,s2,s);
}
void wriggle(){
  for(int i=0; i<5; i++){
   sharpRight(150,150);
   delay(200);
   sharpLeft(150,150);
   delay(200);
  }
}
void dance(){
  for(int i=0; i<4; i++){
  wriggle();
  advance(200);
  delay(1000);
  wriggle();
  advance(200);
  delay(1000);
  wait();
  delay(2000);
  }
  
}
