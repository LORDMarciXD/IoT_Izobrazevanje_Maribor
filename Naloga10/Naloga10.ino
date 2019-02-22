#include <ESP8266HTTPClient.h>
#include <ESP8266WiFi.h>
#include "ThingSpeak.h"

#define CHANNEL_NUMBER 708227
#define API_KEY "1S8W7RYXWBO3CE7M"
#define FIELD3 3
#define FIELD4 4
#define FIELD5 5


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

  ThingSpeak.begin(client);
}

void PreveriDiodo(int LED, int field)

{
  int stanje = ThingSpeak.readIntField(CHANNEL_NUMBER,field,API_KEY);

  if(ThingSpeak.getLastReadStatus()==OK_SUCCESS)
  {
    Serial.println("Ledica na field" + String(field) + " ime stanje " + String(stanje));
    if(stanje==1)
    {
      digitalWrite(LED,HIGH);
    }
    else if(stanje==0)
    {
      digitalWrite(LED,LOW);
    }
  }
}

void loop()
{
  PreveriDiodo(0, FIELD3); 
  delay(20000);
  PreveriDiodo(4, FIELD4); 
  delay(20000);
  PreveriDiodo(5, FIELD5); 
  delay(20000);
}
