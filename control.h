/*
 * kP -- const. proporcional
 * kI -- const. Integral
 * kD -- const. derivada
 * mediaS -- media dos sensores de referencial
 * 
 */
//Portas IRLinhas
#define IRL1 A0 //Direita
#define IRL2 A1 //Esquerda

//Portas ponte H
#define M1D 11
#define M1U 10
#define M2D 6
#define M2U 5

//Portas IR obstáculo
//#define IRO1
//#define IRO2
//#define IRO3

//Constantes
int mediaS = 100;

//void lerSensoresObstaculo()
//{
//  int O1 = analogRead(IRO1);
//  int O2 = analogRead(IRO2);
//  int O3 = analogRead(IRO3);
//}

int lerSensorLinha()
{
 int x1 = analogRead(IRL1);
 int x2 = analogRead(IRL2);
 
 return (x1 + x2)/2;  
}


void PWM(int x1, int x2)
{
   // MOTOR ESQUERDO
  // motor esquerdo para frente
  if (x1 > 0) {
    analogWrite(M2U, x1);
    analogWrite(M2D, 0);
    
  }
  // motor esquerdo "travado"
  else if (x1 == 0) {
    analogWrite(M2U, 0);
    analogWrite(M2D, 0);
  }
  // Motor esquerdo para tras
  else {
    analogWrite(M2U, 0);
    analogWrite(M2D, abs(x1));
  }


  // MOTOR DIREITO
  if (x2 > 0) {
    analogWrite(M1U, x2);
    analogWrite(M1D, 0);
  }
  else if (x2 == 0) {
    analogWrite(M1U, 0);
    analogWrite(M1D, 0);
  }
  else {
    analogWrite(M1U, 0);
    analogWrite(M1D, abs(x2));
  }
}


void PID(float kP, float kI, float kD, int PWM2, int mediaS)
{
  float erro = (float)lerSensorLinha() - (float)mediaS;
  float lastErro, PID2, P, I, D;
  int motor1, motor2;

  P = erro*kP;
  I = I + (erro*kI);
  D = kD*(erro - lastErro);

  PID2 = P + I + D;

  lastErro = erro;

  motor1 = PWM2 + (int)PID2;
  motor2 = PWM2 - (int)PID2;

  PWM(motor1, motor2);
}
