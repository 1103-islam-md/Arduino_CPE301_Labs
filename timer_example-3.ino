// Lab 5 Justyce Hickman Md Islam
// Speaker output PB6, Port B, Bit 6 Digital Pin 12
volatile unsigned char *myTCCR1A = (unsigned char *) 0x80;
volatile unsigned char *myTCCR1B = (unsigned char *) 0x81;
volatile unsigned char *myTCCR1C = (unsigned char *) 0x82;
volatile unsigned char *myTIMSK1 = (unsigned char *) 0x6F;
volatile unsigned int  *myTCNT1  = (unsigned  int *) 0x84;
volatile unsigned char *myTIFR1 =  (unsigned char *) 0x36;
volatile unsigned char *portDDRB = (unsigned char *) 0x24;
volatile unsigned char *portB =    (unsigned char *) 0x25;
unsigned int currentFreq = 0;
bool playing = false;
void my_delay(unsigned int freq)
{
  // freq = desired frequency
  // calc period = twave = 1 / fwave(freq)
  double period = 1.0/double(freq);
  // 50% duty cycle
  double half_period = period / 2;
  // clock period def
  double clk_period = 0.0000000625;
  // calc ticks
  unsigned int ticks = half_period / clk_period;
  // stop the timer
  *myTCCR1B &= 0xF8;
  // set the counts
  *myTCNT1 = (unsigned int) (65536 - ticks); //check slide
  * myTCCR1A = 0x0;
  // start the timer
  * myTCCR1B |= 0x05;
  // wait for overflow
  while((*myTIFR1 & 0x01)==0); 
  // stop the timer
  *myTCCR1B &= 0xF8;   
  // reset TOV           
  *myTIFR1 |= 0x01;
}
void runTimer(unsigned char c){
  switch (c) {
    case 'A':
      Serial.println("A pressed");
      currentFreq = 440;
      playing = true;
    break;
    case 'B':
      Serial.println("B pressed");
      currentFreq = 494;
      playing = true;

    break;
    case 'C':
      Serial.println("C pressed");
      currentFreq = 523;
      playing = true;
    break;
    case 'D':
      Serial.println("D pressed");
      currentFreq = 587;
      playing = true;
    break;
    case 'E':
      Serial.println("E pressed");
      currentFreq = 659;
      playing = true;
    break;
    case 'F':
      Serial.println("F pressed");
      currentFreq = 698;
      playing = true;
    break;
    case 'G':
      Serial.println("G pressed");
      currentFreq = 784;
      playing = true;
    break;
    case 'Q':
      Serial.println("Q pressed");
      playing = false;
      *portB &= ~(1 << PB6); // low
    break;
    default:
    break;
  }
}
void setup() {
  Serial.begin(9600);
  *portDDRB |= (1 << PB6);
  Serial.println("Setup");
  *portB &= ~(1 << PB6);
}
void loop() {
  // if the UART received a character
  if(Serial.available())
  {
    // read in the character
    unsigned char in_char = Serial.read();
    // write the character back to the Serial Port
    runTimer(in_char);
  }

  if(playing && currentFreq > 0){
    *portB ^= (1 << PB6);
    my_delay(currentFreq);
  }
}