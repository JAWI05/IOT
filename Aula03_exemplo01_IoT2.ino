// Inclui biblioteca Servo.h
#include <Servo.h>
Servo myservo;// Cria objeto myservo
// É possível criar mais de um objeto
int pos = 0;// Variável de posição
void setup() {
myservo.attach(9);// Anexa o pino 9 ao objeto myservo
}
void loop() {
// Move de 0 a 180 graus de um em um grau
for (pos = 0; pos <= 180; pos += 1) {
myservo.write(pos);// Escreve a posição atual no objeto servo
delay(15);// Aguarda 15 ms para ver o movimento
}
for (pos = 180; pos >= 0; pos -= 1) {// Move de 180 a 0 grau
myservo.write(pos);// Escreve a posição atual no objeto servo
delay(15);// Aguarda 15 ms para ver o movimento
}
}// fim do programa
