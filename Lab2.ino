int buttonPin3 = 3;
int buttonPin4 = 4;
int d0 = 5;
int d1 = 6;
int d2 = 52;
int d3 = 53;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  pinMode (buttonPin3, INPUT);
  pinMode (buttonPin4, INPUT);
  pinMode (d0, OUTPUT);
  pinMode (d1, OUTPUT);
  pinMode (d2, OUTPUT);
  pinMode (d3, OUTPUT);
  Serial.println("Setup complete!");
}

void loop() {
  // put your main code here, to run repeatedly:
  digitalwrite(d0, LOW);
  digitalwrite(d1, LOW);
  digitalwrite(d2, LOW);
  digitalwrite(d3, LOW);
  char pin3 = digitalRead(buttonPin3);
  char pin4 = digitalRead(buttonPin4);
  if (pin3 == LOW && pin4 == LOW){
  // D0 on
  digitalwrite(d0, HIGH);
  else if(pin3 == HIGH && pin4 == LOW){
  // D1 on
  digitalwrite(d1, HIGH);
  else if(pin3 == LOW && pin4 == HIGH){
  // D3 on
  digitalwrite(d3, HIGH);
  }
  else{
    digitalWrite(d2, HIGH);
  }
  delay(500);

}
