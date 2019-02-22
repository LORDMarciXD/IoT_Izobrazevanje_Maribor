#include <ArduinoJson.h>
#include <ESP8266HTTPClient.h>
#include <ESP8266WiFi.h>
const String imeOmrezja = "rtslab";
const String geslo = "rtslab2019";



void setup()
{
  Serial.begin(9600);
  delay(1000);
  Serial.println("Povezava na AP");

  Serial.print("Povezujem se na omrezje " + imeOmrezja + "...");
  WiFi.begin(imeOmrezja, geslo);
  while(WiFi.status() != WL_CONNECTED)
  {
    Serial.print(".");
    delay(300);
  }
  Serial.println("Uspesno");

  Serial.println(WiFi.localIP());
}

void loop()
{
  HTTPClient http;
  
  http.begin("http://ervajn.uni-mb.si:3000/api/novice/1");
  if (http.GET() > 0)
  {
    String message1 = http.getString();
    Serial.println(message1);
    
    StaticJsonBuffer<200> jsonBuffer;
    JsonObject& root = jsonBuffer.parseObject(message1);

    int idNovice1 = root["id"];
    String nazivNovice1 = root["naziv"];
    String opisNovice1 = root["opis"];

    Serial.println("ID: " + String(idNovice1));
    Serial.println("Naziv: " + String(nazivNovice1));
    Serial.println("Opis: " + String(opisNovice1));

    

  }
   http.begin("http://ervajn.uni-mb.si:3000/api/novice/2");
  if (http.GET() > 0)
  {
    String message2 = http.getString();
    Serial.println(message2);
    
    StaticJsonBuffer<200> jsonBuffer;
    JsonObject& root = jsonBuffer.parseObject(message2);

    int idNovice2 = root["id"];
    String nazivNovice2 = root["naziv"];
    String opisNovice2 = root["opis"];

    Serial.println("ID: " + String(idNovice2));
    Serial.println("Naziv: " + String(nazivNovice2));
    Serial.println("Opis: " + String(opisNovice2));

    

  }
   http.begin("http://ervajn.uni-mb.si:3000/api/novice/3");
  if (http.GET() > 0)
  {
    String message3 = http.getString();
    Serial.println(message3);
    
    StaticJsonBuffer<200> jsonBuffer;
    JsonObject& root = jsonBuffer.parseObject(message3);

    int idNovice3 = root["id"];
    String nazivNovice3 = root["naziv"];
    String opisNovice3 = root["opis"];

    Serial.println("ID: " + String(idNovice3));
    Serial.println("Naziv: " + String(nazivNovice3));
    Serial.println("Opis: " + String(opisNovice3));

    

  }
   http.begin("http://ervajn.uni-mb.si:3000/api/novice/4");
  if (http.GET() > 0)
  {
    String message4 = http.getString();
    Serial.println(message4);
    
    StaticJsonBuffer<200> jsonBuffer;
    JsonObject& root = jsonBuffer.parseObject(message4);

    int idNovice4 = root["id"];
    String nazivNovice4 = root["naziv"];
    String opisNovice4 = root["opis"];

    Serial.println("ID: " + String(idNovice4));
    Serial.println("Naziv: " + String(nazivNovice4));
    Serial.println("Opis: " + String(opisNovice4));

    

  }
   http.begin("http://ervajn.uni-mb.si:3000/api/novice/5");
  if (http.GET() > 0)
  {
    String message5 = http.getString();
    Serial.println(message5);
    
    StaticJsonBuffer<200> jsonBuffer;
    JsonObject& root = jsonBuffer.parseObject(message5);

    int idNovice5 = root["id"];
    String nazivNovice5 = root["naziv"];
    String opisNovice5 = root["opis"];

    Serial.println("ID: " + String(idNovice5));
    Serial.println("Naziv: " + String(nazivNovice5));
    Serial.println("Opis: " + String(opisNovice5));

    

  }
  
  delay(5000);
}
