#define DELAY_IT 70
bool turning=false;
bool sturning=false;
void get_direction(signed char x){
  // this function will decide wich direction to go
  //Serial.print(x);
  switch(x){
      case 0: // special case no sensor detects the line
      //advance();
      break;
      case 1:
        left();
        turning=true;
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
        if(!turning){
          advance();
        }
      break;
      case 6:
        
        sharpRight(130,130);
        turning=true;
        sturning=false;
      break;
      case 7: // special case all sensor detect the line
        advance();
      break;
      default:
      break;
    }
}
