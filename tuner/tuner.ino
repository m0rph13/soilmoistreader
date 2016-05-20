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
    Serial.println(readSensor(moistSensorPins[moistSensorPin]));
  }
  delay(delayInMinis);
}

int readSensor(int moistSensorPin)
{
  return analogRead(moistSensorPin);  
}

