#include <WiFi.h>
#include <WiFiClient.h>
#include <WiFiAP.h>

// Define os pinos para o LED RGB
const int verm = 1;
const int verde = 0;
const int azul = 3;

// Credenciais para o Access Point (AP)
const char *ssid = "AP";
const char *password = "yourPassword";

WiFiServer server(80);

void setup() {
  // Configura os pinos do LED RGB como saída
  pinMode(verm, OUTPUT);
  pinMode(verde, OUTPUT);
  pinMode(azul, OUTPUT);
  
  // Inicializa todos os pinos do LED RGB como apagados
  digitalWrite(verm, LOW);
  digitalWrite(verde, LOW);
  digitalWrite(azul, LOW);

  Serial.begin(115200);

  // Configura o Access Point (AP)
  WiFi.softAP(ssid, password);
  IPAddress myIP = WiFi.softAPIP();
  Serial.print("IP: ");
  Serial.println(myIP);
  server.begin();

}

void loop() {
  WiFiClient client = server.available();   

  if (client) {                             
    Serial.println("ovo cliente.");           
    String currentLine = "";                
    while (client.connected()) {            
      if (client.available()) {            
        char c = client.read();             
        Serial.write(c);                   
        if (c == '\n') {                    

          if (currentLine.length() == 0) {
            client.println("HTTP/1.1 200 OK");
            client.println("Content-type:text/html");
            client.println();

            client.println("<html>");
            client.println("<head><title>Controle LED RGB</title></head>");
            client.println("<body>");
            client.println("<h1>Controle o LED RGB</h1>");
            client.println("<p><a href=\"/red\"><button>Vermelho</button></a></p>");
            client.println("<p><a href=\"/green\"><button>Verde</button></a></p>");
            client.println("<p><a href=\"/blue\"><button>Azul</button></a></p>");
            client.println("<p><a href=\"/off\"><button>Apagar</button></a></p>");
            client.println("</body></html>");

            client.println();
            break;
          } else {
            currentLine = "";
          }
        } else if (c != '\r') {  
          currentLine += c;     
        }

        if (currentLine.endsWith("GET /red")) {
          // Acende o LED em vermelho
          digitalWrite(verm, HIGH);
          digitalWrite(verde, LOW);
          digitalWrite(azul, LOW);
        }
        if (currentLine.endsWith("GET /green")) {
          // Acende o LED em verde
          digitalWrite(verm, LOW);
          digitalWrite(verde, HIGH);
          digitalWrite(azul, LOW);
        }
        if (currentLine.endsWith("GET /blue")) {
          // Acende o LED em azul
          digitalWrite(verm, LOW);
          digitalWrite(verde, LOW);
          digitalWrite(azul, HIGH);
        }
        if (currentLine.endsWith("GET /off")) {
          // Apaga o LED
          digitalWrite(verm, LOW);
          digitalWrite(verde, LOW);
          digitalWrite(azul, LOW);
        }
      }
    }
    client.stop();
    Serial.println("Cliente desconectaso.");
  }
}
