#include "control.h"

void setup()
{
  Serial.begin(9600);
  
  pinMode(M1D, OUTPUT);
  pinMode(M1U, OUTPUT);
  pinMode(M2D, OUTPUT);
  pinMode(M2U, OUTPUT);
  
  //Portas IRO
//  pinMode(IRO1, INPUT);
//  pinMode(IRO2, INPUT);
//  pinMode(IRO3, INPUT);
  
  //Portas IRLinhas
  //pinMode(IRL1, OUTPUT);
  //pinMode(IRL2, OUTPUT);
}

void loop()
{
  //PID(double kp, double kI,, double kI, double PWM, double mediaS)
   PID(0.39, 0.0, 0.0, 50, 44);
  //PWM(60, 60);
  //Serial.println((int)((analogRead(IRL1)+analogRead(IRL2))/2));
}
