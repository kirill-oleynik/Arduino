const int greenLEDPin = 9;
const int redLEDPin = 11;
const int blueLEDPin = 10;
int outputPins[] = {
  greenLEDPin,
  redLEDPin,
  blueLEDPin
};

const int redSensorPin = A0;
const int greenSensorPin = A1;
const int blueSensorPin = A2;

int RedValue = 0;
int greenValue = 0;
int blueValue = 0;

int redSensorValue = 0;
int greenSensorValue = 0;
int blueSensorValue = 0;

const int ADCmillisecondsTimeout = 5;

void setup() {
 for(int i = 0; i <= sizeof(outputPins); i+=1 ) {
  pinMode(outputPins[i],OUTPUT);
 }
}


void loop() {
  redSensorValue = analogRead(redSensorPin);
  delay(5);
  greenSensorValue = analogRead(greenSensorPin);
  delay(5);
  blueSensorValue = analogRead(blueSensorPin);

  Serial.print("Raw sensor values \t Red: ");
  Serial.print(redSensorValue);
  Serial.print("\t Green: ");
  Serial.print(greenSensorValue);
  Serial.print("\t Blue: ");
  Serial.print(blueSensorValue);

  RedValue = redSensorValue / 4;
  greenValue = greenSensorValue / 4;
  blueValue = blueSensorValue / 4;

  Serial.print("Mapped Sensor Values \t Red: ");
  Serial.print(RedValue);
  Serial.print("Green: \t");
  Serial.print(greenValue);
  Serial.print("Blue: \t");
  Serial.print(blueValue);

  analogWrite(redLEDPin, RedValue);
  analogWrite(greenLEDPin, greenValue);
  analogWrite(blueLEDPin, blueValue);
}
