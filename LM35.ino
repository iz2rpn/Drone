#define potPin  A0

void setup()
{
  Serial.begin(9600);
}
void loop ()                             
{
  int aRead = 0;
  aRead = analogRead(potPin);

  Serial.print("Analog = ");
  Serial.print(aRead);
 
  float tempC = aRead * 0.48875;
 
  Serial.print("     Temp = ");
  Serial.println(tempC);
  delay(1000);
}
