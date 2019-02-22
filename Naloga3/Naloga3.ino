const int LED1 = 5;
const int LED2 = 4;
const int LED3 = 0;

void setup() {
  pinMode(LED1,OUTPUT);
  pinMode(LED2,OUTPUT);
  pinMode(LED3,OUTPUT);
  
  Serial.begin(9600);
  delay(1000);
  Serial.println("Sprejemanje znakov!");
}

void loop() {
  if(Serial.available() > 0)
  {
    char prebranznak = Serial.read();
    Serial.print("prebran znak: ");
    Serial.println(prebranznak);

    if(prebranznak == 'M')
    {
      digitalWrite(LED1,HIGH);
    }
    else if(prebranznak == 'm')
    {
      digitalWrite(LED1,LOW);
    }

    else if(prebranznak == 'O')
    {
      digitalWrite(LED2,HIGH);
    }
    else if(prebranznak == 'o')
    {
      digitalWrite(LED2,LOW);
    }

    else if(prebranznak == 'R')
    {
      digitalWrite(LED3,HIGH);
    }
    else if(prebranznak == 'r')
    {
      digitalWrite(LED3,LOW);
    }

    else if(prebranznak == 'c')
    {
      digitalWrite(LED1,LOW);
      digitalWrite(LED2,LOW);
      digitalWrite(LED3,LOW);
    }

    else if(prebranznak != 'M','m','O','o','R','r','c')
    {
      digitalWrite(LED1,HIGH);
      digitalWrite(LED2,HIGH);
      digitalWrite(LED3,HIGH);
      delay(1000);
      digitalWrite(LED1,LOW);
      digitalWrite(LED2,LOW);
      digitalWrite(LED3,LOW);
    }
  }
}
