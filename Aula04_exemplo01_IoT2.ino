// Início do sketch e Função de configuração
void setup() {
  // define pino 1 como saída
  pinMode(D1, OUTPUT);
} // fim da função de configuração
// função de repetição infinita
void loop() {
  digitalWrite(D1, HIGH); // liga led (coloca pino em nível 1)
  delay(1000);                     // aguarda 1s
  digitalWrite(D1, LOW);  // desliga led (coloca pino em nível 0)
  delay(1000); // aguarda um segundo
} // fim da função de loop e programa
