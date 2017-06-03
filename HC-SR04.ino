const int TRIG_PIN = 12;
const int ECHO_PIN = 13;

void setup() {
// Inizializza la comunicazione seriale:
Serial.begin(9600);

pinMode(TRIG_PIN,OUTPUT);
pinMode(ECHO_PIN,INPUT);
}

void loop()
{
long durata, distanza;

// Generiamo un segnale per la rilevazione
digitalWrite(TRIG_PIN, LOW);
delayMicroseconds(2);
digitalWrite(TRIG_PIN, HIGH);
delayMicroseconds(10);
digitalWrite(TRIG_PIN, LOW);
// Leggiamo il tempo che ci mette il segnale a tornare indietro
durata = pulseIn(ECHO_PIN,HIGH);

// Converti il tempo in distanza:
distanza = 0.034 * durata / 2 ;

// Nel caso il segnale sia minore di zero
if (distanza <= 0){
Serial.println("Out of range");
}
else {
// Stampiamo il risaluto su la seriale
Serial.print(distanza);
Serial.println("cm");
Serial.println();
}
delay(1000);
}
