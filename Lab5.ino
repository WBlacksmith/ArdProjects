#include <Servo.h>
Servo MyServo;
int const PinPot=A0;
int ValuePot;
int Angle;
void setup() {
 MyServo.attach(9);
 Serial.begin(9600);
}

void loop() {
 ValuePot=analogRead(PinPot);
 Serial.print("Potentiometer position:");
 Serial.print(ValuePot);
 Angle=map(ValuePot,0,1023,0,179);
 Serial.print(", Angle: ");
 Serial.print(Angle);
}
