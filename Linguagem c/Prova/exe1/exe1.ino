  #define sensor1 A0
  #define sensor2 A1
  #define sensor3 A2
  
  int s[3];
  void setup() {
      Serial.begin(9600);
  }
  void loop() {
    converte();
  }
  bool converte (int valor_sensor,int valor_cor) 
  {
      valor_cor = analogRead(s[3]);
      if (valor_sensor <= valor_cor) {
          return true;
      } else {
          return false;     
      }
  }
