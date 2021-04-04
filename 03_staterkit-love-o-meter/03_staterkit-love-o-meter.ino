const int temperatureSensorPin = A0;
const float baselineTemp = 20.0;
const int connectionSpeedBitsPerSecond = 9600;
const int ledOutputPins[] = {2,3,4};
void writePinsState(int pinNumbers[], int state){
  for(int i = 0;i < sizeof(pinNumbers); i++){
    digitalWrite(pinNumbers[i],state);
  }
}
void setup(){
  Serial.begin(connectionSpeedBitsPerSecond);
  for(int pin = 0; pin < sizeof(ledOutputPins); pin++){
    pinMode(ledOutputPins[pin], OUTPUT);
    digitalWrite(ledOutputPins[pin], LOW);
  }
}
float calcTemperatureSensorPinVoltage(int sensorValue){
  const float sensorValuesRange = 1024.0;
  const float possibleVoltageRange = 5.0;
  return((sensorValue / sensorValuesRange) * possibleVoltageRange);
}
int calcTemperatureInCelcius(float voltage){
  const float belowFreesingValuesVoltageOffset = .5;
  const int celsiusRange = 100;
  return((voltage - belowFreesingValuesVoltageOffset) * celsiusRange);
}
bool noLove(float comparebale, float base){
  return(comparebale < base);
}
bool middleLove(float comparebale, float base){
  return(comparebale >= base + 2 && comparebale < base + 4);
}
bool fullLove(float comparebale, float base){
return(comparebale >= base + 4 && comparebale < base + 6);
}
bool evenMoreThanLove(float comparebale, float base){
}

void loop(){
  int sensorValue = analogRead(temperatureSensorPin);
  float voltage = calcTemperatureSensorPinVoltage(sensorValue);
  float temperature = calcTemperatureInCelcius(voltage);
  Serial.print("Degrees C: ");
  Serial.println(temperature);
  if(noLove(temperature, baselineTemp)){
    writePinsState(ledOutputPins,LOW);
  }else if(middleLove(temperature, baselineTemp)){
    digitalWrite(2,HIGH);
    digitalWrite(3,LOW);
    digitalWrite(4,LOW);
  }else if(fullLove(temperature, baselineTemp)){
    digitalWrite(2,HIGH);
    digitalWrite(3,HIGH);
    digitalWrite(4,LOW);
  } else if(evenMoreThanLove(temperature, baselineTemp)) {
    writePinsState(ledOutputPins,HIGH);
  }
  delay(1);
}
