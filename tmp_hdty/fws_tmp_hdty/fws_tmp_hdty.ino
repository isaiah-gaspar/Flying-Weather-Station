/******************************************************************************
  SparkFun Si7021 Breakout Example 
  Joel Bartlett @ SparkFun Electronics
  Original Creation Date: May 18, 2015
  Updated May 4, 2016
  This sketch prints the temperature and humidity the Serial port.
  The library used in this example can be found here:
  https://github.com/sparkfun/Si7021_Breakout/tree/master/Libraries
  Hardware Connections:
      HTU21D ------------- Photon
      (-) ------------------- GND
      (+) ------------------- 3.3V (VCC)
       CL ------------------- D1/SCL
       DA ------------------- D0/SDA
  Development environment specifics:
    IDE: Particle Dev
    Hardware Platform: SparkFun RedBoard
                       Arduino IDE 1.6.5
  This code is beerware; if you see me (or any other SparkFun
  employee) at the local, and you've found our code helpful,
  please buy us a round!
  Distributed as-is; no warranty is given.
*******************************************************************************/

 /*
  * Edited by Isaiah Gaspar
  * 
  * Date: 4/7/18
  * 
  */


#include "SparkFun_Si7021_Breakout_Library.h"
#include <Wire.h>

float humidity = 0;
float tempf = 0;

//IG Changed name and pinout to better fit application
int s_data0 = A4;
int s_clock0 = A5;
float time_on = 0;
//Create Instance of HTU21D or SI7021 temp and humidity sensor and MPL3115A2 barrometric sensor
Weather sensor;

//---------------------------------------------------------------
void setup()
{
    Serial.begin(9600);   // open serial over USB at 9600 baud
    
//IG Changed name of pins
    pinMode(s_data0, OUTPUT);
    pinMode(s_clock0, OUTPUT);

    digitalWrite(s_data0, HIGH);
    digitalWrite(s_clock0, LOW);

    //Initialize the I2C sensors and ping them
    sensor.begin();

}
//---------------------------------------------------------------
void loop()
{
    //Get readings from all sensors
    getWeather();
    printInfo();
    delay(30000);
    
 time_on = time_on+.5;
}
//---------------------------------------------------------------
void getWeather()
{
  // Measure Relative Humidity from the HTU21D or Si7021
  humidity = sensor.getRH();

  // Measure Temperature from the HTU21D or Si7021
  tempf = sensor.getTempF();
  // Temperature is measured every time RH is requested.
  // It is faster, therefore, to read it from previous RH
  // measurement with getTemp() instead with readTemp()

}
//---------------------------------------------------------------
void printInfo()
{
//This function prints the weather data out to the default Serial Port

  Serial.print("Temp:");
  Serial.print(tempf);
  Serial.print("F, ");

  Serial.print("Humidity:");
  Serial.print(humidity);
  Serial.print("%, ");

//IG Adding time prinout

 
  Serial.print("Time operating:");
  Serial.print(time_on);
  Serial.println("min");
}
