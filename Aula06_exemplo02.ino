// Início do sketch 
// Cria uma constante chamada pot no pino A0
const int pot = A0;

//Função de configuração
void setup() {
  // Inicia Comunicação Serial
  // Velocidade de 9600 bits por segundo
  Serial.begin(9600);
} // fim da função de configuração
// função de repetição infinita
void loop() {
// Cria variável chamada leitura para saber condição de giro
 int leitura; 
 // Lê pino pot e guarda em leitura
leitura = analogRead(pot);
 //  Imprime na tela o valor de leitura
 Serial.println(leitura); 
// Aguarda 500 ms
delay (500);
} // fim da função de loop e programa
