#include <LiquidCrystal.h>
#include <Keypad.h>

const int ROW_NUM = 4; //four rows
const int COLUMN_NUM = 4; //four columns

char keys[ROW_NUM][COLUMN_NUM] = {
  {'1','2','3', 'A'},
  {'4','5','6', 'B'},
  {'7','8','9', 'C'},
  {'*','0','#', 'D'}
};

byte pin_rows[ROW_NUM] = {48, 46, 44, 42}; //connect to the row pinouts of the keypad
byte pin_column[COLUMN_NUM] = {40, 38, 36, 34}; //connect to the column pinouts of the keypad

Keypad keypad = Keypad( makeKeymap(keys), pin_rows, pin_column, ROW_NUM, COLUMN_NUM );

// LCD pins <--> Arduino pins
const int RS = 11, EN = 12, D4 = 2, D5 = 3, D6 = 4, D7 = 5;
int right=0,up=0;
int dir1=0,dir2=0;
byte customChar[8] = {
  0b00000,
  0b01010,
  0b11111,
  0b11111,
  0b01110,
  0b00100,
  0b00000,
  0b00000
};

byte customChar2[8] = {
  0b00000,
  0b00000,
  0b01110,
  0b01110,
  0b01110,
  0b00000,
  0b00000,
  0b00000
};
LiquidCrystal lcd(RS, EN, D4, D5, D6, D7);

int targetRow = 1;
int targetCol = 5;

void setup()

{
  Serial.begin(9600);
  lcd.begin(16, 2); // set up number of columns and rows

  lcd.createChar(1, customChar); // create a new custom character

  lcd.setCursor(0, 0); // move cursor to (2, 0)
  lcd.write((byte)1);  // print the custom char at (2, 0)
  
  lcd.createChar(2, customChar2); // create a new custom character
  lcd.setCursor(5, 1); // move cursor to (2, 0)
  lcd.write((byte)2);  // print the custom char at (2, 0)

    lcd.setCursor(9, 1); // move cursor to (2, 0)
  lcd.write((byte)2);  // print the custom char at (2, 0)

    lcd.setCursor(6, 0); // move cursor to (2, 0)
  lcd.write((byte)2);  // print the custom char at (2, 0)
    lcd.setCursor(15, 1); // move cursor to (2, 0)
  lcd.write((byte)2);  // print the custom char at (2, 0)

  lcd.setCursor(targetCol, targetRow);
  lcd.setCursor(right, up);
  
}

void loop()
{
  char key = keypad.getKey();

  if (key) {
    if (key == '4') right--;   // left
    if (key == '6') right++;   // right
    if (key == '2') up--;      // up
    if (key == '8') up++;      // down

    if (right > 15) right = 0;
    if (right < 0) right = 15;

    if (up > 1) up = 0;
    if (up < 0) up = 1;

    lcd.clear();

    lcd.setCursor(targetCol, targetRow);
    lcd.write((byte)2);
    lcd.setCursor(9, 1);
    lcd.write((byte)2);
    lcd.setCursor(6, 0);
    lcd.write((byte)2);
    lcd.setCursor(15, 1);
    lcd.write((byte)2);

    lcd.setCursor(right, up);
    lcd.write((byte)1);

    if ((right == targetCol && up == targetRow) ||
        (right == 9 && up == 1) ||
        (right == 6 && up == 0) ||
        (right == 15 && up == 1)) {
      Serial.println("You scored!");
    }

    Serial.print("Key pressed: ");
    Serial.println(key);
  }
}


  

   

    

      

}

