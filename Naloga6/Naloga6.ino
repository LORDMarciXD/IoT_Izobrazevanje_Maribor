#include <LiquidCrystal_I2C.h>
#include <DHTesp.h>
LiquidCrystal_I2C lcd(0x27, 16,2);
DHTesp senzor;
const int DHT_PIN = 16;
const int TRIGGER_PIN = 10;
const int ECHO_PIN = 15; 
void setup()
{
  senzor.setup(DHT_PIN,DHTesp::DHT22);
  Serial.begin(9600);
  delay(1000);

  pinMode(TRIGGER_PIN,OUTPUT);
  pinMode(ECHO_PIN,INPUT);
  
  Serial.println("LCD IZPIS");
  lcd.begin(16,2);
  lcd.init();
  lcd.backlight();
  lcd.setCursor(3, 0);
  lcd.print("OI   ");
  
}

void loop()
{
  delay(3000);
  float temperatura = senzor.getTemperature();
  float vlaga = senzor.getHumidity();
  String stat = senzor.getStatusString();
  float temperaturaF = senzor.toFahrenheit(temperatura);

  Serial.println("------------------------------------------------------------------------------------------");
  Serial.print("Temp (C): ");
  Serial.println(temperatura, 1);
  Serial.print("Vlaga (%): ");
  Serial.println(vlaga, 1);
  Serial.print("Temp(F): ");
  Serial.println(temperaturaF, 1);
  Serial.print("Status: ");
  Serial.println(stat);
  Serial.print("");

  lcd.setCursor(0,0);
  lcd.print("T: " + String(temperatura, 1));

  lcd.setCursor(9,0);
  lcd.print("V: " + String(vlaga, 1));

  digitalWrite(TRIGGER_PIN,LOW);
  delayMicroseconds(2);
  digitalWrite(TRIGGER_PIN,HIGH);;
  delayMicroseconds(10);
  digitalWrite(TRIGGER_PIN,LOW);

  unsigned long trajanje = pulseIn(ECHO_PIN,HIGH);

  unsigned long razdalja = 0.0343 * trajanje / 2;
  Serial.println("TRAJANJE: " + String(trajanje) + " => Razdalja: " + String(razdalja) + "cm");

  lcd.setCursor(0,1);
  lcd.print("RAZDALJA:   " + String(razdalja) + "cm");
  
}
