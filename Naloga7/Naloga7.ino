#include <ESP8266WiFi.h>
const String imeOmrezja = "blabla2";
const String geslo = "geslogeslo";
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
  
}
