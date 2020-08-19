#include "infra_red_read.h"


/*
    -----// IR_sensor::IR_sensor(char pin) //-----

  This part is responsible for setting the sensor input pin.
  It'll get as parameter the number or the name of the pin used 
  as input and will set it as an input for arduino. It saves the
  pin name as a private info of the object too.

*/
IR_sensor::IR_sensor(char pin){
  
  pinMode(pin, INPUT);
  _pin = pin;
}
/*-----//--------------------//-------------------//-----*/



/*
    -----// function int IR_sensor::IR_read() //-----
    
  This funcion is responsible for reading the value readed by the
  infra-red sensor. It uses the private name of the pin to know
  which pin should be readed and returns the readed value of the
  sensor
  
*/
int IR_sensor::IR_read(){
  
  return analogRead(_pin);
}
/*-----//--------------------//-------------------//-----*/



/*
    -----// function void IR_sensor::set_bw_val //-----

  This function will set the black and white values of the line
  follower. Frist, it'll use the function IR_read() to get the vlue
  from the sensor and, if its the first read of that sensor, that
  value will be saved as black and white. In a loop, lots of values
  will be founded and, the highest ones will be considered as black and 
  the lowest will be white. This numbers are stored in the IR_sensor::black_val
  and IR_sensor::white_val variables and inside the IR_sensor::black_var and 
  IR_sensor::white_var variables black and white values will be slightly 
  alterated as an margin of error. 
*/
void IR_sensor::set_bw_val(){
  
  int readed = IR_sensor::IR_read();
  int whiteVal = IR_sensor::white_val;
  int blackVal = IR_sensor::black_val;
  int whiteVar = IR_sensor::white_var;
  int blackVar = IR_sensor::black_var;
  
  if(whiteVal == 0 && blackVal == 0){
    IR_sensor::white_val = readed;
    IR_sensor::black_val = readed;  
  }

  else{
    if(readed > blackVal){
      IR_sensor::black_val = readed;
      IR_sensor::black_var = IR_sensor::black_val - 10;
    }
    
    if(readed < whiteVal){
      IR_sensor::white_val = readed;
      IR_sensor::white_var = IR_sensor::white_val + 10;
    }
  } 
}
/*-----//--------------------//-------------------//-----*/
