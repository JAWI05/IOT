// Início do sketch 
// Cria uma constante chamada botao no pino 2
const int botao = 2;
// Cria uma constante chamada LED no pino 13
const int LED = 13;

//Função de configuração
void setup() {
  // define LED como saída
  pinMode(LED, OUTPUT);
// define botao como entrada
  pinMode(botao, INPUT);
} // fim da função de configuração
// função de repetição infinita
void loop() {
  int leitura; // Variável leitura para saber condição de aperto
  leitura = digitalRead(botao); // Lê pino botao e guarda em leitura
  if (leitura == HIGH){ // Se leitura for HIGH, então  
      digitalWrite(LED, HIGH);   // liga LED (coloca pino em nível 1)
      }
   else{   // Se leitura não for HIGH
       digitalWrite(13, LOW);    // desliga LED (coloca pino em nível 0)
   }
} // fim da função de loop e programa
