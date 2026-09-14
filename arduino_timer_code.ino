#include <LiquidCrystal.h>
const int rs = 2, en = 3, d4 = 4, d5 = 5, d6 = 6, d7 = 7;
LiquidCrystal lcd(rs, en, d4, d5, d6, d7);
//boolian variables mode of timer(secounds or minutes)
bool minute_mode = false;
bool secounde_mode = false;
//some variables for input time from the user
  int minutes = 0;
  int secounds = 0;
//this variable for set status of start/reset button
  int start = 3;
//this variable for fixing the LCD bug
  int i = 1;
//some variables for buttons
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
  //setting up the LCD
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
  //when the minute_mode = true,the timer mode sets in minute mode
  while(minute_mode == true){
    if(i == 1){
      //setting up the LCD
      lcd.clear();
      lcd.setCursor(0,0);
      lcd.print("time:");
      lcd.setCursor(5,0);
      lcd.print(minutes);
      lcd.setCursor(0,1);
      lcd.print("mode:minutes");
      delay(250);
    }
    //some if functions to make buttons work
    if(digitalRead(plus_button) == HIGH){
      minutes = minutes + 1;
      
    }
    if(digitalRead(minus_button) == HIGH && minutes > 0){
      minutes = minutes - 1;
      
    }
    //if the start button is pressd,counting down loop starts
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
       //this section of the code is for,when the counting is complete,its start beeping and break the countinuing the count for the preventing bugs
      if(secounds == 0){
        lcd.clear();
        lcd.setCursor(3,0);
        lcd.print("TIME IS UP");
        secounds = 0;
        delay(300);
        digitalWrite(buzzer,HIGH);
      }
      //this section of code is for reseting the program
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
    //when the secounde_mode = true,the timer mode sets in secounde mode
  while(secounde_mode == true){
    if(i == 1){
      //setting up the LCD
      lcd.clear();
      lcd.setCursor(0,0);
      lcd.print("time:");
      lcd.setCursor(5,0);
      lcd.print(secounds);
      lcd.setCursor(0,1);
      lcd.print("mode:secounds");
      delay(250);
    }
    //some if functions to make buttons work
    if(digitalRead(plus_button) == HIGH){
      secounds = secounds + 1;
      
    }
    if(digitalRead(minus_button) == HIGH && secounds > 0){
      secounds = secounds - 1;
      
    }
    //if the start button is pressd,counting down loop starts
    if(digitalRead(start_button) == HIGH){
      start = 1;
      i = 0;
    }   
    if(start == 1){

      if(secounds > 0){
        //setting up the LCD
        lcd.clear();
        lcd.setCursor(0,0);
        lcd.print("countdown:");
        lcd.setCursor(10,0);
        lcd.print(secounds);
        secounds = secounds - 1;
        delay(1000);
      }
      //this section of the code is for,when the counting is complete,its start beeping and break the countinuing the count for the preventing bugs
      if(secounds == 0){
        lcd.clear();
        lcd.setCursor(3,0);
        lcd.print("TIME IS UP");
        start = 3;
        digitalWrite(buzzer,HIGH);
      }
      //this section of code is for reseting the program
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
