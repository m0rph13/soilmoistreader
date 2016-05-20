int moistSensorPins[] = {A1};
int delayInMinis=5000;

void setup() 
{
  Serial.begin(9600);
}

void loop() 
{
  for (int moistSensorPin = 0; moistSensorPin < (sizeof(moistSensorPins)/sizeof(int)); moistSensorPin++) 
  {
    Serial.print("Pin ");
    Serial.print(moistSensorPins[moistSensorPin]);
    Serial.print(" = ");
    Serial.print(readSensor(moistSensorPins[moistSensorPin]));
    Serial.println(" %");
  }
  delay(delayInMinis);
}

double readSensor(int moistSensorPin)
{
  int sensorValue = analogRead(moistSensorPin);
  double percentage=100*(1.0-(sensorValue/1024.0));
  return percentage;
}

