//Programa : Controle servo motor com joystick
//Autor : Bárbara e  Luiz

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
 
void loop()
{


  val_x = analogRead(pino_x);           //Recebe o valor do joystick, eixo X
  val_x = map(val_x, 0, 1023, 1, 180);  //Converte o valor lido para um valor entre 1 e 180 graus
  spd_x = val_x;                        //Velocidade age de acordo com a posição no eixo
  
  val_y = analogRead(pino_y);           //Recebe o valor do joystick, eixo Y
  val_y = map(val_y, 0, 1023, 1, 180);  //Converte o valor lido para um valor entre 1 e 180 graus
  spd_y = val_y;                        //Velocidade age de acordo com a posição no eixo

  if (val_x < 90)
  {
      spd_x = map (spd_x, 1, 90, 50, 150);
      servo_base.slowmove(val_x, spd_x);           //Move o servo base para a posicao definida pelo joystick
  }
  else if (val_x > 90)
  {
      spd_x = map (spd_x, 91, 180, 50, 150);    
      servo_base.slowmove(val_x, spd_x);         //Move o servo base para a posicao definida pelo joystick
  }

  if (val_y <90)
  {
      spd_y = map (spd_y, 1, 90, 50, 150);
      servo_inclinacao.slowmove(val_y, spd_y);  //Move o servo inclinacao para a posicao definida pelo joystick
  }
  else if (val_y > 90)
  {
      spd_y = map (spd_y, 91, 180, 50, 150);
      servo_inclinacao.slowmove(val_y, spd_y);  //Move o servo inclinacao para a posicao definida pelo joystick
  }

  Serial.print("Eixo x: \n");
  Serial.print(val_x);
  Serial.print("Eixo y: \n");
  Serial.print(val_y);
  
  delay(30);                                 //Aguarda a movimentacao do servo e reinicia a leitura

}
