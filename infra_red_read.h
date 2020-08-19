/*
  infra_red_read.h

  Author: jptrindade3
  April de 2019

  Descrição: A ideia dessa biblioteca é ser capaz de utilizar um sensor infravermelho para poder fazer a leitura de seus resultados e definí-los como preto ou branco nesse caso específico.
*/

#ifndef infra_red_read
#define infra_red_read

#include <Arduino.h>

class IR_sensor
{
  public:
    IR_sensor(char pin);
    int IR_read(); /*Reading sensor function*/
    void set_bw_val();/*Define black and white values*/
    int white_val = 0;/*Stores white value*/
    int black_val = 0;/*Stores black value*/
    int white_var = 0;/*Stores white value with a margin of error*/
    int black_var = 0;/*Stores black value with a margin of error*/
    
  private:
    char _pin;
};

#endif
