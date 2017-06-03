//Menù di controllo:
//
// 1 -Motore 1 Avanti
// 2 -Motore 1 Stop
// 3 -Motore 1 Indietro
//
// 4 -Motore 2 Avanti
// 5 -Motore 2 Stop
// 6 -Motore 2 Indietro

// Definisco le variabile per il Motore 1
int dir1PinA = 2;
int dir2PinA = 3;
int speedPinA = 9; // Definisco il pin per il controllo  di velocità con un segnale PWM

// Definisco le variabile per il Motore 1
int dir1PinB = 4;
int dir2PinB = 5;
int speedPinB = 10; // Definisco il pin per il controllo  di velocità con un segnale PWM

void setup() {  
// Inizializzo la porta seriale a 9600 boud:
Serial.begin(9600);

//Configuro i pin di arduino in uscita per pilotare L298N 

pinMode(dir1PinA,OUTPUT);
pinMode(dir2PinA,OUTPUT);
pinMode(speedPinA,OUTPUT);
pinMode(dir1PinB,OUTPUT);
pinMode(dir2PinB,OUTPUT);
pinMode(speedPinB,OUTPUT);

}

void loop() {

// Inizializzo l'interfaccia seriale in ascolto

if (Serial.available() > 0) {
int inByte = Serial.read();
int speed; // Variabile locale

switch (inByte) {

//______________Motore 1______________

case '1': // Motore 1 Avanti
analogWrite(speedPinA, 255);//Configurazione velocità del motore tramite PWM
digitalWrite(dir1PinA, LOW);
digitalWrite(dir2PinA, HIGH);
Serial.println("Motore 1 Avanti"); // Scrive su la seriale 
Serial.println("   "); // Crea una line vuota
break;

case '2': // Motore 1 Stop 
analogWrite(speedPinA, 0);
digitalWrite(dir1PinA, LOW);
digitalWrite(dir2PinA, HIGH);
Serial.println("Motore 1 Stop");
Serial.println("   ");
break;

case '3': // Motore 1 Indietro
analogWrite(speedPinA, 255);
digitalWrite(dir1PinA, HIGH);
digitalWrite(dir2PinA, LOW);
Serial.println("Motore 1 Indietro");
Serial.println("   ");
break;

//______________Motore 2______________

case '4': // Motore 2 Avanti
analogWrite(speedPinB, 255);
digitalWrite(dir1PinB, LOW);
digitalWrite(dir2PinB, HIGH);
Serial.println("Motore 2 Avanti");
Serial.println("   ");
break;

case '5': // Motore 1 Stop 
analogWrite(speedPinB, 0);
digitalWrite(dir1PinB, LOW);
digitalWrite(dir2PinB, HIGH);
Serial.println("Motore 2 Stop");
Serial.println("   ");
break;

case '6': // Motor 2 Indietro
analogWrite(speedPinB, 255);
digitalWrite(dir1PinB, HIGH);
digitalWrite(dir2PinB, LOW);
Serial.println("Motore 2 Indietro");
Serial.println("   ");
break;

default:
// Resetta tutti i pin dopo che è stato effettuato il ciclo
for (int thisPin = 2; thisPin < 11; thisPin++) {
digitalWrite(thisPin, LOW);
}
 }
   }
     } 
