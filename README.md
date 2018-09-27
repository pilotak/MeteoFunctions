# MeteoFunctions
[![Build Status](https://travis-ci.org/pilotak/MeteoFunctions.svg?branch=master)](https://travis-ci.org/pilotak/MeteoFunctions) 
[![Framework Badge Arduino](https://img.shields.io/badge/framework-arduino-00979C.svg)](https://arduino.cc)
[![Framework Badge mbed](https://img.shields.io/badge/framework-mbed-008fbe.svg)](https://os.mbed.com/)

Do you have your own meteo station based on Arduino or Mbed? and ever wondered how meteorologists get values like:
- Humidex
- Dew point
- Beaufort wind scale
- Wind chill
- Heat index
- Apparent temperature
- Cloud height base
- Relative pressure

Let's add them to your project. You don't need any special sensors, it's just a math. Here is a class that do that for you. Supports both **Celsius** and **Fahrenheit**.

## Example
```cpp
#include "MeteoFunctions.h"

MeteoFunctions calc;

float wind_speed = 2.0;     // m/s
float temp = 21.0;        // °C
float humidity = 60.0;    // %
float pressure = 975.8;   // Pa
float above_sea = 408.0;  // m

void setup() {
    Serial.begin(115200);
}

void loop() {
    Serial.print("Wind speed: ");
    Serial.print(calc.msToKmh(wind_speed));

    Serial.print(" km/h\nWind speed: ");
    Serial.print(calc.msToMph(wind_speed));

    Serial.print(" m/h\nWind speed knots: ");
    Serial.print(calc.msToKn(wind_speed));

    Serial.print(" knots\nWind beaufort: ");
    Serial.print(calc.beaufort(wind_speed));

    Serial.print(" \nHumidex: ");
    Serial.print(calc.humidex_c(temp, humidity));

    Serial.print(" *C\nDew point: ");
    Serial.print(calc.dewPoint_c(temp, humidity));

    Serial.print(" *C\nBeaufort wind scale: ");
    Serial.print(calc.beaufort(wind_speed));

    Serial.print("\n Wind chill: ");
    Serial.print(calc.windChill_c(temp, wind_speed));

    Serial.print(" *C\nHeat index: ");
    Serial.print(calc.heatIndex_c(temp, humidity));

    Serial.print(" *C\nApparent temperature: ");
    Serial.print(calc.apparentTemp_c(temp, humidity, wind_speed));

    Serial.print(" *C\n: ");
    Serial.print(calc.cloudBase_m(temp, humidity));

    Serial.print(" metres\n: ");
    Serial.print(calc.relativePressure_c(pressure, above_sea, temp));
    Serial.println(" Pa");

    delay(5000);
}
```
