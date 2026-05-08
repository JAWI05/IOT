#include <ESP8266WiFi.h> // biblioteca para ESP8266

const char* ssid = "Xiaomi_9888"; // Substitua com o nome da sua rede
const char* senha = "ALE"; // Substitua com a senha da sua rede WiFi


void setup() {
  Serial.begin(115200); // Velocidade da serial

  // Configura os pinos dos LEDs como saída
  pinMode(23, OUTPUT);
  pinMode(21, OUTPUT);
  pinMode(18, OUTPUT);

  // Apaga todos os LEDs inicialmente
  digitalWrite(23, LOW);
  digitalWrite(21, LOW);
  digitalWrite(18, LOW);

  // Mensagem na serial com o nome da rede
  Serial.print("Conectando com a rede ");
  Serial.println(ssid);

  WiFi.begin(ssid, senha); // Conexão na rede com senha

  // Enquanto a conexão não for realizada
  while (WiFi.status() != WL_CONNECTED) {
    delay(500); // Aguarda 500ms
    // Acende o LED vermelho para indicar falha na conexão
    digitalWrite(23, HIGH);
    digitalWrite(21, LOW);
    Serial.print("."); // Escreve pontos na tela
  }

  // Quando a conexão for realizada
  Serial.println("\nParabéns, você está conectado!");

  // Acende o LED verde para indicar sucesso na conexão
  digitalWrite(23, LOW);
  digitalWrite(21, HIGH);

  // Mostra o IP da placa
  Serial.println("Endereco IP: ");
  Serial.println(WiFi.localIP()); // mostra o IP da placa
}

void loop() {
  // Sem comandos no loop
}
