const int LED = 12;
const int botao = 5;

void setup(){
  pinMode(LED, OUTPUT);
  pinMode(botao, INPUT);
}
void loop(){
  int leitura;
  leitura = digitalRead(botao);
  if(leitura == HIGH){
    digitalWrite(LED, HIGH);
    delay(500);
    digitalWrite(LED, LOW);
    delay(500);
  }
  else{
    digitalWrite(LED, LOW);
  }
}
