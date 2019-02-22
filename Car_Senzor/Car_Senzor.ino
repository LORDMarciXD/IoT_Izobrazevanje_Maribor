//-----------------------------------------------------------------------
// --- Meritev razdalje s pomočjo ultrazvočnega senzorja HC-SR04---------

int PWMA=5; //Moč motorja A    D1
int PWMB=4; //Moč motorja B    D2
int DA=0;   //Smer vrtenja motorja A   D3
int DB=2;   //Smer vrtenja motorja B   D4
#define trigPin 15        // Pin oddajnika/sprožilca  SD3
#define echoPin 10        // Pin sprejemnika          D8
long cas_odboja; 
long razdalja;


//-----------------------------------------------------------------------
// --- Začetni pogoji ---------------------------------------------------
void setup() {
  Serial.begin (9600);
  delay (3000);
  Serial.println("Meritev razdalje.");
  
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
  pinMode(PWMA, OUTPUT);   
  pinMode(PWMB, OUTPUT); 
  pinMode(DA, OUTPUT); 
  pinMode(DB, OUTPUT); 
}


//-----------------------------------------------------------------------
// --- Neskončna zanka --------------------------------------------------
void loop() {

  digitalWrite(trigPin, LOW);               //Ugasnemo ultrazvočni oddajnik
  delayMicroseconds(2); 
  digitalWrite(trigPin, HIGH);              //Vključimo ultrazvočni oddajnik
  delayMicroseconds(10);                    //Oddajamo 10 mikrosekund
  digitalWrite(trigPin, LOW);               //Ugasnemo ultrazvočni oddajnik
  cas_odboja = pulseIn(echoPin, HIGH);      //Vključimo ultrazvočni sprejemnik in merimo čas odboja
  razdalja = (cas_odboja/2) / 29.1;         //Preračun časa v razdaljo

  if (razdalja >= 4)
  {
    Serial.println("Furej!!!");
    digitalWrite(DA, LOW);     // Nastavitev smeri vrtenja motorja A
    analogWrite(PWMA, 750);   // Omogočimo izhod za motor A
    digitalWrite(DB, HIGH);
    analogWrite(PWMB, 750);
  }
  
  else if (razdalja <= 3)
  {
    Serial.println("Ustavi se!!!");
    digitalWrite(DA, HIGH); 
    digitalWrite(PWMA, LOW); 
    digitalWrite(DB, LOW); 
    digitalWrite(PWMB, LOW); 
  
  }
  
  
  delay(500);
  
}
