#include <QTRSensors.h>
QTRSensors qtr;
// Portas driver motor
#define PININ1 2
#define PININ2 4
#define PININ3 5
#define PININ4 7
#define PINENA 3
#define PINENB 6

// Portas sensor QTR
#define SENSOR1 A0
#define SENSOR2 A1
#define SENSOR3 A2
#define SENSOR4 A3
#define SENSOR5 A4
#define SENSOR6 A5

// Valores de ajustes para o seguidor de linha MIF
#define TRESHOLD 750                       // Valor de referencia para cor da linha branca
#define SPEED0 240                          // Valor de 0 a 255 para velocidade com a seguinte leitura do sensor (0 0 1 1 0 0) 
#define SPEED1 200                          // Valor de 0 a 255 para velocidade com a seguinte leitura do sensor (0 0 1 1 1 0) 

#define SPEED2 180                          // Valor de 0 a 255 para velocidade com a seguinte leitura do sensor (0 0 0 1 0 0) 
#define SPEED3 150                          // Valor de 0 a 255 para velocidade com a seguinte leitura do sensor (0 0 0 1 1 0)  
#define SPEED4 100                          // Valor de 0 a 255 para velocidade com a seguinte leitura do sensor (0 0 0 1 1 1) 

#define SPEED5 0                            // Valor de 0 a 255 para velocidade com a seguinte leitura do sensor (0 0 0 0 1 0) 
#define SPEED6 0                            // Valor de 0 a 255 para velocidade com a seguinte leitura do sensor (0 0 0 0 1 1) 
#define SPEED7 120                          // Valor de 0 a 255 para velocidade com a seguinte leitura do sensor (0 0 0 0 0 1) 

#define RUNTIME 18500                      // Valor para executar o percurso 

const uint8_t SensorCount = 8;
uint16_t sensorValues[SensorCount];

float Kp = 2; 
float Ki = 0;
float Kd = 1;
int P;
int I;
int D;

int totalError = 0;
int lastError = 0;
boolean onoff = false;

const uint8_t maxspeeda = 255;
const uint8_t maxspeedb = 255;
const uint8_t basespeeda = 150;
const uint8_t basespeedb = 150;

int mode = 8;
int aphase = 9;
int aenbl = 6;
int bphase = 5;
int benbl = 3;

int buttoncalibrate = 17;
int buttonstart = 2;

void calibration(){
  digitalWrite(LED_BUILTIN, HIGH);
  for (uint16_t i = 0; i < 400; i++)
  {
    qtr.calibrate();
  }
  digitalWrite(LED_BUILTIN, LOW);
}

void setup() {
  Serial.begin(9600);
  qtr.setTypeRC();
  qtr.setSensorPins((const uint8_t[]){10, 11, 12, 14, 15, 16, 18, 19}, SensorCount);
  qtr.setEmitterPin(7);//LEDON PIN

  pinMode(mode, OUTPUT);
  pinMode(aphase, OUTPUT);
  pinMode(aenbl, OUTPUT);
  pinMode(bphase, OUTPUT);
  pinMode(benbl, OUTPUT);
  digitalWrite(mode, HIGH);

  delay(500);
  pinMode(LED_BUILTIN, OUTPUT);

  boolean Ok = false;
  while (Ok == false) { //the loop won't start until the robot is calibrated
    if(digitalRead(buttoncalibrate) == HIGH) {
      calibration(); 
      Ok = true;
    }
  }
  forward_brake(0, 0);
}
  




void loop() {
  followLineMEF();
  if(digitalRead(buttonstart) == HIGH) {
    onoff =! onoff;
    if(onoff = true) {
      delay(1000);//a delay when the robot starts
    }
    else {
      delay(50);
    }
  }
  if (onoff == true) {
    PID_control();
  }
  else {
    forward_brake(0,0);
  }
}


