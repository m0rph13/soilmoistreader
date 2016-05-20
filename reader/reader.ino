int moistSensorPins[] = {A1};
int delayInMinis=5000;
double extremeDryValues[]={1018.0};
double extremeWetValues[]={113.0};

void setup() 
{
  Serial.begin(9600);
}

void loop() 
{
  for (int i = 0; i < (sizeof(moistSensorPins)/sizeof(int)); i++) 
  {
    Serial.print("Pin ");
    Serial.print(moistSensorPins[i]);
    Serial.print(" = ");
    Serial.print(readSensor(moistSensorPins[i], extremeDryValues[i], extremeWetValues[i]));
    Serial.println(" %");
  }
  delay(delayInMinis);
}

double readSensor(int moistSensorPin, double extremeDry, double extremeWet)
{
  int sensorValue = analogRead(moistSensorPin);
  double percentage=100*(1.0-((sensorValue-extremeWet)/(extremeDry-extremeWet)));
  return percentage;
}

