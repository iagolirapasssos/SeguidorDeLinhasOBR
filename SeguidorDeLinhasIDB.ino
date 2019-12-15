/*
 * kP -- const. proporcional
 * kI -- const. Integral
 * kD -- const. derivada
 * mediaS -- media dos sensores de referencial
 */
int IRO()
{
  int O1 = analogRead(IRO1);
  int O2 = analogRead(IRO2);
  int O3 = analogRead(IRO3);

  return (O1 + O2 + O3);
}

int IRLinha()
{
 int x1 = analogRead(IRL1);
 int x2 = analogRead(IRL2);
 
 return (x1 + x2);  
}

void motorPWM(int x1, int x2)
{
  Serial.print("Olá");
  if (x1 > 0) {
    analogWrite(MotorEsquerdoFrente, x1);
    analogWrite(MotorEsquerdoTras, 0);
  }
  else if (x1 == 0) {
    analogWrite(MotorEsquerdoFrente, 0);
    analogWrite(MotorEsquerdoTras, 0);
  }
  else {
    analogWrite(MotorEsquerdoFrente, 0);
    analogWrite(MotorEsquerdoTras, abs(x1));
  }
  
  if (x2 > 0) {
    analogWrite(MotorDireitoFrente, x2);
    analogWrite(MotorDireitoTras, 0);
  }
  else if (x2 == 0) {
    analogWrite(MotorDireitoFrente, 0);
    analogWrite(MotorDireitoTras, 0);
  }
  else {
    analogWrite(MotorDireitoFrente, 0);
    analogWrite(MotorDireitoTras, abs(x2));
  }
}

void PID(double kp, double kI,, double kI, double PWM, double mediaS)
}
  double erro = lerSensores - mediaS;
  double lastErro, PID, P, I, D;
  int motor1, motor2;

  P = erro*kP;
  I = I + erro*kI;
  D = erro*(erro - lastErro);

  PID = P + I + D;

  lastErro = erro;

  motor1 = PWM + PID;
  motor2 = PWM - PID;

  motorPWM(motor1, motor2);
}
