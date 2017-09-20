int sensorVal = 0;
int sensorLow = 1023;
int sensorHigh = 0;

const int ledPin = 13;

void setup() {
pinMode (ledPin, OUTPUT);
digitalWrite (ledPin, HIGH);
  while(millis() < 5000){
    sensorVal = analogRead(A0);
    if(sensorVal > sensorHigh){
      sensorHigh = sensorVal;
      }
      if(sensorVal < sensorLow){
      sensorLow = sensorVal;
      }
    }
    digitalWrite (ledPin, LOW);
}

void loop() {
  sensorVal = analogRead(A0);
  int pitch = map(sensorVal,sensorHigh, sensorLow, 50, 4000);
  tone (8, pitch, 20);
  delay (10);
}
