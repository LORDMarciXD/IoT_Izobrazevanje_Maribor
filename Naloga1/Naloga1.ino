void setup() { //izvede se samo enkrat
  pinMode(16,OUTPUT);
  Serial.begin(9600);
  //pocakamo da se vse incializira
  delay(1000);
  Serial.println("Led pozdrav 01");
}

void loop() { //izvaja se ves cas
  //vklopimo LED diodo
  digitalWrite(16,LOW);
  Serial.println("VKLOP");
  //zakasnitev 0,5 sekunde
  delay(500);
  //izklopimo LED diodo
  digitalWrite(16,HIGH);
  Serial.println("IZKLOP");
  //zakasnitev 0,5 sekunde
  delay(500);
}
