#include <WiFi.h> // biblioteca para ESP32

const char* ssid = "nome"; // Substitua com o nome da sua rede WiFi
const char* senha = "senha"; // Substitua com a senha da sua rede WiFi

// Define os pinos para o LED RGB
const int pinRed = 0;
const int pinGreen = 1;

void setup() {
  Serial.begin(115200); // Velocidade da serial

  // Configura os pinos do LED RGB como saída
  pinMode(pinRed, OUTPUT);
  pinMode(pinGreen, OUTPUT);

  // Inicialmente, apaga todas as cores do LED RGB
  digitalWrite(pinRed, LOW);
  digitalWrite(pinGreen, LOW);

  // Mensagem da rede
  Serial.print("Conectando com a rede ");
  Serial.println(ssid);
  
  WiFi.begin(ssid, senha); // Conexão na rede com senha
  
  // Enquanto a conexão não for realizada
  while (WiFi.status() != WL_CONNECTED) {
    delay(500); // Aguarda 500ms
    // Acende o LED em vermelho para indicar que não há conexão
    digitalWrite(pinRed, HIGH);
    digitalWrite(pinGreen, LOW);
    
    Serial.print("."); // Escreve pontos na tela
  }
  
  // Quando a conexão for realizada
  Serial.println("\nParabéns, você está conectado!");
  
  // Acende o LED em verde para indicar conexão bem-sucedida
  digitalWrite(pinRed, LOW);
  digitalWrite(pinGreen, HIGH);
  
  Serial.println("Endereco IP: ");
  Serial.println(WiFi.localIP()); // Mostra o IP da placa
}

void loop() {
  // Sem comandos adicionais
}
