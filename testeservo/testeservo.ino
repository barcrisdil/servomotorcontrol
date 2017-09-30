#include <Servo.h> //inclui a biblioteca Servo.h
Servo servo_1;
Servo servo_2;
 
int minPulse_1     =  0;   // Posição (angular) mínima do servo
int maxPulse_1     =  180; // Posição (angular) máxima do servo
int turnRate_1     =  1;  // Incremento do servo (Maior valor = maior velocidade, Menor valor = Mais precisão)
 
 
int minPulse_2     =  0;   // Posição (angular) mínima do servo
int maxPulse_2     =  180; // Posição (angular) máxima do servo
int turnRate_2     =  1;  // Incremento do servo (Maior valor = maior velocidade, Menor valor = Mais precisão)
 
int pulseWidth_1;            // Largura do Pulso do servo (PWM)
int pulseWidth_2;        // Largura do Pulso do servo (PWM)
 
void setup() {
  servo_1.attach(2); //Pino do arduino do Servo 1  (D2)
  servo_2.attach(3); //Pino do arduino do Servo 2  (D3)      
  Serial.begin(9600); // Abre conexão serial e define a taxa de transmissão em 9.600kbps  
}
void loop() {
  if (Serial.available() > 0) { // verifica serial
 
    int data = Serial.read();     // lê o byte na serial
    switch(data)
    {
    case 'a' :
      {
        pulseWidth_1 = pulseWidth_1 - turnRate_1;
        break;
      }
    case 'q' :
      {
        pulseWidth_1 = pulseWidth_1 + turnRate_1;  
        break ;
      }
    case 's' :
      {
        pulseWidth_2 = pulseWidth_2 - turnRate_2;
        break;
      }
    case 'w' :
      {
        pulseWidth_2 = pulseWidth_2 + turnRate_2;
        break ;
      }
    }      
 
    // Verifica os limites do servo 1
    if (pulseWidth_1 > maxPulse_1) {
      pulseWidth_1 = maxPulse_1;
    }
    if (pulseWidth_1 < minPulse_1) {
      pulseWidth_1 = minPulse_1;
    }
 
    // Verifica os limites do servo 2
    if (pulseWidth_2 > maxPulse_2) {
      pulseWidth_2 = maxPulse_2;
    }
    if (pulseWidth_2 < minPulse_2) {
      pulseWidth_2 = minPulse_2;
    }
 
    //envia o "comando" para os servos
    servo_1.write(pulseWidth_1);
    servo_2.write(pulseWidth_2);
 
    // imprime na serial os angulos dos servos
    Serial.print(" Servo _1: ");
    Serial.print(pulseWidth_1);
    Serial.print("- Servo _2: ");
    Serial.println(pulseWidth_2);
  }
}
