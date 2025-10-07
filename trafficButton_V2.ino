
int Button_State = 0;
int last_Button_State = LOW;


unsigned char* ddr_b = (unsigned char*) 0x24;
unsigned char* port_b = (unsigned char*) 0x25;
unsigned char* pin_b = (unsigned char*) 0x23;
unsigned char* ddr_h = (unsigned char*) 0x101;
unsigned char* port_h = (unsigned char*) 0x102;


/*
// Pin 10 - Port b bit 4
//  Pin 9 - Port h bit 6
?? Pin 8 - Port h bit 5
Pin 7 port h bit 4
*/
void setup() {
// put your setup code here, to run once:
Serial.begin(9600);
  *ddr_b &= ~(1 << PB4);
  *port_b|= (1 << PB4);
  *ddr_h |= (1 << PH6);
  *ddr_h |= (1 << PH5);
  *ddr_h |= (1 << PH4);
Serial.println("This is the Traffic light Project!");
}

void loop() {
// put your main code here, to run repeatedly:



if(*pin_b & (1 << PB4) && last_Button_State == LOW){
delay(50);
if(*pin_b & (1 << PB4)){
if (Button_State == 1){
Serial.println("Red light is ON");
// digitalWrite(Led_R, HIGH);
// digitalWrite(Led_G, LOW);
// digitalWrite(Led_Y, LOW);
*port_h |= (1 << PH6);
*port_h &= ~(1 << PH5);
*port_h &= ~(1 << PH4);
}
else if (Button_State == 2){
Serial.println("Yellow light is ON");
// digitalWrite(Led_Y, HIGH);
// digitalWrite(Led_G, LOW);
// digitalWrite(Led_R, LOW);
*port_h &= ~(1 << PH6);
*port_h &= ~(1 << PH4);
*port_h |= (1 << PH5);
}
else if (Button_State == 3){
Serial.println("Green light is ON");
// digitalWrite(Led_G, HIGH);
// digitalWrite(Led_Y, LOW);
// digitalWrite(Led_R, LOW);
*port_h &= ~(1 << PH6);
*port_h &= ~(1 << PH5);
*port_h |= (1 << PH4);
}

else if(Button_State == 0){
// digitalWrite(Led_R, LOW);
// digitalWrite(Led_Y, LOW);
// digitalWrite(Led_G, LOW);
*port_h &= ~(1 << PH6);
*port_h &= ~(1 << PH5);
*port_h &= ~(1 << PH4);

}
  if(Button_State >= 3){
    Button_State = 0;
  }
  else{
  Button_State++;
  }
}
}
last_Button_State = *pin_b & (1 << PB4);
}