#include <ESP8266WiFi.h>
#include <WiFiClientSecure.h>

//creating a web server for user authentication
String userId = "purnima";


const char* ssid = "SOC-LAB";
const char* password = "**********";

//storing and matching cookies for user authentication
//arduinoSession= millis();

//const char* host= "sdo.gsfc.nasa.gov";
const char* host="192.168.1.50";
const int httpsPort= 443;

// Use web browser to view and copy
// SHA1 fingerprint of the certificate
const char* fingerprint = "33 67 34 13 37 BA A4 E2 AB FB 61 DA CA 83 43 EB C5 2D 47 EF";

void setup() {
 Serial.begin(115200);
 Serial.println();
 Serial.print("connecting to ");
 Serial.println(ssid);
 WiFi.begin(ssid, password);
 while (WiFi.status() != WL_CONNECTED) {
   delay(500);
   Serial.print(".");
 }
 Serial.println("");
 Serial.println("WiFi connected");
 Serial.println("IP address: ");
 Serial.println(WiFi.localIP());



 // Use WiFiClientSecure class to create TLS connection
 WiFiClientSecure client;
 Serial.print("connecting to ");
 Serial.println(host);
 Serial.println(client);
 //Serial.println("Connected");
 //Serial.println("certificate matches");
 //Serial.println(".............................................");
 //Serial.println("Disconnected");
 
 while (!client.connect(host, httpsPort)) {
   Serial.println("connection failed");
 return;
 }

 if (client.verify(fingerprint, host)) {
   Serial.println("certificate matches");
 } else {
   Serial.println("certificate doesn't match");
 }

 //String url = "/repos/esp8266/Arduino/commits/master/status";
 String url = "/epo";
 Serial.print("requesting URL: ");
 Serial.println(url);

 client.print(String("GET ") + url + " HTTP/1.1\r\n" +
              "Host: " + host + "\r\n" +
              "User-Agent: \r\n" +
              "Connection: close\r\n\r\n");

 Serial.println("request sent");

 Serial.println("Receiving response");

 while (client.connected()) {
   String line = client.readStringUntil('\n');
   Serial.println(line);
   if (line == "\r") {
     Serial.println("headers received");
     break;
   }
   
   Serial.write(client.read());
   delay(10);
 }
 
 String line = client.readStringUntil('\n');
  //if(line.startsWith("(\"state\":\"success\"")){
  //Serial.println("successful");
  //}
 
 Serial.println(line);
 Serial.println("closing connection");
}

void loop() {
  int nameNo;
  bool found=false;
  //Serial.println("please enter your username or ID");
  exit;
  //while(Serial.available() == 0)
  //{
   // String id = Serial.readString();
 // }
  
  //}
}
