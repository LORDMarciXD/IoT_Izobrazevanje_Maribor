//-----------------------------------------------------------------------
// --- Bluetooth daljinec------------------------------------------------
//
// Program za mobilni telefon:
// Car Bluetooth RC
// Android: https://play.google.com/store/apps/details?id=com.buncaloc.carbluetoothrc


#include <SoftwareSerial.h>
SoftwareSerial BTSerial(13, 9);      //Pini za serijsko komunikacijo z Bluetooth modulom: RX | TX = D7 | SD2

// Ukazi:
// S - Stop
// F - Naprej
// B - Nazaj
// L - Levo
// R - Desno
// G - Naprej-levo
// H - Nazaj-levo
// I - Naprej-desno
// J - Nazaj-desno
// W - Sprednje luči ON
// v - Sprednje luči OFF
// U - Zadnje luči ON
// u - Zadnje luči OFF
// V - Hupa ON
// v - Hupa OFF

int HUPA=16;
int PWMA=5; //Moč motorja A    D1
int PWMB=4; //Moč motorja B    D2
int DA=0;   //Smer vrtenja motorja A   D3
int DB=2;   //Smer vrtenja motorja B   D4
int LeviSenzor = 14;       //Levi senzor črte D5
int DesniSenzor = 12;      //Desni senzor črte D6

char Sprejem;   //Sprejem Serijski prenos

int zastavica=0;


//-----------------------------------------------------------------------
// --- Začetni pogoji ---------------------------------------------------
void setup() {
  Serial.begin(9600);
  delay (2000);
  Serial.println("Car Bluetooth RC");
  BTSerial.begin(38400);            // Serijska hitrost za Bluetooth modul HC-05 

 pinMode(PWMA, OUTPUT); 
 pinMode(PWMB, OUTPUT); 
 pinMode(DA, OUTPUT); 
 pinMode(DB, OUTPUT); 
 pinMode(HUPA, OUTPUT);
 pinMode(LeviSenzor, INPUT);
 pinMode(DesniSenzor, INPUT);

}

//-----------------------------------------------------------------------
// --- Neskončna zanka --------------------------------------------------
void loop() {
  
  Serial.flush();   
  if (BTSerial.available()){
    Sprejem = BTSerial.read();
    Serial.println(Sprejem);
  }
  // F - vozi naprej
  if (Sprejem == 'F') {  
    digitalWrite(DA, LOW);     // Nastavitev smeri vrtenja motorja A
    digitalWrite(PWMA, HIGH);   // Omogočimo izhod za motor A
    digitalWrite(DB, HIGH);
    digitalWrite(PWMB, HIGH); 
  }

  // B - Nazaj
  if (Sprejem == 'B') {  
    digitalWrite(DA, HIGH);     // Nastavitev smeri vrtenja motorja A
    digitalWrite(PWMA, HIGH);   // Omogočimo izhod za motor A
    digitalWrite(DB, LOW);
    digitalWrite(PWMB, HIGH); 
  }

  // L - Levo
  if (Sprejem == 'L') {  
    digitalWrite(DA, LOW);     // Nastavitev smeri vrtenja motorja A
    digitalWrite(PWMA, LOW);   // Omogočimo izhod za motor A
    digitalWrite(DB, HIGH);
    digitalWrite(PWMB, HIGH); 
  }

  // R - Desno
  if (Sprejem == 'R') {  
    digitalWrite(DA, LOW);     // Nastavitev smeri vrtenja motorja A
    digitalWrite(PWMA, HIGH);   // Omogočimo izhod za motor A
    digitalWrite(DB, HIGH);
    digitalWrite(PWMB, LOW); 
  }

  // G - Naprej-levo
  if (Sprejem == 'G') {  
    digitalWrite(DA, LOW);     // Nastavitev smeri vrtenja motorja A
    analogWrite(PWMA, 500);   // Omogočimo izhod za motor A
    digitalWrite(DB, HIGH);
    digitalWrite(PWMB, HIGH); 
  }

  // I - Naprej-desno
  if (Sprejem == 'I') {  
    digitalWrite(DA, LOW);     // Nastavitev smeri vrtenja motorja A
    digitalWrite(PWMA, HIGH);   // Omogočimo izhod za motor A
    digitalWrite(DB, HIGH);
    analogWrite(PWMB, 500); 
  }

  // H - Nazaj-levo
  if (Sprejem == 'H') {  
    digitalWrite(DA, HIGH);     // Nastavitev smeri vrtenja motorja A
    analogWrite(PWMA, 500);   // Omogočimo izhod za motor A
    digitalWrite(DB, LOW);
    digitalWrite(PWMB, HIGH); 
  }

  // J - Nazaj-desno
  if (Sprejem == 'J') {  
    digitalWrite(DA, HIGH);     // Nastavitev smeri vrtenja motorja A
    digitalWrite(PWMA, HIGH);   // Omogočimo izhod za motor A
    digitalWrite(DB, LOW);
    analogWrite(PWMB, 500); 
  }

  // S - stop
  if (Sprejem == 'S') {  
    digitalWrite(DA, HIGH); 
    digitalWrite(PWMA, LOW); 
    digitalWrite(DB, LOW); 
    digitalWrite(PWMB, LOW); 
  }

  // V - Hupa ON
  if (Sprejem == 'V') {
    digitalWrite(HUPA,HIGH);
  }

  // v - Hupa OFF
  if (Sprejem == 'v') {
    digitalWrite(HUPA,LOW);
  }

  // W - Sprednje luči ON
  if (Sprejem == 'W') {
    zastavica = 1;
  }
  if (Sprejem == 'w') {
    zastavica = 0;
  }

  if (zastavica == 1){
    if (digitalRead (LeviSenzor) == LOW)    //Levi senzor zazna črto
    {  
      Serial.println("DESNA");
      digitalWrite(DA, LOW);     // Nastavitev smeri vrtenja motorja A
      digitalWrite(PWMA, LOW);   // Omogočimo izhod za motor A
      digitalWrite(DB, HIGH);
      analogWrite(PWMB, 850); 
    }

    //Desno senzor 
    if (digitalRead (DesniSenzor) == LOW)    //Desni senzor zazna črto
    {  
    
      Serial.println("LEVA");
      digitalWrite(DA, LOW);     // Nastavitev smeri vrtenja motorja A
      analogWrite(PWMA, 850);   // Omogočimo izhod za motor A
      digitalWrite(DB, HIGH);
      digitalWrite(PWMB, LOW);
    }

    if (digitalRead (LeviSenzor) == LOW && digitalRead (DesniSenzor) == LOW)
    {
      digitalWrite(DA, LOW);     // Nastavitev smeri vrtenja motorja A
      digitalWrite(PWMA, LOW);   // Omogočimo izhod za motor A
      digitalWrite(DB, HIGH);
      digitalWrite(PWMB, LOW);
    }

    if (digitalRead (DesniSenzor) == LOW)    //Desni senzor zazna črto
    {  
    
      Serial.println("LEVA");
      digitalWrite(DA, LOW);     // Nastavitev smeri vrtenja motorja A
      analogWrite(PWMA, 850);   // Omogočimo izhod za motor A
      digitalWrite(DB, HIGH);
      digitalWrite(PWMB, LOW);
    }

    if (digitalRead (LeviSenzor) == HIGH && digitalRead (DesniSenzor) == HIGH)
    {
      digitalWrite(DA, LOW);     // Nastavitev smeri vrtenja motorja A
      analogWrite(PWMA, 850);   // Omogočimo izhod za motor A
      digitalWrite(DB, HIGH);
      analogWrite(PWMB, 850);
    }
  }


  //...
  //...

}
