#include <ESP8266HTTPClient.h>
#include <ESP8266WiFi.h>
#include "ThingSpeak.h"
#include <DHTesp.h>

#define DHT_PIN (16)
DHTesp senzor;

#define CHANNEL_NUMBER 708227
#define API_KEY "1S8W7RYXWBO3CE7M"

const String imeOmrezja = "rtslab";
const String geslo = "rtslab2019";

WiFiClient client;

void setup()
{
  Serial.begin(9600);
  delay(1000);
  Serial.println("ThingSpeak");

  Serial.print("Povezujem se na omrezje " + imeOmrezja + "...");
  WiFi.begin(imeOmrezja, geslo);
  while(WiFi.status() != WL_CONNECTED)
  {
    Serial.print(".");
    delay(300);
  }
  Serial.println("Uspesno");

  Serial.println(WiFi.localIP());

  senzor.setup(DHT_PIN, DHTesp::DHT22);
  ThingSpeak.begin(client);
}

void loop()
{
  float temperatura = senzor.getTemperature();
  float vlaga = senzor.getHumidity();

  Serial.println("Temperatura: " + String(temperatura,1));
  Serial.println("Vlaga: " + String(vlaga, 1));
  
  ThingSpeak.setField(1, String(temperatura,1));
  ThingSpeak.setField(2, String(vlaga,1));

  int status = ThingSpeak.writeFields(CHANNEL_NUMBER, API_KEY);
  if(status==OK_SUCCESS)
  {
    Serial.println("Prenos uspel");
  }
  else
  {
    Serial.println("Prenos ni uspel");
  }
  delay(20000);
}
