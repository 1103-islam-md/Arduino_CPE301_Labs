int LED_R = 9;
int LED_Y = 8;
int LED_G = 7;
int LED_B = 10;

void setup() {
// put your setup code here, to run once:
Serial.begin(9600);
pinMode(LED_R, OUTPUT);
pinMode(LED_Y, OUTPUT);
pinMode(LED_G, OUTPUT);
pinMode(LED_B, OUTPUT);
Serial.println("This is the Traffic light Project!");
}

void loop() {
// put your main code here, to run repeatedly:
Serial.println("Red light is ON");
digitalWrite(LED_R, HIGH);
unsigned long time = millis();
while (digitalRead(LED_R) == HIGH && millis() - time < 5000UL) {
digitalWrite(LED_B, !digitalRead(LED_B)); // toggle
delay(250);
}
digitalWrite(LED_B, LOW);
digitalWrite(LED_R, LOW);

Serial.println("Yellow light is ON");
digitalWrite(LED_Y, HIGH);
delay(3000);
digitalWrite(LED_Y, LOW);


Serial.println("Green light is ON");
digitalWrite(LED_G, HIGH);
delay(5000);
digitalWrite(LED_G, LOW);

}