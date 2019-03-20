#include <IRremote.h>
                                                                                            
 IRrecv IR(IR_PIN);  //   IRrecv object  IR get code from IR remoter
 decode_results IRresults;   

 /***************motor control***************/

void go_Advance(void)  //Forward
{
  digitalWrite(dir1PinL, HIGH);
  digitalWrite(dir2PinL,LOW);
  digitalWrite(dir1PinR,HIGH);
  digitalWrite(dir2PinR,LOW);
  analogWrite(speedPinL,SPEED);
  analogWrite(speedPinR,SPEED);
}
void go_Left()  //Turn left
{
  digitalWrite(dir1PinL, HIGH);
  digitalWrite(dir2PinL,LOW);
  digitalWrite(dir1PinR,LOW);
  digitalWrite(dir2PinR,HIGH);
  analogWrite(speedPinL,SPEED);
  analogWrite(speedPinR,SPEED);
}
void go_Right(int t=0)  //Turn right
{
  digitalWrite(dir1PinL, LOW);
  digitalWrite(dir2PinL,HIGH);
  digitalWrite(dir1PinR,HIGH);
  digitalWrite(dir2PinR,LOW);
  analogWrite(speedPinL,SPEED);
  analogWrite(speedPinR,SPEED);
 
}
void go_Back(int t=0)  //Reverse
{
  digitalWrite(dir1PinL, LOW);
  digitalWrite(dir2PinL,HIGH);
  digitalWrite(dir1PinR,LOW);
  digitalWrite(dir2PinR,HIGH);
  analogWrite(speedPinL,SPEED);
  analogWrite(speedPinR,SPEED);
 
}
void stop_Stop()    //Stop
{
  digitalWrite(dir1PinL, LOW);
  digitalWrite(dir2PinL,LOW);
  digitalWrite(dir1PinR,LOW);
  digitalWrite(dir2PinR,LOW);
}
void open_Clamp()    //Opens clamp 
{
  head.write(90); //use 90 degrees if you are moving your servo through the whole 180 degrees
}
void close_Clamp()    //Closes clamp 
{
  head.write(0);
}
void movement()
{
      delay(DelayTime);
       stop_Stop();
}

/**************detect IR code***************/
void do_IR_Tick()
{
  if(IR.decode(&IRresults))
  {
    if(IRresults.value==IR_ADVANCE)
    {
      go_Advance();
    movement();
    }
    else if(IRresults.value==IR_RIGHT)
    {
       go_Right();
    movement();
 
    }
    else if(IRresults.value==IR_LEFT)
    {
       go_Left();
    movement();
    }
    else if(IRresults.value==IR_BACK)
    {
         go_Back();
    movement();
    }
    else if(IRresults.value==IR_STOP)
    {
        stop_Stop();
    }
    else if(IRresults.value==IR_open_clamp)
    {
        stop_Stop();
    }
    else if(IRresults.value==IR_close_clamp)
    {
        stop_Stop();
    }
    IRresults.value = 0;
    IR.resume();
  }
}
