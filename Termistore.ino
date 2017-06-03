define Ro 1000 // Valore NTC a 25°C
#define NTCPIN A0 // Pin di collegamento NTC
#define Tnom 25 // Temperatura nominale NTC
#define B 3000 // Coeff. Beta della NTC (dai datasheet)
float Temp;
// Settaggio velocità dati seriali
void setup() {
 Serial.begin(9600);
}
// Ciclo infinito, programma principale
void loop() {
 Serial.print("Temp=");
 Serial.println(misTemp());
 delay(1000);
}
// Funzione che misura la temperatura
float misTemp() {
 Temp = analogRead(NTCPIN);
 Temp = Ro/((1023/Temp)-1);
 Temp = Temp / Ro; // (R/Ro)
 Temp = log(Temp); // ln(R/Ro)
 Temp = Temp/B; // 1/B * ln(R/Ro)
 Temp = Temp + 1.0 / (Tnom + 273.15); // + (1/To)
 Temp = 1.0 / Temp; // Invert
 Temp = Temp - 273.15; // convert to 
 }
