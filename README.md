# Informatik-Sejr-og-Sander

Vores problemformulering:

Hvordan kan man sikre et bedre klassemiljø aka indeklima herunder lyd- og CO_2-niveau på en måde, så det ikke bliver overset, men heller ikke er et for forstyrrende element.


Vi vil gerne finde ud af, hvor meget CO_2 der er i luften. Det gør vi med en CO_2-måler. Derudover måler vi støjniveauet med en støjmåler. Vores Audoino skal reagere med lys og/eller lyde, for at komme i kontakt med eleverne og læreren (output).

Vi har lånt 1 arduino, 1 mikrofon, 1 kanp/LED, 1 CO2 måler, 3 ledninger til input og output, 1 ledning mellem arduiono og computer.

Vi mangler en højtaler til arduinoen


Linket: til vores miroboard er:
https://miro.com/welcomeonboard/cWROUWRUUWxBZ045U3dNc1NqS3hTekpKY01rOWQ2MWtIREVacXdsTWJNdkhIYjB6VGVpM2x5bTl2dFJoRkhacFRrZ3VOcjZOMTNySGRDY2Q4bHRhSm9kaWdaTEJjVmVNQldHUDUveTdtL2RqekZtWXRhNDlsQVpubzhhRWZFNmhBd044SHFHaVlWYWk0d3NxeHNmeG9BPT0hdjE=?share_link_id=681320653072
















# koden:



/*
  Reading CO2, humidity and temperature from the SCD4x
  By: Paul Clark
  Based on earlier code by: Nathan Seidle
  SparkFun Electronics
  Date: June 3rd, 2021
  License: MIT. See license file for more information but you can
  basically do whatever you want with this code.

  Feel like supporting open source hardware?
  Buy a board from SparkFun! https://www.sparkfun.com/products/18365

  This example prints the current CO2 level, relative humidity, and temperature in C.

  Hardware Connections:
  Attach RedBoard to computer using a USB cable.
  Connect SCD40/41 to RedBoard using Qwiic cable.
  Open Serial Monitor at 115200 baud.
*/

#include <Wire.h>

#include "SparkFun_SCD4x_Arduino_Library.h" //Click here to get the library: http://librarymanager/All#SparkFun_SCD4x
SCD4x mySensor;

const int ledPin = A0; 
const int lydPin = 9
int co2;




// notes in the melody:
int melody[] = {
 262, 196, 196, 220, 196, 0, 247, 262
};

// note durations: 4 = quarter note, 8 = eighth note, etc.:
int noteDurations[] = {
  4, 8, 8, 4, 4, 4, 4, 4
};


void setup()
{



  
  Serial.begin(115200);
  Serial.println(F("SCD4x Example"));
  Wire.begin();

  pinMode(ledPin, OUTPUT);
pinMode(lydPin, OUTPUT);

  //mySensor.enableDebugging(); // Uncomment this line to get helpful debug messages on Serial

  //.begin will start periodic measurements for us (see the later examples for details on how to override this)
  if (mySensor.begin() == false)
  {
    Serial.println(F("Sensor not detected. Please check wiring. Freezing..."));
    while (1)
      ;
  }

  //The SCD4x has data ready every five seconds
}

void loop()
{


    long sum = 0;
    for(int i=0; i<32; i++)
    {
        sum += analogRead(A3);
    }

    sum >>= 5;

    Serial.println(sum);
  




  if (mySensor.readMeasurement()) // readMeasurement will return true when fresh data is available
  {
    Serial.println();
co2=mySensor.getCO2();
    Serial.print(F("CO2(ppm):"));
    Serial.print(mySensor.getCO2());

    Serial.print(F("\tTemperature(C):"));
    Serial.print(mySensor.getTemperature(), 1);

    Serial.print(F("\tHumidity(%RH):"));
    Serial.print(mySensor.getHumidity(), 1);

    Serial.println();


if(co2>1400){

  digtialWrite(lydPin,HIGH);

}
else{
digitalWrite(lydPin,LOW);}


}


  
  else
    Serial.print(F(""));

  delay(250);


  int ledState;

if (sum>250)
{
  ledState = HIGH;   
}
  else
    ledState = LOW;   

digitalWrite(ledPin,ledState);

}
