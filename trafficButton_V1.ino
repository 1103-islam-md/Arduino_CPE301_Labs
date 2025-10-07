int Button = 10;
int Led_R = 9;
int Led_Y = 8;
int Led_G = 7;
int Button_State = 0;
int last_Button_State = LOW;


void setup() {
// put your setup code here, to run once:
Serial.begin(9600);
pinMode(Button, INPUT);
pinMode(Led_R, OUTPUT);
pinMode(Led_Y, OUTPUT);
pinMode(Led_G, OUTPUT);
Serial.println("This is the Traffic light Project!");
}

void loop() {
// put your main code here, to run repeatedly:
int read = digitalRead(Button);

if(read == HIGH && last_Button_State == LOW){
delay(50);
if(digitalRead(Button) == HIGH){
if (Button_State == 1){
Serial.println("Red light is ON");
digitalWrite(Led_R, HIGH);
digitalWrite(Led_G, LOW);
digitalWrite(Led_Y, LOW);
}
else if (Button_State == 2){
Serial.println("Yellow light is ON");
digitalWrite(Led_Y, HIGH);
digitalWrite(Led_G, LOW);
digitalWrite(Led_R, LOW);
}
else if (Button_State == 3){
Serial.println("Green light is ON");
digitalWrite(Led_G, HIGH);
digitalWrite(Led_Y, LOW);
digitalWrite(Led_R, LOW);
}

else if(Button_State == 0){
digitalWrite(Led_R, LOW);
digitalWrite(Led_Y, LOW);
digitalWrite(Led_G, LOW);

}
  if(Button_State >= 3){
    Button_State = 0;
  }
  else{
  Button_State++;
  }
}
}
last_Button_State = read;
}