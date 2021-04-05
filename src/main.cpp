#include <Arduino.h>
#include <WiFi.h>
#include <WebServer.h>
// SSID & Password
const char* ssid = "FRITZBox 7530 AA"; // Enter your SSID here
const char* password = "29204458007338454923"; //Enter your Password here
WebServer server(80); // Object of WebServer(HTTP port, 80 is defult)

void handle_root(void);

void setup() {
Serial.begin(115200);
Serial.println("Try Connecting to ");
Serial.println(ssid);

// Connect to your wi-fi modem
WiFi.begin(ssid, password);

// Check wi-fi is connected to wi-fi network
while (WiFi.status() != WL_CONNECTED) {
  delay(1000);
  Serial.print(".");
}

Serial.println("");
Serial.println("WiFi connected successfully");
Serial.print("Got IP: ");
Serial.println(WiFi.localIP()); //Show ESP32 IP on serial
server.on("/", handle_root);
server.begin();
Serial.println("HTTP server started");
delay(100);
}

void loop() {
  server.handleClient();
}

// HTML & CSS contents which display on web server
String HTML = "<!DOCTYPE html>\
<html>\
<body>\
<h1> CHISTES MALOS </h1>\
<p> - Que le dice un calcetin al de al lado? Tenemos que charlar largo y tendido. </p>\
<p> - Cual es la mejor mascota para un esqueleto? Un sab-hueso. </p>\
<p> - Por que estallo el equipo de musica? Porque era radio-activo. </p>\
<p> - Como puedes arreglar una hierba que se ha roto? Con pega-menta. </p>\
<p> - Cual es el animal mas sonoro de la orquesta? El torombon </p>\
<p> - Porque los peces juegan tan mal al tenis? Por que odian acercarse a la red. </p>\
<p> - Que hace un perro en una obra de construccion? Ta-ladrando. </p>\
<p> - Que le dice una patata al churrero? ¡Me tienes frita! </p>\
<p> - Por que ya no te hablas con la rana? Porque era in-sapo-table. </p>\
<p> - Con que excaban las cuevas los dinosaurios? Con dino-mita. </p>\
<p> - Que pez conduce peor? El de-rrape </p>\
</body>\
</html>";

// Handle root url (/)
void handle_root() {
  server.send(200, "text/html", HTML);
}
