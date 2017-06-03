int analogInPin = A0;
int sensorValue = 0;

void setup() {
	Serial.begin(9600);
}

void loop() {
// legge la tensione sul pin analogico
	sensorValue = analogRead(analogInPin);

	Serial.print("sensor = " );
	Serial.println(sensorValue);

delay(1000);
}
