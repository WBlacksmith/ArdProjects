const int greenLedPin = 9;
const int redLedPin = 11;
const int blueLedPin = 10;

const int greenSensorPin = A0;
const int redSensorPin = A1;
const int blueSensorPin = A2;

int greenValue = 0;
int redValue = 0;
int blueValue = 0;

int greenSensorValue = 0;
int redSensorValue = 0;
int blueSensorValue = 0;
void setup() {
  Serial.begin(9600);
  pinMode(greenLedPin, OUTPUT);
  pinMode(redLedPin, OUTPUT);
  pinMode(blueLedPin, OUTPUT);
}

void loop() {
 greenSensorValue = analogRead (greenSensorPin);
 delay (5);
 redSensorValue = analogRead (redSensorPin);
 delay (5);
 blueSensorValue = analogRead (blueSensorPin);
 delay (5);

  Serial.print("Sensor G:");
  Serial.print(greenSensorValue);
  Serial.print("Sensor R:");
  Serial.print(redSensorValue);
  Serial.print("Sensor B:");
  Serial.println(blueSensorValue);

  greenValue = (greenSensorValue)/4;
  redValue = (redSensorValue)/4;
  blueValue = (blueSensorValue)/4;

  Serial.print("Sensor G:");
  Serial.print(greenValue);
  Serial.print("Sensor R:");
  Serial.print(redValue);
  Serial.print("Sensor B:");
  Serial.println(blueValue);

  analogWrite(greenLedPin, greenValue);
  analogWrite(redLedPin, redValue);
  analogWrite(blueLedPin, blueValue);
}
