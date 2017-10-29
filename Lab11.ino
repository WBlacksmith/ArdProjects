#include <LiquidCrystal.h>
LiquidCrystal lcd(12, 11, 5, 4, 3, 2);

const int swP = 6;
int swS = 0;
int preswS = 0;
int reply;

void setup()
{
  lcd.begin(16, 2);
  pinMode(swP, INPUT);
  lcd.print("Hello World!");
  lcd.setCursor(0,1);
  lcd.print("crystal ball!");
}

void loop()
{
  
  swS = digitalRead(swP);
  
  if(swS != preswS) {
    if (swS == LOW) {
      reply = random(8);
      lcd.clear();
      lcd.setCursor(0,0);
      lcd.print("The ball Says");
      lcd.setCursor(0,1);
      
      switch(reply) {
        case 0:
        lcd.print("Yes");
        break;
        case 1:
        lcd.print("Most likely");
        break;
        case 2:
        lcd.print("Certainly");
        break;
        case 3:
        lcd.print("Outlook Good");
        break;
        case 4:
        lcd.print("Unsure");
        break;
        case 5:
        lcd.print("Ask Again");
        break;
        case 6:
        lcd.print("doubtful");
        break;
        case 7:
        lcd.print("No");
        break;
      }
    }
  }
  preswS = swS;
}
