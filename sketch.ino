#include <WiFi.h>
#include <HTTPClient.h>
#include <WiFiClientSecure.h>

const char* ssid = "A35 de Yuri";
const char* password = "yurimartins";

const char* serverName = "https://jsonplaceholder.typicode.com/todos/1";

const int PINO_LED_TRUE = 18;

const int PINO_LED_FALSE = 19;

void setup() {
  Serial.begin(115200);

  WiFi.begin(ssid, password);
  Serial.print("Conectado ao Wi-Fi");
  while(WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");

    
  }
  Serial.println("n\Conectado com sucesso!");

  pinMode(PINO_LED_TRUE, OUTPUT);
  pinMode(PINO_LED_FALSE, OUTPUT);
}

void loop() {
  if(WiFi.status() == WL_CONNECTED) {
    
    WiFiClientSecure *client = new WiFiClientSecure; 

    if(client){

      client->setInsecure();

      HTTPClient http;

      Serial.print("[HTTPS] Iniciando requisição... \n");

       if (http.begin(*client, serverName)) {
      int httpCode = http.GET();

      if (httpCode > 0) {
        Serial.printf("[HTTP] Código de resposta: %d\n", httpCode);
        String payload = http.getString();
        if(httpCode == 200) {
          digitalWrite(PINO_LED_TRUE, HIGH);
          digitalWrite(PINO_LED_FALSE, LOW);
        } else {
          digitalWrite(PINO_LED_FALSE, HIGH);
          digitalWrite(PINO_LED_TRUE, LOW);
        }
        Serial.println("Conteúdo recebido:");
        Serial.println(payload);
      } else {
        Serial.printf("[HTTP] Falha na requisição, erro: %s\n", http.errorToString(httpCode).c_str());
        digitalWrite(PINO_LED_FALSE, HIGH);
        digitalWrite(PINO_LED_TRUE, LOW);
      }
      http.end();
    } else {
      Serial.printf("[HTTPS] Não foi possível conectar ao servidor\n");
      digitalWrite(PINO_LED_FALSE, HIGH);
      digitalWrite(PINO_LED_TRUE, LOW);
      delete client;
    }
  }


    }
  delay(10000); 
}