#include <SoftwareSerial.h>
SoftwareSerial BT(7, 8); 
// crea una  porta seriale virtuale UART
// collega BT modulo TX al pin D7
// collega BT module RX al pin D8
// collega BT Vcc al pin 5V, GND al pin GND

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

void setup()  
{
 
  BT.begin(9600);
  // Inviamo un messaggio appena si connette
  BT.println("Hello from Automobilina");
  BT.println("'7' Comandi di aiuto");
  
  //Configuro i pin di arduino in uscita per pilotare L298N 
  pinMode(dir1PinA,OUTPUT);
  pinMode(dir2PinA,OUTPUT);
  pinMode(speedPinA,OUTPUT);
  pinMode(dir1PinB,OUTPUT);
  pinMode(dir2PinB,OUTPUT);
  pinMode(speedPinB,OUTPUT);
}


void loop() 
{
  if (BT.available())
  // Se arrivva del testo dal Bluetooth...
  {
    int inByte=(BT.read()); // ...leggilo e memorizza in “a”
    
    switch (inByte) {

//______________Motore 1______________

case '1': // Motore 1 Avanti
analogWrite(speedPinA, 255);//Configurazione velocità del motore tramite PWM
digitalWrite(dir1PinA, LOW);
digitalWrite(dir2PinA, HIGH);
BT.println("'Motore 1 Avanti'"); // Scrive su la seriale 
break;

case '2': // Motore 1 Stop 
analogWrite(speedPinA, 0);
digitalWrite(dir1PinA, LOW);
digitalWrite(dir2PinA, HIGH);
BT.println("'Motore 1 Stop'");
break;

case '3': // Motore 1 Indietro
analogWrite(speedPinA, 255);
digitalWrite(dir1PinA, HIGH);
digitalWrite(dir2PinA, LOW);
BT.println("'Motore 1 Indietro'");
break;

//______________Motore 2______________

case '4': // Motore 2 Avanti
analogWrite(speedPinB, 255);
digitalWrite(dir1PinB, LOW);
digitalWrite(dir2PinB, HIGH);
BT.println("'Motore 2 Avanti'");
break;

case '5': // Motore 1 Stop 
analogWrite(speedPinB, 0);
digitalWrite(dir1PinB, LOW);
digitalWrite(dir2PinB, HIGH);
BT.println("'Motore 2 Stop'");
break;

case '6': // Motor 2 Indietro
analogWrite(speedPinB, 255);
digitalWrite(dir1PinB, HIGH);
digitalWrite(dir2PinB, LOW);
BT.println("'Motore 2 Indietro'");
break;

case '7': // Motor 2 Indietro
  BT.println(" '1' Motore 1 Avanti");
  BT.println(" '2' Motore 1 Stop");
  BT.println(" '3' Motore 1 Indietro");
  BT.println(" '4' Motore 2 Avanti");
  BT.println(" '5' Motore 2 Stop");
  BT.println(" '6' Motore 2 Indietro");
  BT.println(" '7' Menu di aiuto");
break;

default:
// Resetta tutti i pin dopo che è stato effettuato il ciclo
for (int thisPin = 2; thisPin < 11; thisPin++) {
digitalWrite(thisPin, LOW);
}
 }
   }
     } 
