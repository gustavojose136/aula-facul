#define PININ1 2
#define PININ2 4
#define PININ3 5
#define PININ4 7
#define PINENA 3
#define PINENB 6

#define TRESHOLD 750                       
#define BASESPD 155

#define SPEED0 255  //0 0 (X X) 0 0

#define SPEED2 205  //0 0 X | X 0 0                  
#define SPEED3 170  //0 X X | X X 0

#define SPEED5 100  //0 X 0 | 0 X 0
#define SPEED6 80  //X X 0 | 0 X X
#define SPEED7 180  //X 0 0 | 0 0 X

#define RUNTIME 13000                     

#define Kp 8
#define Kd 3

void setup() {
  pinMode(PININ1, OUTPUT);
  pinMode(PININ2, OUTPUT);
  pinMode(PININ3, OUTPUT);
  pinMode(PININ4, OUTPUT);
  pinMode(PINENA, OUTPUT);
  pinMode(PINENB, OUTPUT);
}

void loop() {
  PIDmath();
}

void motorControl(int speedLeft, int speedRight) {
  if (speedLeft < 0) {
    speedLeft = -speedLeft;
    digitalWrite (PININ3, HIGH);
    digitalWrite (PININ4, LOW);
  } else {
    digitalWrite (PININ3, LOW);
    digitalWrite (PININ4, HIGH);
  }

  if (speedRight < 0) {
    speedRight = -speedRight;
    digitalWrite (PININ1, LOW);
    digitalWrite (PININ2, HIGH);
  } else {
    digitalWrite (PININ1, HIGH);
    digitalWrite (PININ2, LOW);
  }

  analogWrite (PINENA, speedLeft);
  analogWrite (PINENB, speedRight);
}

int speedLeft; 
int speedRight; 
int erro;

void PIDmath(){
  int ulterro = 0;
  
  int PIDvalue = (Kp * erro) + (Kd * (erro - ulterro));
  float position = followLineMEF();
  erro = 3500-position;
  
  speedLeft  = BASESPD + speedLeft + PIDvalue;
  speedRight = BASESPD + speedRight + PIDvalue;

  if (speedLeft > 255) {
    speedLeft = 255;
  }
  if (speedRight > 255) {
    speedRight = 255;
  }
  if (speedLeft < 0) {
    speedLeft = 0;
  }
  if (speedRight < 0) {
    speedRight = 0;
  } 

}

void motorOption(char option, int speedLeft, int speedRight) {
  switch (option) {
    case '6': // Esquerda
      motorControl(-speedLeft, speedRight);
      break;
    case '4': // Direita
      motorControl(speedLeft, -speedRight);
      break;
    case '2': // Trás
      motorControl(-speedLeft, -speedRight);
      break;
    case '8': // Frente
      motorControl(speedLeft, speedRight);
      break;
    case '0': // Parar
      motorControl(0, 0);
      break;
  }
}

bool motorStop(long runtime, long currentTime) {
  if (millis() >= (runtime + currentTime)) {
    motorOption('0', 0, 0);
    int cont = 0;
    while (true) {
      cont++;
    }
    return false;
  }
  return true;
}

