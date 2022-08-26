// função 1 (sem entrada/sem saida);

void inicio(void){
  pinMode(13,OUTPUT);
  digitalWrite(13,HIGH);
  Serial.begin(9600);
  Serial.println("Arduino iniciado");
}

// função 2 (com entrada/sem saida);
void ligarled(int porta, boolean situacao){
  pinMode(porta,OUTPUT);
  if(situacao){
    digitalWrite(porta,HIGH);
  }else{
    digitalWrite(porta,LOW);
  }
}

// função 3 (sem entrada/com saida);
int ledaleatorio(void){
  return random(2,13);
}

// função 3 (com entrada/com saida);
int numerospares(int numero){
  if(numero%2 == 0){
    return numero;
  }else{
    return 0;
  }
}
void setup() {
  // put your setup code here, to run once:
  inicio();

}

void loop() {
  // put your main code here, to run repeatedly:
  for(int i=2;i<=13;i++){
    int aux = numerospares(ledaleatorio());
    if(aux != 0){
      ligarled(aux,true);  
    }
    delay(100);
  }
  delay(1000);
  for(int i=13;i>=2;i--){
    int aux = numerospares(ledaleatorio());
    if(aux != 0){
      ligarled(aux,true);  
    }
    delay(100);
  }
  delay(1000);
}
