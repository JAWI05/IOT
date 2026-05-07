const int rele = 13;
const int rele2 = 12;

void setup(){
  pinMode(rele, OUTPUT);
  pinMode(rele2, OUTPUT);
  Serial.begin(9600);
}

void loop(){
  Serial.println("Digite 1 para ligar ou 0 para desligar o relé 1");
  Serial.println("Digite L para ligar ou D para desligar o relé 2");
  if(Serial.available()){
    char caractere = (char) Serial.read();
    if(caractere == '1'){
      digitalWrite(rele, HIGH);
      Serial.println("Relé 1 Ligado");
    }
    else if(caractere == '0'){
      digitalWrite(rele, LOW); //Desliga saída
      Serial.println("Relé 1 Desligado");
    }
    else if(caractere == 'L'){
      digitalWrite(rele2, HIGH);
      Serial.println("Relé 2 Ligado");
    }
    else if(caractere == 'D'){
      digitalWrite(rele2, LOW);
      Serial.println("Relé 2 Desligado");
    }
  }
  delay(1000);
}