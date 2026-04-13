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

const int ledPin = 2; 
const int ledPin2 = 4;
const int ledtryk = 3;
int co2, fugt, temp, sum;
int ledState2;
int ledState;
void setup()
{
  Serial.begin(115200);
  //Serial.println(F("SCD4x Example"));
  Wire.begin();

  //mySensor.enableDebugging(); // Uncomment this line to get helpful debug messages on Serial

  //.begin will start periodic measurements for us (see the later examples for details on how to override this)
  if (mySensor.begin() == false)
  {
    Serial.println(F("Sensor not detected. Please check wiring. Freezing..."));
    while (1)
      ;
  }

  //The SCD4x has data ready every five seconds

pinMode(ledPin2, OUTPUT);


Serial.println("relativt støjniveau;co2 (ppm);temprature (C);relativ luftfugtighed (%RH)");

//her begynder lyddelen









}

void loop()
{
  if (mySensor.readMeasurement()) // readMeasurement will return true when fresh data is available
  {
   // Serial.println(mip);

co2=mySensor.getCO2();
temp=mySensor.getTemperature();
fugt=mySensor.getHumidity();

 }
    //Serial.print(F(""));


   // Serial.print(F("CO2(ppm):"));
    //Serial.print(mySensor.getCO2());

    //Serial.print(F("\tTemperature(C):"));
    //Serial.print(mySensor.getTemperature(), 1);

   // Serial.print(F("\tHumidity(%RH):"));
   // Serial.print(mySensor.getHumidity(), 1);

   // Serial.println();
  
    if (digitalRead(ledtryk)==LOW){
      ledState2 = LOW;// continue(60000);
    }
    else if(co2>1400)
    {

ledState2 = HIGH;

    }
    else
    ledState2 = LOW;

  digitalWrite(ledPin2,ledState2);

  //if(digitalRead(ledtryk)==HIGH){}

 
 

  delay(250);

  //her begynder lyddelen

 long sum = 0;
    for(int i=0; i<32; i++)
    {
        sum += analogRead(A0);
    }

    sum >>= 5;

    Serial.println(String(sum)+";"+String(co2)+";"+String(temp)+";"+String(fugt));
   /* Serial.println("co2 (ppm): "+ String(co2));
    Serial.println("temprature (C): "+ String(temp));
    Serial.println("relativ luftfugtighed(%RH): "+ String(fugt));
    Serial.println();
  test();*/

if (sum>200)
{
  ledState = HIGH;   
}
  else
    ledState = LOW;   

digitalWrite(ledPin,ledState);




}
void test(){
  return;
}
