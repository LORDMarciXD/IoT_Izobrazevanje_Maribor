//-----------------------------------------------------------------------
// --- Senzor zaznave črte  ---------------------------------------------

int LeviSenzor = 14;       //Levi senzor črte D5
int DesniSenzor = 12;      //Desni senzor črte D6
int PWMA=5; //Moč motorja A    D1
int PWMB=4; //Moč motorja B    D2
int DA=0;   //Smer vrtenja motorja A   D3
int DB=2;   //Smer vrtenja motorja B   D4

//-----------------------------------------------------------------------
// --- Začetni pogoji ---------------------------------------------------
void setup() {
  Serial.begin(9600);           
  delay(3000);  
  Serial.println("Senzor zaznave crte");
  
  pinMode(LeviSenzor, INPUT);
  pinMode(DesniSenzor, INPUT);  
  pinMode(PWMA, OUTPUT);   
  pinMode(PWMB, OUTPUT); 
  pinMode(DA, OUTPUT); 
  pinMode(DB, OUTPUT); 
}


//-----------------------------------------------------------------------
// --- Neskončna zanka --------------------------------------------------
void loop() {

  //Levi senzor 
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
  
}
