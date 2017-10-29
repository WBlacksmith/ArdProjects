#include <Servo.h>
Servo myServo;

const int piezo = A0;
const int swP = 2;
const int yellow = 3;
const int green = 4;
const int red = 5;

int knockVal;
int swV;
const int quietKnock = 10;
const int loudKnock = 100;

boolean locked = false;
int numKnocks = 0;

void setup()
{
  myServo.attach(9);
  pinMode(swP, INPUT);
  pinMode(yellow, OUTPUT);
  pinMode(green, OUTPUT);
  pinMode(red, OUTPUT);
  
  digitalWrite(green, HIGH);
        Serial.begin(9600);
  myServo.write(0);
  Serial.println("The box is unlocked!");
}

void loop()
{
  if(locked == false) {
    swV = digitalRead(swP);
    
    if(swV == HIGH) {
      locked = true;
      digitalWrite(green, LOW);
      digitalWrite(red, LOW);
      myServo.write(90);
      Serial.println("The box is Locked");
      delay(1000);
    } 
  }
  if(locked == true) {
    knockVal = analogRead(piezo);
    if(numKnocks < 3 && knockVal > 0) {
      if(checkForKnock(knockVal) == true) {
        numKnocks++;
      }
      Serial.print(3 - numKnocks);
      Serial.println(" more knocks to go");
    }
    if(numKnocks >= 3) {
      locked = false;
      myServo.write(0);
      delay(20);
      digitalWrite(green, HIGH);
      digitalWrite(red, LOW);
      Serial.println("The box is unlocked");
                        numKnocks = 0;
    }
  }
}

boolean checkForKnock(int value) {
  if(value > quietKnock && value < loudKnock) {
    digitalWrite(yellow, HIGH);
    delay(50);
    digitalWrite(yellow, LOW);
    Serial.print("Valid Knock of value ");
    Serial.println(value);
    return true;
  }
  else {
    Serial.print("Bad knock Value ");
    Serial.println(value);
    return false;
  }
}
