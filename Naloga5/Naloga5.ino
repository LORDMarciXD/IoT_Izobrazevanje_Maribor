#include <LiquidCrystal_I2C.h>
#include <DHTesp.h>
LiquidCrystal_I2C lcd(0x27, 16,2);
DHTesp senzor;
const int DHT_PIN = 16;

void setup()
{
  senzor.setup(DHT_PIN,DHTesp::DHT22);
  Serial.begin(9600);
  delay(1000);
  Serial.println("LCD IZPIS");
  lcd.begin(16,2);
  lcd.init();
  lcd.backlight();
  lcd.setCursor(3, 0);
  lcd.print("PRIVIAT");
  
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

  lcd.setCursor(0,0);
  lcd.print("Temp:       " + String(temperatura, 1));

  lcd.setCursor(0,1);
  lcd.print("Vlag:       " + String(vlaga, 1));
}
