int freq[] = {262, 294, 330, 349};

void setup() {

  Serial.begin(9600);
}

void loop() {
  int value = analogRead(A0);
  Serial.println(value);
  if(value == 1023){
    tone(8, freq[0]);
  }
  else if(value >= 990 && value <= 1010){
    tone(8, freq[1]);
  }
  else if(value >= 505 && value <= 515){
    tone(8, freq[2]);
  }
  else if(value >= 5 && value <= 10){
    tone(8, freq[3]);
  }
  else{
    noTone(8);
  }
}
  
