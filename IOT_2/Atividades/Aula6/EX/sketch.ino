#include <WiFi.h>
#include <WiFiClient.h>
#include <WiFiAP.h>

#define VERMELHO 1
#define VERDE 0
#define AZUL 3

// Insira o nome e senha da rede WiFi que será criada
const char *ssid = "AP";
const char *password = "suaSenha";

WiFiServer servidor(80);

void setup() {
  pinMode(VERMELHO, OUTPUT);
  pinMode(VERDE, OUTPUT);
  pinMode(AZUL, OUTPUT);
  
  digitalWrite(VERMELHO, LOW);
  digitalWrite(VERDE, LOW);
  digitalWrite(AZUL, LOW);

  Serial.begin(115200);
  Serial.println();
  Serial.println("Configurando ponto de acesso...");

  if (!WiFi.softAP(ssid, password)) {
    log_e("Falha ao criar o ponto de acesso.");
    while(1);
  }

  IPAddress meuIP = WiFi.softAPIP();
  Serial.print("Endereço IP AP: ");
  Serial.println(meuIP);
  servidor.begin();
  Serial.println("Servidor iniciado");
}

void loop() {
  WiFiClient cliente = servidor.available(); 
  if (cliente) { 
    Serial.println("Novo cliente."); 
    String linhaAtual = ""; 
    while (cliente.connected()) { 
      if (cliente.available()) { 
        char c = cliente.read(); 
        Serial.write(c); 
        if (c == '\n') { 
          if (linhaAtual.length() == 0) {
            cliente.println("HTTP/1.1 200 OK");
            cliente.println("Content-type:text/html");
            cliente.println();

            cliente.print("Clique <a href=\"/R\">aqui</a> para VERMELHO.<br>");
            cliente.print("Clique <a href=\"/G\">aqui</a> para VERDE.<br>");
            cliente.print("Clique <a href=\"/B\">aqui</a> para AZUL.<br>");
            cliente.print("Clique <a href=\"/OFF\">aqui</a> para DESLIGAR o LED.<br>");

            cliente.println();
            break;
          } else {
            linhaAtual = "";
          }
        } else if (c != '\r') {
          linhaAtual += c;
        }

        // Comandos para controlar as cores do LED RGB
        if (linhaAtual.endsWith("GET /R")) {
          digitalWrite(VERMELHO, HIGH);   
          digitalWrite(VERDE, LOW);
          digitalWrite(AZUL, LOW);
        }
        if (linhaAtual.endsWith("GET /G")) {
          digitalWrite(VERMELHO, LOW);
          digitalWrite(VERDE, HIGH); 
          digitalWrite(AZUL, LOW);
        }
        if (linhaAtual.endsWith("GET /B")) {
          digitalWrite(VERMELHO, LOW);
          digitalWrite(VERDE, LOW);
          digitalWrite(AZUL, HIGH);  
        }
        if (linhaAtual.endsWith("GET /OFF")) {
          digitalWrite(VERMELHO, LOW);    
          digitalWrite(VERDE, LOW);
          digitalWrite(AZUL, LOW);
        }
      }
    }
    cliente.stop();
    Serial.println("Cliente desconectado.");
  }
}
