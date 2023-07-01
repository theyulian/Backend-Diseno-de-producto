// esp32.cpp

#include <WiFi.h>
#include <HTTPClient.h>

const char* ssid = "POCOF4";
const char* password = "03151708";
const char* serverUrl = "http://192.168.104.16:5000/temperatura";

const int temperatura = 34;

void setup() {
  Serial.begin(115200);
  WiFi.begin(ssid, password);

  while (WiFi.status() != WL_CONNECTED) {
    delay(1000);
    Serial.println("Conectando a WiFi...");
  }

  Serial.println("Conectado a WiFi");
}

void loop() {

  HTTPClient http;

  // Configurar la URL y los datos a enviar
  http.begin(serverUrl);
  http.addHeader("Content-Type", "application/x-www-form-urlencoded");

  String requestBody = "temperatura=" + String(temperatura);
  
  // Realizar la solicitud POST y obtener la respuesta
  int httpResponseCode = http.POST(requestBody);

  // Verificar el código de respuesta
  if (httpResponseCode > 0) {
    Serial.printf("Respuesta del servidor: %d\n", httpResponseCode);
    String response = http.getString();
    Serial.println(response);
  } else {
    Serial.printf("Error en la solicitud. Código de error: %d\n", httpResponseCode);
  }

  http.end();

  delay(5000); // Esperar 1 minuto antes de enviar la siguiente solicitud
}
