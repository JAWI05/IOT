const int rele = 13;
void setup() {
  pinMode(rele, OUTPUT);
  Serial.begin(9600);
}
void loop() {
  Serial.println("Digite 1 para ligar e 0 para desligar");
  if(Serial.available ()){
    char caractere = (char) Serial.read();
    if(caractere == '1'){
      digitalWrite(rele, HIGH);   // Liga saída
      Serial.println("ligado");
    }
    else if(caractere == '0'){
      digitalWrite(rele, LOW); //Desliga saída
      Serial.println("desligado");
    }
  }
    delay(1000);   // Aguarda 1s                  
}
