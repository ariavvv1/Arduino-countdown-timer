#include <LiquidCrystal.h>
const int rs = 2, en = 3, d4 = 4, d5 = 5, d6 = 6, d7 = 7;
LiquidCrystal lcd(rs, en, d4, d5, d6, d7);
bool minute_mode = false;
bool secounde_mode = false;
  int minutes = 0;
  int secounds = 0;
  int start = 3;
  int i = 1;
  const int plus_button = 8;
  const int minus_button = 9;
  const int minute_mode_button = 10;
  const int start_button = 11;
  const int secounde_mode_button = 12;
  const int buzzer = 13 ;
void setup() {
  lcd.begin(16, 2);
  pinMode(buzzer,OUTPUT);
  pinMode(plus_button,INPUT);
  pinMode(minus_button,INPUT);
  pinMode(minute_mode_button,INPUT);
  pinMode(start_button,INPUT);
}
void loop() {
  lcd.clear();
  lcd.setCursor(0,0);
  lcd.print("Choose mode");
  delay(300);
  if(digitalRead(minute_mode_button) == HIGH){
    minute_mode = true;
  }
   if(digitalRead(secounde_mode_button) == HIGH){
    secounde_mode = true;
  }
  while(minute_mode == true){
    if(i == 1){
      lcd.clear();
      lcd.setCursor(0,0);
      lcd.print("time:");
      lcd.setCursor(5,0);
      lcd.print(minutes);
      lcd.setCursor(0,1);
      lcd.print("mode:minutes");
      delay(250);
    }
    if(digitalRead(plus_button) == HIGH){
      minutes = minutes + 1;
      
    }
    if(digitalRead(minus_button) == HIGH && minutes > 0){
      minutes = minutes - 1;
      
    }
    if(digitalRead(start_button) == HIGH && i == 1){
      start = 1;
      secounds = minutes * 60;
      i = 0;
    }
    if(start == 1){
      if(secounds > 0){
        lcd.clear();
        lcd.setCursor(0,0);
        lcd.print("countdown:");
        lcd.setCursor(10,0);
        lcd.print(secounds);
        secounds = secounds - 1;
        delay(1000);
      }
      if(secounds == 0){
        lcd.clear();
        lcd.setCursor(3,0);
        lcd.print("TIME IS UP");
        secounds = 0;
        delay(300);
        digitalWrite(buzzer,HIGH);
      }
      if(digitalRead(start_button) == HIGH){
        minutes = 0;
        secounds = 0;
        start = 3;
        minute_mode = false;
        i = 1;
        digitalWrite(buzzer,LOW);
      }
    }
  }
  while(secounde_mode == true){
    if(i == 1){
      lcd.clear();
      lcd.setCursor(0,0);
      lcd.print("time:");
      lcd.setCursor(5,0);
      lcd.print(secounds);
      lcd.setCursor(0,1);
      lcd.print("mode:secounds");
      delay(250);
    }
    if(digitalRead(plus_button) == HIGH){
      secounds = secounds + 1;
      
    }
    if(digitalRead(minus_button) == HIGH && secounds > 0){
      secounds = secounds - 1;
      
    }
    if(digitalRead(start_button) == HIGH){
      start = 1;
      i = 0;
    }
    if(start == 1){

      if(secounds > 0){
        lcd.clear();
        lcd.setCursor(0,0);
        lcd.print("countdown:");
        lcd.setCursor(10,0);
        lcd.print(secounds);
        secounds = secounds - 1;
        delay(1000);
      }
      if(secounds == 0){
        lcd.clear();
        lcd.setCursor(3,0);
        lcd.print("TIME IS UP");
        start = 3;
        digitalWrite(buzzer,HIGH);
      }
      if(digitalRead(start_button) == HIGH){
        minutes = 0;
        secounds = 0;
        start = 3;
        secounde_mode = false;
        i = 1;
        digitalWrite(buzzer,LOW);
      }
    }
  }
}
