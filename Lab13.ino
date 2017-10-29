#include <CapacitiveSensor.h>
CapacitiveSensor capSensor = CapacitiveSensor(4,2);

int tsho = 1000;
const int LP = 12;

void setup()
{
  Serial.begin(9600);
  pinMode(LP, OUTPUT);
}

void loop()
{
  long sensorValue = capSensor.capacitiveSensor(30);
  Serial.println(sensorValue);
  
  if(sensorValue > tsho) {
    digitalWrite(LP, HIGH);
  } else {
    digitalWrite(LP, LOW);
  }
  delay(10);
}

