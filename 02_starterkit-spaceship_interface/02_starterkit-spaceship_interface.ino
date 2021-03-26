int GREEN_LED_PIN = 3;
int RED_LED_PINS[] = {4, 5};
int LED_OUTPUT_PINS[] = {
  GREEN_LED_PIN,
  RED_LED_PINS[0],
  RED_LED_PINS[1]
  };
int BBUTTON_INPUT_PIN = 2;
int switchState = 0;
void setup() {
  pinMode(BBUTTON_INPUT_PIN, INPUT);
for (int i = 0; i < sizeof(LED_OUTPUT_PINS); i+=1) {
  pinMode(i,OUTPUT);
}
}
void turnOnGreenLed(){
  digitalWrite(GREEN_LED_PIN, HIGH);
  digitalWrite(RED_LED_PINS[0], LOW);
  digitalWrite(RED_LED_PINS[1], LOW);
}
void blinkRedLeds() {
  delay(250);
  digitalWrite(RED_LED_PINS[0], HIGH);
  digitalWrite(RED_LED_PINS[1], LOW);
  delay(250);
  digitalWrite(RED_LED_PINS[0], LOW);
  digitalWrite(RED_LED_PINS[1], HIGH);
  digitalWrite(GREEN_LED_PIN, LOW);
}
void loop() {
  switchState = digitalRead(BBUTTON_INPUT_PIN);
  if(switchState == LOW) {
    turnOnGreenLed();
  }else{
    blinkRedLeds();
  }
}
