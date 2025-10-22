//Need to send data,
/*
  define
  0x00	Brake light
  0x01	Reverse light
  0x02	Left turn signal
  0x03	Right turn signal
  0x04	Hazard mode (overide)
  0x05	Rear light on
  0x06	
  0x07	
  0x08	
  0x09	
  0x0A	
  0x0B	
  0x0C	
  0x0D	
  0x0E	
  0x0F	
*/

#define btn1 3
#define reverseInput 4;
#define rearlightSwitch 5;
#define leftSignal 6;
#define rightSignal 7l

unsigned long previousMillisTask1 = 0;
const long intervalTask1 = 50; 

unsigned long previousMillisTask2 = 0;
const long intervalTask2 = 100; 

unsigned long previousMillisTask3 = 0;
const long intervalTask3 = 1000;

void setup() {
  Serial.begin(115200);
  pinMode(btn1, INPUT_PULLUP);
  pinMode(reverseInput, INPUT_PULLUP);
  pinMode(rearlightSwitch, INPUT_PULLUP);
  pinMode(leftSignal, INPUT_PULLUP);
  pinMode(rightSignal, INPUT_PULLUP);
}

void loop() {
  unsigned long currentMillis = millis();

  if (currentMillis - previousMillisTask1 >= intervalTask1) {
    previousMillisTask1 = currentMillis;
    //high responsive
    Serial.print(brakeLight());
    Serial.print(leftSignal());
    Serial.print(rightSignal());
    Serial.println();
  }

  if (currentMillis - previousMillisTask2 >= intervalTask2) {
    previousMillisTask2 = currentMillis;
    
  }

  if (currentMillis - previousMillisTask3 >= intervalTask3) {
    previousMillisTask3 = currentMillis;
    //No rush system
    Serial.print(reverseLight());
    Serial.println();
  }
}

const char* brakeLight(){
  btnInput = digitalRead(btn1);
  state = "00";
  if(btnInput == HIGH){
    state = "01";
  }
  else{
    state = "00";
  }
  return "0x00"+state;
}

const char* reverseLight(){
  rInput = digitalRead(reverseInput);
  state = "00";
  if(rInput == HIGH){
    state = "01";
  }
  else{
    state = "00"
  }
  return "0x01"+state;
}

const char* rearLight(){
  rsInput = digitalRead(rearlightSwitch);
  state = "00";
  if(rsInput == HIGH){
    state = "01";
  }
  else{
    state = "00"
  }
  return "0x05"+state;
}

const char* leftSignal(){
  leftSig = digitalRead(leftSignal);
  state = "00";
  if(leftSig == HIGH){
    state = "01";
  }
  else{
    state = "00";
  }
  return "0x02"+state;
}

const char* rightSignal(){
  rightSig = digitalRead(rightSignal);
  state = "00";
  if(rightSig == HIGH){
    state = "01";
  }
  else{
    state = "00";
  }

  return "0x03"+state;
}