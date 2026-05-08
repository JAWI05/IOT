// Inclui biblioteca Servo.h
#include <Servo.h>
Servo myservo;// Cria objeto myservo
// É possível criar mais de um objeto
const int potpin = 0; // pino analógico A0 em potenciômetro
int valor; // variável de leitura val
void setup() {
Serial.begin(9600); // Inicia comunicação serial
myservo.attach(9);// Anexa o pino 9 ao objeto myservo
}
void loop() {
// lê valor do potenciômetro e armazena em val
valor = analogRead(potpin);
Serial.print("Valor lido pelo potenciometro: ");
Serial.println(valor);
valor = map(valor, 0, 1023, 0, 180); // mapeia valor e faz conversão para escala do servo
Serial.print("Valor convertido para servo: ");
Serial.println(valor);
myservo.write(valor); // coloca o servo na posição equivalente a val
delay(15); // aguarda 15 ms para ver movimento
} // Fim do programa
