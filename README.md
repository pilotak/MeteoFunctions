# MeteoFunctions
[![build](https://github.com/pilotak/MeteoFunctions/workflows/build/badge.svg)](https://github.com/pilotak/MeteoFunctions/actions) 
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
- Absolute humidity

Let's add them to your project. You don't need any special sensors, it's just a math. Here is a class that do that for you. Supports both **Celsius** and **Fahrenheit**, please navigate to full example.

## Arduino example
Please see `examples` folder

## Mbed example
```cpp
#include "mbed.h"
#include "MeteoFunctions.h"

MeteoFunctions calc;

float wind_speed = 2.0;   // m/s
float temp = 21.0;        // °C
float humidity = 60.0;    // %
float pressure = 975.8;   // hPa
float above_sea = 408.0;  // m

int main() {
    printf("Wind speed: %f km/h\n", calc.msToKmh(wind_speed));

    printf("Wind speed: %f m/h\n", calc.msToMph(wind_speed));

    printf("Wind speed: %f knots\n", calc.msToKn(wind_speed));

    printf("Beaufort wind scale: %u\n", calc.beaufort(wind_speed));

    printf("Humidex: %f *C\n", calc.humidex_c(temp, humidity));

    printf("Dew point: %f *C\n", calc.dewPoint_c(temp, humidity));

    printf("Wind chill: %f *C\n", calc.windChill_c(temp, wind_speed));

    printf("Heat index: %f *C\n", calc.heatIndex_c(temp, humidity));

    printf("Apparent temperature: %f *C\n", calc.apparentTemp_c(temp, humidity, wind_speed));

    printf("Could base: %f metres\n", calc.cloudBase_m(temp, humidity));

    printf("Relative pressure: %f hPa\n", calc.relativePressure_c(pressure, above_sea, temp));

    printf("Absolute humidity: %f g/m3\n", calc.absoluteHumidity_c(temp, humidity));

    return 0;
}
```
