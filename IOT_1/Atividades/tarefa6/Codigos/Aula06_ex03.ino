// Início do sketch 
// Cria uma constante chamada pot no pino A0
const int pot = A0;
// Cria uma constante chamada LED no pino 13
const int LED = 13;

//Função de configuração
void setup() {
  // define LED como saída
  pinMode(LED, OUTPUT);
} // fim da função de configuração
// função de repetição infinita
void loop() {
  int leitura; // Variável leitura para saber condição de giro
  leitura = analogRead(pot); // Lê pino pot e guarda em leitura
  if (leitura >= 600){ // Se leitura for maior ou igual a 600, então  
      digitalWrite(LED, HIGH);   // liga LED (coloca pino em nível 1)
      }
   else{   // Se leitura não for maior ou igual a 600
       digitalWrite(13, LOW);    // desliga LED (coloca pino em nível 0)
   }
} // fim da função de loop e programa
