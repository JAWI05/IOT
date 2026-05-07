const int Trigger = 12;    // Pino digital 12 para Trigger do sensor
const int Echo = 11;       // Pino digital 11 para Echo do sensor
void setup() {
    Serial.begin(9600);          // Início comunicação serial
    pinMode(Trigger, OUTPUT);    // Trigger como saída
    pinMode(Echo, INPUT);        // Echo como entrada
    digitalWrite(Trigger, LOW);  // Inicializamos o pin com 0
}
void loop() {
    // Tempo que demora para chegar em eco
    long t;
    // Distância em centímetros
    long d;
    digitalWrite(Trigger, HIGH);
    delayMicroseconds(10);  // Enviamos um pulso de 10us
    digitalWrite(Trigger, LOW);
    t = pulseIn(Echo, HIGH);  // Obtemos eco do pulso
    d = t/59;                 // Escalamos o tempo a uma distância em cm
    Serial.print("Distancia: ");
    Serial.print(d);          // Enviamos por serial o valor da distância
    Serial.println("cm");
} // Fim do sketch
