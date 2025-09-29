// MD Islam
// CPE 301 – Lab 3 Part 2


#define RED_MASK_H    0x40  // PH6
#define YELLOW_MASK_H 0x20  // PH5
#define GREEN_MASK_H  0x10  // PH4
#define BLUE_MASK_B   0x10  // PB4
unsigned char* ddr_b  = (unsigned char*)0x24;   // DDRB
unsigned char* port_b = (unsigned char*)0x25;   // PORTB

unsigned char* ddr_h  = (unsigned char*)0x101;  // DDRH
unsigned char* port_h = (unsigned char*)0x102;  // PORTH

void setup() {
  Serial.begin(9600);
  Serial.println("Traffic Light (Register-Level GPIO)");

  *ddr_h |= (RED_MASK_H | YELLOW_MASK_H | GREEN_MASK_H); // PH6, PH5, PH4
  *ddr_b |= BLUE_MASK_B;                                 // PB4
  *port_h &= ~(RED_MASK_H | YELLOW_MASK_H | GREEN_MASK_H);
  *port_b &= ~BLUE_MASK_B;
}

void loop() {
  Serial.println("Red light is ON");
  *port_h |= RED_MASK_H;
  unsigned long t0 = millis();
  while (millis() - t0 < 5000UL) {
    *port_b ^= BLUE_MASK_B;
    delay(250);
  }
  *port_b &= ~BLUE_MASK_B;
  *port_h &= ~RED_MASK_H;

  Serial.println("Yellow light is ON");
  *port_h |= YELLOW_MASK_H;
  delay(3000);
  *port_h &= ~YELLOW_MASK_H;

  Serial.println("Green light is ON");
  *port_h |= GREEN_MASK_H;
  delay(5000);
  *port_h &= ~GREEN_MASK_H;
}


