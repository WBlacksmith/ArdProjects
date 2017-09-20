const int sensorPin = A0;
const float BLTemp = 28.0;
void setup() {
  Serial.begin(9600);
  for(int pinNum = 2; pinNum < 5; pinNum++){
    pinMode(pinNum, OUTPUT);
    digitalWrite(pinNum, LOW);
    }
}

void loop() {
  int senVal = analogRead (sensorPin);
  Serial.print("Sensor:");
  Serial.print(senVal);
  float voltage = (senVal/1024.0) * 5.0;
  Serial.print("Voltage:");
  Serial.print(voltage);
  float temp = (voltage - 0.5) * 100;
  Serial.print("Temperature:");
  Serial.print(temp);
  if (temp < BLTemp){
    digitalWrite(2, HIGH);
    digitalWrite(3, LOW);
    digitalWrite(4, LOW);
    }
    else if(temp >= BLTemp+1 && temp < BLTemp+1.5){
      digitalWrite(2, LOW);
      digitalWrite(3, HIGH);
      digitalWrite(4, LOW);
    }
    else if(temp >= BLTemp+1.5 && temp < BLTemp+1.75){
      digitalWrite(2, LOW);
      digitalWrite(3, LOW);
      digitalWrite(4, HIGH);
    }
    else if(temp >= BLTemp+2){      
      digitalWrite(2, LOW);
      digitalWrite(3, LOW);
      digitalWrite(4, LOW);
      delay (150);
      digitalWrite(2, LOW);
      digitalWrite(3, LOW);
      digitalWrite(4, HIGH);
      delay (150);     
    }
}
