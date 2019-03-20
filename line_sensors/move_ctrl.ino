#define DELAY_IT 70
#define TURN_THR 4
#define SLOW_MODE 50
bool turning=false;
bool sturning=false;
int count_forward=0;
int count_turning=0;
int took_decision_count=0;
bool taking_decision=false;
bool off_line=true;
bool decision_done=false;
int count_off_line=0;

void get_direction(signed char x){
  // this function will decide wich direction to go
  //Serial.print(x);


  if(IR.decode(&IRresults))
  {
    if(IRresults.value==IR_ok)
    {
      if(IR_FLAG){
        IR_FLAG = false;
      }else{
        IR_FLAG = true;
      }
    }
    IRresults.value = 0;
    IR.resume();
  }

  
  if(!choosing_mode){
  switch(x){
      case 0: // special case no sensor detects the line
      //advance();
        if(!turning and !sturning) advance();
        else delay(30);
      break;
      case 1:
        if(!sturning){
          left();
          turning=true;
        }
      break;
      case 2:
        advance();
        turning=false;
        sturning=false;
      break;
      case 3:
        sharpLeft(130,130);
        turning=true;
        sturning=true;
      break;
      case 4:
        if(!sturning){
          right();
          turning=true;
        }
      break;
      case 5: // special case and big WTF
        if(!turning and !sturning){
          advance();
        }
      break;
      case 6:
        
        sharpRight(130,130);
        turning=true;
        sturning=true;
      break;
      case 7: // special case all sensor detect the line
        if(!turning and !sturning){
          advance();
        }
      break;
      default:
      break;
    }
    }else{
    switch(x){
      case 0: // special case no sensor detects the line
      //advance();
      break;
      case 1:
        if(!sturning){
          left();
          turning=true;
        }
      break;
      case 2:
        if(!taking_decision) advance();
        else{
            advance(SLOW_MODE);
        }
        count_turning=0;
        turning=false;
        sturning=false;
        off_line=false;
      break;
      case 3:
        sharpLeft(130,130);
        turning=true;
        sturning=true;
        count_turning+=1;
        if(count_turning>TURN_THR){
          taking_decision=true;
          delay(300);
          count_turning=0;
          choosing_mode=false;
        }

      break;
      case 4:
        if(!sturning){
        right();
        turning=true;
        }
      break;
      case 5: // special case and big WTF
        if(!turning and !sturning){
          advance();
        }
      break;
      case 6:
        
        sharpRight(130,130);
        turning=true;
        sturning=false;
      break;
      case 7: // special case all sensor detect the line
        sharpLeft(130,130);
        count_turning=0;
        delay(400);
        if(!off_line){
          choosing_mode=false;
        }
       
      break;
      default:
      break;
    }
    }
}
