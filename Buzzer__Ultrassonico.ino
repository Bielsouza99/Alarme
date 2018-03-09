#include <Ultrasonic.h>
 
//Define os pinos para o trigger e echo
#define pino_trigger 4
#define pino_echo 5
#define buzzer 10
#define led 12 
 
//Inicializa o sensor nos pinos definidos acima
Ultrasonic ultrasonic(pino_trigger, pino_echo);
 
void setup()
{
  Serial.begin(9600);
  Serial.println("Lendo dados do sensor...");
  pinMode (buzzer, OUTPUT);
  pinMode (led, OUTPUT);
}
 
void loop()
{
  //Le as informacoes do sensor, em cm e pol
  float cmMsec, inMsec;
  long microsec = ultrasonic.timing();
  cmMsec = ultrasonic.convert(microsec, Ultrasonic::CM);
  inMsec = ultrasonic.convert(microsec, Ultrasonic::IN);
  //Exibe informacoes no serial monitor
  Serial.print("Distancia em cm: ");
  Serial.print(cmMsec);
  Serial.print(" - Distancia em polegadas: ");
  Serial.println(inMsec);
  delay(1000);

  if ( cmMsec < 100 ) {
   Serial.println ("Te peguei");
   digitalWrite(led, HIGH);
   tone (buzzer, 4000);
   delay(1000);
   tone (buzzer, 3000);
   delay(1000);
   tone (buzzer, 2000);
   delay(1000);
   tone (buzzer, 1000);
   delay(1000);
   
   noTone (buzzer);
   digitalWrite(led, LOW);
   
    }
}


