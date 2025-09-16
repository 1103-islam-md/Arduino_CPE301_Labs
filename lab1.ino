int ledPin = 4;
int buttonPin = 2;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  pinMode(ledPin, OUTPUT);
  pinMode(buttonPin, INPUT);
  Serial.println("Hello from the Serial monitor!");
}

void loop() {
  // put your main code here, to run repeatedly:
  char input = digitalRead(buttonPin);
  if(input == HIGH){
    digitalWrite(ledPin, HIGH);
    Serial.println("Button pressed");
    delay(1000);
  }
  else{
    digitalWrite(ledPin, LOW);
  }
}
