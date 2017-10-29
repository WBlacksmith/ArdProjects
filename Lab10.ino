const int cp1 = 2; 
const int cp2 = 3;
const int enp = 9; 
const int dirSwP = 4;
const int onofSwP = 5; 
const int potPin = A0;  


int onofSwS = 0;  
int prevonofSwS = 0; 
int dirSwS = 0;  
int predirSwS = 0;  

int motorEnabled = 0; 
int motorSpeed = 0; 
int motorDirection = 1; 

void setup(){
  pinMode(dirSwP, INPUT);
  pinMode(onofSwP, INPUT);
  pinMode(cp1, OUTPUT);
  pinMode(cp2, OUTPUT);
  pinMode(enp, OUTPUT);

  digitalWrite(enp, LOW);
}

void loop(){
  onofSwS = digitalRead(onofSwP);
  delay(1);
  
  dirSwS = digitalRead(dirSwP);
  
  motorSpeed = analogRead(potPin)/4; 

  if(onofSwS != prevonofSwS){
    if(onofSwS == HIGH){
      motorEnabled = !motorEnabled;
    }
  }

  if (dirSwS != predirSwS) {
    if (directionSwitchState == HIGH) {
      motorDirection = !motorDirection;
    }
  }  

  if (motorDirection == 1) {
    digitalWrite(cp1, HIGH);
    digitalWrite(cp2, LOW);
  } 
  else {
    digitalWrite(cp1, LOW);
    digitalWrite(cp2, HIGH);
  }  

  if (motorEnabled == 1) {
    analogWrite(enp, motorSpeed);
  }
  else { 
    analogWrite(enp, 0);
  }
  predirSwS = dirSwS;
  prevonofSwS = onofSwS;
}
