// Início do sketch 
// Cria uma constante chamada LED no pino 10
const int LED = 10;

//Função de configuração
void setup() {
  // define LED como saída
  pinMode(LED, OUTPUT);
} // fim da função de configuração

// função de repetição infinita
void loop() {
   // Contador i de 0 a 255
   for(int i = 0; i < 255; i++){
      // Variável i usada para alterar brilho do LED de forma automática
      analogWrite(LED, i);
      delay(100); // aguarda 100 ms
}   // Fim do contador   
  // Contador i de 255 a 0
   for(int i = 255; i > 0; i--){
      // Variável i usada para alterar brilho do LED de forma automática
      analogWrite(LED, i);
      delay(100); // aguarda 100 ms
}   // Fim do contador  
} // fim da função de loop e programa
