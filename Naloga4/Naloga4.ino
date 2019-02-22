#include <DHTesp.h>
DHTesp senzor;
const int DHT_PIN = 16;

void setup()
{
  senzor.setup(DHT_PIN,DHTesp::DHT22);
  Serial.begin(9600);
  delay(1000);
  Serial.println("Temperaturni senzor");
}

void loop()
{
  delay(3000);
  float temperatura = senzor.getTemperature();
  float vlaga = senzor.getHumidity();
  String stat = senzor.getStatusString();
  float temperaturaF = senzor.toFahrenheit(temperatura);
  Serial.print("Temp (C): ");
  Serial.print(temperatura, 1);
  Serial.print(" Vlaga (%): ");
  Serial.print(vlaga, 1);
  Serial.print(" Temp(F): ");
  Serial.print(temperaturaF, 1);
  Serial.print(" Status: ");
  Serial.print(stat);
  Serial.println();
}
