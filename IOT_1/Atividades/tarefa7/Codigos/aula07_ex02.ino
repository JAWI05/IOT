//Declaração de constantes
// Pinos 2 e 3 para OUT (Saída) dos sensores
const int sensor_esq = 2, sensor_dir = 3;
// Pinos 9 e 10 para LEDs
const int LED_esq = 13, LED_dir = 12;

void setup() {
  // Inicia comunicação serial
  Serial.begin(9600);
  // configuração dos sensores e LEDs
  pinMode(sensor_esq, INPUT);
  pinMode(sensor_dir, INPUT);
  pinMode(LED_esq, OUTPUT);
  pinMode(LED_dir, OUTPUT);
}
void loop() {
  // Leitura dos sensores
  int leitura1 = digitalRead(sensor_esq);
  int leitura2 = digitalRead(sensor_dir);
  // Escrita no Monitor Serial
  Serial.print(leitura1);
  Serial.print(" e ");
  Serial.println(leitura2);
// Se os dois sensores lerem a faixa preta 
  if(leitura1 == LOW && leitura2 == LOW){
    // Ligam os dois LEDs
    digitalWrite(LED_esq, HIGH);
    digitalWrite(LED_dir, HIGH);
  }
  // Se o sensor esquerdo somente ler a faixa preta
  else if(leitura1 == LOW && leitura2 == HIGH){
    // Liga somente LED esquerdo
    digitalWrite(LED_esq, HIGH);
    digitalWrite(LED_dir, LOW);
  }
  // Se o sensor direito somente ler a faixa preta
  else if(leitura1 == HIGH && leitura2 == LOW){
    // Liga somente LED direito
    digitalWrite(LED_esq, LOW);
    digitalWrite(LED_dir, HIGH);
  }
  // Se nenhum dos dois sensores lerem a faixa preta 
  else if(leitura1 == HIGH && leitura2 == HIGH){
    // Desliga LEDs
    digitalWrite(LED_esq, LOW);
    digitalWrite(LED_dir, LOW);
  }   delay(200);        // Aguarda 200 ms
} // fim do programa
