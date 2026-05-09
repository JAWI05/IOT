#include <WiFi.h> // biblioteca para ESP32
const char* ssid = "nome-da-sua-rede"; //Substitua com o nome da sua rede WiFi
const char* senha = "sua-senha"; //substitua com a senha da sua rede WiFi
void setup() {
  Serial.begin(115200); //Velocidade da serial
  pinMode(2,OUTPUT); // configura pino 2 como saída
 /* Aparece na serial a msg com nome da rede*/
  Serial.print("Conectando com a rede ");
  Serial.println(ssid);
  WiFi.begin(ssid, senha); // Conexão na rede com senha
 /* Enquanto a conexão não for realizada, faz*/
  while(WiFi.status() != WL_CONNECTED){
delay(500); //aguarda 500ms
    digitalWrite(2, LOW);// apaga D2
    Serial.print("."); // escreve pontos na tela
  }
  /*Quando a conexão foi realizada, faz*/
    Serial.println("Parabéns, você está conectado!");
    digitalWrite(2, HIGH); // acende D2
    Serial.println("Endereco IP: ");
    Serial.println(WiFi.localIP()); // mostra o IP da placa
}
void loop() {
  // Sem comandos
}
