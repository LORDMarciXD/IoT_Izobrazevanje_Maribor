//-----------------------------------------------------------------------
// --- Motor shield  ----------------------------------------------------
// 
// Dokumentacija:
// ESP 8266 motor shield https://cdn.hackaday.io/files/8856378895104/user-mannual-for-esp-12e-motor-shield.pdf
// L293 http://www.ti.com/lit/ds/symlink/l293.pdf

int PWMA=5; //Moč motorja A    D1
int PWMB=4; //Moč motorja B    D2
int DA=0;   //Smer vrtenja motorja A   D3
int DB=2;   //Smer vrtenja motorja B   D4
 

//-----------------------------------------------------------------------
// --- Začetni pogoji ---------------------------------------------------
void setup(){ 
  Serial.begin(9600); 
  delay(3000);  
  Serial.println("Motor shield");

  pinMode(PWMA, OUTPUT);   
  pinMode(PWMB, OUTPUT); 
  pinMode(DA, OUTPUT); 
  pinMode(DB, OUTPUT); 
} 
 
 
//-----------------------------------------------------------------------
// --- Neskončna zanka -------------------------------------------------- 
void loop(){ 

avto_naprej();
delay(1000);
avto_levo();
delay(1500);
avto_naprej();
delay(1000);
avto_desno();
delay(1500);
avto_nazaj();
delay(1000);
avto_stop();
delay(1000);
}

void avto_naprej(){
//Vozi naprej
  digitalWrite(DA, LOW);     // Nastavitev smeri vrtenja motorja A
  analogWrite(PWMA, 750);   // Omogočimo izhod za motor A
  digitalWrite(DB, HIGH);
  analogWrite(PWMB, 750); 
}

void avto_levo(){
//Vozi naprej
  digitalWrite(DA, LOW);     // Nastavitev smeri vrtenja motorja A
  analogWrite(PWMA, 750);    // Omogočimo izhod za motor A
  digitalWrite(DB, HIGH);
  analogWrite(PWMB, LOW); 
}

void avto_desno(){
//Vozi naprej
  digitalWrite(DA, LOW);     // Nastavitev smeri vrtenja motorja A
  analogWrite(PWMA, LOW);   // Omogočimo izhod za motor A
  digitalWrite(DB, HIGH);
  analogWrite(PWMB, 750); 
}

void avto_nazaj(){
//Vozi naprej
  digitalWrite(DA, HIGH);     // Nastavitev smeri vrtenja motorja A
  analogWrite(PWMA, 750);   // Omogočimo izhod za motor A
  digitalWrite(DB, LOW);
  analogWrite(PWMB, 750); 
}

void avto_stop(){
//Stop 
  digitalWrite(DA, HIGH); 
  digitalWrite(PWMA, LOW); 
  digitalWrite(DB, LOW); 
  digitalWrite(PWMB, LOW); 
  
}  
