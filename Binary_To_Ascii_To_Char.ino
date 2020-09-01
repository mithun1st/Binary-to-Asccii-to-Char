#include <LiquidCrystal.h>

LiquidCrystal lcd(33, 31, 29, 27, 25, 23);

int b1 , b2 , b3 , b4 , b5 , b6 , b7 , b8 , vari = 0, ascii = 0;
const int buz = 36;

void setup() {
  // put your setup code here, to run once:
  pinMode(b1, INPUT);
  pinMode(b2, INPUT);
  pinMode(b3, INPUT);
  pinMode(b4, INPUT);
  pinMode(b5, INPUT);
  pinMode(b6, INPUT);
  pinMode(b7, INPUT);
  pinMode(b8, INPUT);

  pinMode(buz, OUTPUT);

  lcd.begin(16, 2);

  Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
  binaryInput();
  ascii = (pow(2, 7) * b8 + pow(2, 6) * b7 + pow(2, 5) * b6 + pow(2, 4) * b5 + pow(2, 3) * b4 + pow(2, 2) * b3 + pow(2, 1) * b2 + pow(2, 0) * b1);

  lcd.setCursor(0, 0);
  lcd.print("Bin= " + String(b8) + "" + String(b7) + "" + String(b6) + "" + String(b5) + " " + String(b4) + "" + String(b3) + "" + String(b2) + "" + String(b1));

  lcd.setCursor(0, 1);
  lcd.print("Asc= " + String(ascii));
  lcd.setCursor(10, 1);
  lcd.print("Chr= " + String(char(ascii)));

  if(ascii!=vari){
    digitalWrite(buz,1);
    delay(100);
    digitalWrite(buz,0);
  }
  
  Serial.println(String(b8) + "" + String(b7) + "" + String(b6) + "" + String(b5) + " " + String(b4) + "" + String(b3) + "" + String(b2) + "" + String(b1));
  Serial.println(ascii);
  Serial.println(char(ascii));
  delay(500);

  vari = ascii;
  lcd.clear();
}

void binaryInput() {
  b1 = digitalRead(A7);
  b2 = digitalRead(A6);
  b3 = digitalRead(A5);
  b4 = digitalRead(A4);
  b5 = digitalRead(A3);
  b6 = digitalRead(A2);
  b7 = digitalRead(A1);
  b8 = digitalRead(A0);
}
