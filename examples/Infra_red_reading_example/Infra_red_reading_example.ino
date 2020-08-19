#include <infra_red_read.h>
#define IR_PIN A0

IR_sensor sensor(IR_PIN);

void setup() {
  Serial.begin(9600);
}

void loop() {
  Serial.print("Valor lido: ");
  Serial.println(sensor.IR_read());
  
  Serial.print("Branco: ");
  Serial.println(sensor.white_val);
  Serial.print("Valor de segurança do branco: ");
  Serial.println(sensor.white_var);
  
  Serial.print("Preto: ");
  Serial.println(sensor.black_val);
  Serial.print("Valor de segurança do preto: ");
  Serial.println(sensor.black_var);
  
  sensor.set_bw_val();
  Serial.println("----------//----------");
  delay(1500);
}
