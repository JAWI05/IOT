// --- Bibliotecas Auxiliares ---
#include <ESP8266WiFi.h>

// --- Define os pinos para o LED RGB ---
#define Verm D1
#define Verd D2
#define Azul D3

// --- Definições de rede ---
const char* ssid = "102_2G";
const char* password = "%#20&5$";

// --- Escutar porta 80 ---
WiFiServer server(80);

// --- Setup ---
void setup() {
  Serial.begin(115200);
  delay(10);

  // Configura os pinos do LED RGB como saída
  pinMode(Verm, OUTPUT);
  pinMode(Verd, OUTPUT);
  pinMode(Azul, OUTPUT);

  // Apaga o LED RGB no início
  digitalWrite(Verm, LOW);
  digitalWrite(Verd, LOW);
  digitalWrite(Azul, LOW);

  Serial.print("Conectando a rede: ");
  Serial.println(ssid);
  WiFi.begin(ssid, password);

  // --- Verifica e aguarda conexão ---
  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
  }
  Serial.println("WiFi conectado");
  server.begin();
  Serial.println("Servidor web iniciado");
  Serial.print("Utilize a seguinte URL: ");
  Serial.print("http://");
  Serial.print(WiFi.localIP());
}

// --- Função para controlar as cores ---
void setColor(int r, int g, int b) {
  analogWrite(Verm, r);
  analogWrite(Verd, g);
  analogWrite(Azul, b);
}

// --- Loop ---
void loop() {
  // Verifica conexão com servidor
  WiFiClient cliente = server.available();
  if (!cliente) return;

  // Aguardar envio de dados
  Serial.println("Novo cliente...");
  while (!cliente.available()) delay(10);

  // Realiza leitura da primeira linha da request
  String request = cliente.readStringUntil('\r');
  Serial.println(request);
  cliente.flush();

  // Verifica request e altera cor do LED RGB
  if (request.indexOf("/RGB=RED") != -1) {
    setColor(255, 0, 0); // Vermelho
  } else if (request.indexOf("/RGB=GREEN") != -1) {
    setColor(0, 255, 0); // Verde
  } else if (request.indexOf("/RGB=BLUE") != -1) {
    setColor(0, 0, 255); // Azul
  } else if (request.indexOf("/RGB=OFF") != -1) {
    setColor(0, 0, 0); // Desligar
  }

  // Retorna a resposta HTML
  client.println("HTTP/1.1 200 OK");
  client.println("Content-Type: text/html");
  client.println("");
  client.println("<!DOCTYPE HTML>");
  client.println("<html>");
  client.println("<h1>Controle LED RGB</h1>");
  client.println("<a href=\"/RGB=RED\"><button>Vermelho</button></a><br>");
  client.println("<a href=\"/RGB=GREEN\"><button>Verde</button></a><br>");
  client.println("<a href=\"/RGB=BLUE\"><button>Azul</button></a><br>");
  client.println("<a href=\"/RGB=OFF\"><button>Apagar</button></a>");
  client.println("</html>");

  delay(10);
  Serial.println("Cliente desconectado");
}
