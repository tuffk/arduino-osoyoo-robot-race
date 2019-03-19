
void get_direction(signed char x){
  // this function will decide wich direction to go
  //Serial.print(x);
  switch(x){
      case 0: // special case no sensor detects the line
      advance();
      break;
      case 1:
        sharpLeft(130,130);
        delay(50);
      break;
      case 2:
        advance();
      break;
      case 3:
        left();
      break;
      case 4:
        sharpRight(130,130);
        delay(50);
      break;
      case 5: // special case and big WTF
        advance();
      break;
      case 6:
        right();
      break;
      case 7: // special case all sensor detect the line
        advance();
      break;
      default:
      break;
    }
}
