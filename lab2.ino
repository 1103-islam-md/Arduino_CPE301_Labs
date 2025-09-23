void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  Serial.println("Hello from the Serial monitor!");
  pinMode(4, OUTPUT);
  pinMode(2, INPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  char input = digitalRead(2);
  if(input == HIGH){
    digitalWrtie(4, HIGH);
    Serial.println("Button has been pressed"); 
    delay(1000);
  }else{
    digitalWrite(4, LOW);
  }
  }
}
