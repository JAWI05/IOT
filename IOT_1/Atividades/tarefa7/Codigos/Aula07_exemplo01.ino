// Início do sketch 
// Pinos de controle motor A
const int IN1 = 9;
const int IN2 = 8;

void setup(){
// Declara pinos IN1 e IN2 como saída
pinMode(IN1,OUTPUT);
pinMode(IN2,OUTPUT);
}
void loop(){
  // Sentido horario 
  digitalWrite(IN1,HIGH);
  digitalWrite(IN2,LOW);
  // Aguarda 3s
  delay(3000);

  // freio
  digitalWrite(IN1,HIGH);
  digitalWrite(IN2,HIGH);
  // Aguarda 4s
  delay (4000); 
  
  // Sentido antihorario
  digitalWrite(IN1,LOW);
  digitalWrite(IN2,HIGH);
  // Aguarda 2,5s
  delay(2500);

  // desligado
  digitalWrite(IN1,LOW);
  digitalWrite(IN2,LOW);  
  // Aguarda 3,5s
  delay (3500);

} // fim da função de loop e programa
