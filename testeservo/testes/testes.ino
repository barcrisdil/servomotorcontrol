#include <VarSpeedServo.h>
VarSpeedServo servo_base;           //Cria objeto para controlar o servo base
VarSpeedServo servo_inclinacao;     //Cria objeto para controlar o servo inclinacao
 
int pino_x = A4;      //Pino ligado ao X do joystick
int pino_y = A5;      //Pino ligado ao Y do joystick
int val_x;            //Armazena o valor do eixo X
int val_y;            //Armazena o valor do eixo Y
int spd_x;            //Velocidade do eixo x;
int spd_y;            //Velocidade do eixo y;
 
void setup()
{
  
  servo_base.attach(7, 1, 180);          //Define a porta a ser ligada ao servo base
  servo_inclinacao.attach(8, 1, 180);    //Define a porta a ser ligada ao servo inclinacao
  Serial.begin(9600);
  servo_base.write(90);
  servo_inclinacao.write(90);
  
}
void loop() {
  servo_base.write(90);
  servo_inclinacao.write(90);

}