float followLineMEF(void) {
  bool flag = true;
  long currentTime = millis();
  int erro = 0;

  while (flag) {
    flag = motorStop(RUNTIME, currentTime);

    //(0 0 0 0 0 1)
    if      (analogRead(A0) >= TRESHOLD && analogRead(A1) >= TRESHOLD && analogRead(A2) >= TRESHOLD && analogRead(A3) >= TRESHOLD && analogRead(A4) >= TRESHOLD && analogRead(A5) <= TRESHOLD) {
      motorOption('4', SPEED7, SPEED7, erro);
      erro =  11;
    }
    //(0 0 0 0 1 1)
    else if (analogRead(A0) >= TRESHOLD && analogRead(A1) >= TRESHOLD && analogRead(A2) >= TRESHOLD && analogRead(A3) >= TRESHOLD && analogRead(A4) <= TRESHOLD && analogRead(A5) <= TRESHOLD) {
      motorOption('8', SPEED6, SPEED0, erro);
    } erro =  10;
    //(0 0 0 0 1 0)
    else if (analogRead(A0) >= TRESHOLD && analogRead(A1) >= TRESHOLD && analogRead(A2) >= TRESHOLD && analogRead(A3) >= TRESHOLD && analogRead(A4) <= TRESHOLD && analogRead(A5) >= TRESHOLD) {
      motorOption('8', SPEED5, SPEED0, erro);
      erro =  9;
    }
    //(0 0 0 1 1 0)
    else if (analogRead(A0) >= TRESHOLD && analogRead(A1) >= TRESHOLD && analogRead(A2) >= TRESHOLD && analogRead(A3) <= TRESHOLD && analogRead(A4) <= TRESHOLD && analogRead(A5) >= TRESHOLD) {
     
      motorOption('8', SPEED3, SPEED0, erro);
      erro =  8;
    }
    //(0 0 0 1 0 0)
    else if (analogRead(A0) >= TRESHOLD && analogRead(A1) >= TRESHOLD && analogRead(A2) >= TRESHOLD && analogRead(A3) <= TRESHOLD && analogRead(A4) >= TRESHOLD && analogRead(A5) >= TRESHOLD) {
      motorOption('8', SPEED2, SPEED0, erro);
    } erro =  7;
    //(0 0 1 1 0 0)
    else if (analogRead(A0) >= TRESHOLD && analogRead(A1) >= TRESHOLD && analogRead(A2) <= TRESHOLD && analogRead(A3) <= TRESHOLD && analogRead(A4) >= TRESHOLD && analogRead(A5) >= TRESHOLD) {
      
      motorOption('8', SPEED0, SPEED0, erro);
      erro =  0;
    }
    //(0 0 1 0 0 0)
    else if (analogRead(A0) >= TRESHOLD && analogRead(A1) >= TRESHOLD && analogRead(A2) <= TRESHOLD && analogRead(A3) >= TRESHOLD && analogRead(A4) >= TRESHOLD && analogRead(A5) >= TRESHOLD) {

      motorOption('8', SPEED0, SPEED2, erro);
      erro =  -7;
    }
    //(0 1 1 0 0 0)
    else if (analogRead(A0) >= TRESHOLD && analogRead(A1) <= TRESHOLD && analogRead(A2) <= TRESHOLD && analogRead(A3) >= TRESHOLD && analogRead(A4) >= TRESHOLD && analogRead(A5) >= TRESHOLD) {
      
      motorOption('8', SPEED0, SPEED3, erro);
      erro =  -8;
    }
    //(0 1 0 0 0 0)
    else if (analogRead(A0) >= TRESHOLD && analogRead(A1) <= TRESHOLD && analogRead(A2) >= TRESHOLD && analogRead(A3) >= TRESHOLD && analogRead(A4) >= TRESHOLD && analogRead(A5) >= TRESHOLD) {

      motorOption('8', SPEED0, SPEED5, erro);
      erro =  -9;
    }
    //(1 1 0 0 0 0)
    else if (analogRead(A0) <= TRESHOLD && analogRead(A1) <= TRESHOLD && analogRead(A2) >= TRESHOLD && analogRead(A3) >= TRESHOLD && analogRead(A4) >= TRESHOLD && analogRead(A5) >= TRESHOLD) {
      
      motorOption('8', SPEED0, SPEED6, erro);
      erro =  -10;
    }
    //(1 0 0 0 0 0)
    else if (analogRead(A0) <= TRESHOLD && analogRead(A1) >= TRESHOLD && analogRead(A2) >= TRESHOLD && analogRead(A3) >= TRESHOLD && analogRead(A4) >= TRESHOLD && analogRead(A5) >= TRESHOLD) {

      motorOption('6', SPEED7, SPEED7, erro);
      erro =  -11;
    }
  }
}
