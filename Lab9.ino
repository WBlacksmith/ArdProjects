const int SwP  = 8;
unsigned long preTime = 0;
int swS = 0;
int preswS = 0;
long interval = 60;
int led = 2;

void setup() {
  for(int x = 2; x<8; x++){
    pinMode (x, OUTPUT);
    }
pinMode (SwP, INPUT);
}

void loop() {
unsigned long curTime = millis();
if(curTime - preTime < interval){
  preTime = curTime;
  digitalWrite (led, HIGH);
  led++;
  if (led == 7){
    }
    swS = digitalRead(SwP);
    if (swS != preswS){
      for(int x = 2; x<8; x++){
    digitalWrite (x, LOW);
    }
    led = 2;
      }
  preTime = curTime;
  }

}