void motorControl(int speedLeft, int speedRight) {
  // Função para controle do driver de motor

  // Definições das portas digitais
  pinMode(PININ1, OUTPUT);
  pinMode(PININ2, OUTPUT);
  pinMode(PININ3, OUTPUT);
  pinMode(PININ4, OUTPUT);
  pinMode(PINENA, OUTPUT);
  pinMode(PINENB, OUTPUT);

  // Ajustes motor da esquerda
  if (speedLeft < 0) {
    speedLeft = -speedLeft;
    digitalWrite (PININ3, HIGH);
    digitalWrite (PININ4, LOW);
  } else {
    digitalWrite (PININ3, LOW);
    digitalWrite (PININ4, HIGH);
  }

  // Ajustes motor da direita
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

void motorOption(char option, int speedLeft, int speedRight) {
  // Função para controle de motor com pre definições
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
  // Função de parada do robô
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

void readSensors(void) {
  // Função para leitura dos sensores
  Serial.print(analogRead(A0));
  Serial.print(' ');
  Serial.print(analogRead(A1));
  Serial.print(' ');
  Serial.print(analogRead(A2));
  Serial.print(' ');
  Serial.print(analogRead(A3));
  Serial.print(' ');
  Serial.print(analogRead(A4));
  Serial.print(' ');
  Serial.println(analogRead(A5));
  Serial.print(' ');
}

void followLineMEF(void) {
  // Função para controle do seguidor de linha em modo de maquina de estado finita
  bool flag = true;
  long currentTime = millis();

  while (flag) {
    flag = motorStop(RUNTIME, currentTime);

    // leitura do sensor (1 1 1 1 1 1)
    if (analogRead(A0) <= TRESHOLD && analogRead(A1) <= TRESHOLD && analogRead(A2) <= TRESHOLD && analogRead(A3) <= TRESHOLD && analogRead(A4) <= TRESHOLD && analogRead(A5) <= TRESHOLD) {
      motorOption('8', SPEED0, SPEED0);
      // leitura do sensor (0 1 1 1 1 0)
    } else if ( analogRead(A0) >= TRESHOLD && analogRead(A1) <= TRESHOLD && analogRead(A2) <= TRESHOLD && analogRead(A3) <= TRESHOLD && analogRead(A4) <= TRESHOLD && analogRead(A5) >= TRESHOLD) {
      motorOption('8', SPEED0, SPEED0);
      // leitura do sensor (0 0 1 1 0 0)
    } else if ( analogRead(A0) >= TRESHOLD && analogRead(A1) >= TRESHOLD && analogRead(A2) <= TRESHOLD && analogRead(A3) <= TRESHOLD && analogRead(A4) >= TRESHOLD && analogRead(A5) >= TRESHOLD) {
      motorOption('8', SPEED0, SPEED0);

      // leitura do sensor (0 1 1 1 0 0)
    } else if (analogRead(A0) >= TRESHOLD && analogRead(A1) <= TRESHOLD && analogRead(A2) <= TRESHOLD && analogRead(A3) <= TRESHOLD && analogRead(A4) >= TRESHOLD && analogRead(A5) >= TRESHOLD) {
      motorOption('8', SPEED0, SPEED1);

      // leitura do sensor (0 0 1 1 1 0)
    } else if (analogRead(A0) >= TRESHOLD && analogRead(A1) >= TRESHOLD && analogRead(A2) <= TRESHOLD && analogRead(A3) <= TRESHOLD && analogRead(A4) <= TRESHOLD && analogRead(A5) >= TRESHOLD ) {
      motorOption('8', SPEED1, SPEED0);

      // leitura do sensor (0 0 1 0 0 0)
    } else if (analogRead(A0) >= TRESHOLD && analogRead(A1) >= TRESHOLD && analogRead(A2) <= TRESHOLD && analogRead(A3) >= TRESHOLD && analogRead(A4) >= TRESHOLD && analogRead(A5) >= TRESHOLD) {
      motorOption('8', SPEED0, SPEED2);
      // leitura do sensor (0 0 0 1 0 0)
    } else if (analogRead(A0) >= TRESHOLD && analogRead(A1) >= TRESHOLD && analogRead(A2) >= TRESHOLD && analogRead(A3) <= TRESHOLD && analogRead(A4) >= TRESHOLD && analogRead(A5) >= TRESHOLD ) {
      motorOption('8', SPEED2, SPEED0);

      // leitura do sensor (0 1 1 0 0 0)
    } else if (analogRead(A0) >= TRESHOLD && analogRead(A1) <= TRESHOLD && analogRead(A2) <= TRESHOLD && analogRead(A3) >= TRESHOLD && analogRead(A4) >= TRESHOLD && analogRead(A5) >= TRESHOLD) {
      motorOption('8', SPEED0, SPEED3);

      // leitura do sensor (0 0 0 1 1 0)
    } else if (analogRead(A0) >= TRESHOLD && analogRead(A1) >= TRESHOLD && analogRead(A2) >= TRESHOLD && analogRead(A3) <= TRESHOLD && analogRead(A4) <= TRESHOLD && analogRead(A5) >= TRESHOLD) {
      motorOption('8', SPEED3, SPEED0);

      // leitura do sensor (1 1 1 0 0 0)
    } else if (analogRead(A0) <= TRESHOLD && analogRead(A1) <= TRESHOLD && analogRead(A2) <= TRESHOLD && analogRead(A3) >= TRESHOLD && analogRead(A4) >= TRESHOLD && analogRead(A5) >= TRESHOLD) {
      motorOption('8', SPEED0, SPEED4);
      // leitura do sensor (0 0 0 1 1 1)
    } else if (analogRead(A0) >= TRESHOLD && analogRead(A1) >= TRESHOLD && analogRead(A2) >= TRESHOLD && analogRead(A3) <= TRESHOLD && analogRead(A4) <= TRESHOLD && analogRead(A5) <= TRESHOLD) {
      motorOption('8', SPEED4, SPEED0);

      // leitura do sensor (0 1 0 0 0 0)
    } else if (analogRead(A0) >= TRESHOLD && analogRead(A1) <= TRESHOLD && analogRead(A2) >= TRESHOLD && analogRead(A3) >= TRESHOLD && analogRead(A4) >= TRESHOLD && analogRead(A5) >= TRESHOLD) {
      motorOption('8', SPEED0, SPEED5);

      // leitura do sensor (0 0 0 0 1 0)
    } else if (analogRead(A0) >= TRESHOLD && analogRead(A1) >= TRESHOLD && analogRead(A2) >= TRESHOLD && analogRead(A3) >= TRESHOLD && analogRead(A4) <= TRESHOLD && analogRead(A5) >= TRESHOLD) {
      motorOption('8', SPEED5, SPEED0);

      // leitura do sensor (1 1 0 0 0 0)
    } else if (analogRead(A0) <= TRESHOLD && analogRead(A1) <= TRESHOLD && analogRead(A2) >= TRESHOLD && analogRead(A3) >= TRESHOLD && analogRead(A4) >= TRESHOLD && analogRead(A5) >= TRESHOLD) {
      motorOption('8', SPEED0, SPEED6);

      // leitura do sensor (0 0 0 0 1 1)
    } else if (analogRead(A0) >= TRESHOLD && analogRead(A1) >= TRESHOLD && analogRead(A2) >= TRESHOLD && analogRead(A3) >= TRESHOLD && analogRead(A4) <= TRESHOLD && analogRead(A5) <= TRESHOLD) {
      motorOption('8', SPEED6, SPEED0);

      // leitura do sensor (1 0 0 0 0 0)
    } else if (analogRead(A0) <= TRESHOLD && analogRead(A1) >= TRESHOLD && analogRead(A2) >= TRESHOLD && analogRead(A3) >= TRESHOLD && analogRead(A4) >= TRESHOLD && analogRead(A5) >= TRESHOLD) {
      motorOption('6', SPEED7, SPEED7);
      // leitura do sensor (0 0 0 0 0 1)
    } else if (analogRead(A0) >= TRESHOLD && analogRead(A1) >= TRESHOLD && analogRead(A2) >= TRESHOLD && analogRead(A3) >= TRESHOLD && analogRead(A4) >= TRESHOLD && analogRead(A5) <= TRESHOLD) {
      motorOption('4', SPEED7, SPEED7);

    }
  }
  motorOption('0', 0, 0);
}

void forward_brake(int posa, int posb) {
  digitalWrite(aphase, LOW);
  digitalWrite(bphase, HIGH);
  analogWrite(aenbl, posa);
  analogWrite(benbl, posb);
}

void PID_control() {
  uint16_t position = qtr.readLineBlack(sensorValues);
  int error = 3500 - position;

  int motorspeed = Kp + Ki + Kd;
  
  int motorspeeda = basespeeda + motorspeed;
  int motorspeedb = basespeedb - motorspeed;
  
  if (motorspeeda > maxspeeda) {
    motorspeeda = maxspeeda;
  }
  if (motorspeedb > maxspeedb) {
    motorspeedb = maxspeedb;
  }
  if (motorspeeda < 0) {
    motorspeeda = 0;
  }
  if (motorspeedb < 0) {
    motorspeedb = 0;
  } 
  //Serial.print(motorspeeda);Serial.print(" ");Serial.println(motorspeedb);
  forward_brake(motorspeeda, motorspeedb);
}
