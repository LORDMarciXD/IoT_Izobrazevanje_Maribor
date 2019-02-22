const int TIPKA = 14;
const int LED1 = 5;
const int LED2 = 4;
const int LED3 = 0;
int prejsnja;
int stevec;

void setup() {
  pinMode(TIPKA,INPUT);
  pinMode(LED1,OUTPUT);
  pinMode(LED2,OUTPUT);
  pinMode(LED3,OUTPUT);

  prejsnja = 0;
  
  Serial.begin(9600);
  delay(500);
  Serial.println("?");
}

void loop() {
  int stanje = digitalRead(TIPKA);
  
  Serial.println(stanje);

  if (prejsnja == 0 && stanje == 1)
  {
    stevec = stevec + 1;
    if(stevec == 1)
    {
      digitalWrite(LED1,HIGH);
      digitalWrite(LED2,LOW);
      digitalWrite(LED3,LOW);  
    }
    if(stevec == 2)
    {
      digitalWrite(LED1,LOW);
      digitalWrite(LED2,HIGH);
      digitalWrite(LED3,LOW);
    }
    if(stevec == 3)
    {
      digitalWrite(LED1,LOW);
      digitalWrite(LED2,LOW);
      digitalWrite(LED3,HIGH);  
    }
    if(stevec >= 3)
    stevec = 0;
  }

  prejsnja = stanje;
    
}
