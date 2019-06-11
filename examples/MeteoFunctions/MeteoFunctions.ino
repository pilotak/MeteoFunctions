#include "MeteoFunctions.h"

MeteoFunctions calc;

#define CELSIUS
//#define FAHRENHEIT

#if defined(CELSIUS)
    float wind_speed = 2;     // m/s
    float temp = 21.0;        // °C
    float humidity = 60.0;    // %
    float pressure = 975.8;   // hPa
    float above_sea = 408.0;  // m
#elif defined(FAHRENHEIT)
    float wind_speed = 2;      // m/s
    float temp = 69.8;         // °F
    float humidity = 60.0;     // %
    float pressure = 975.8;    // hPa
    float above_sea = 1338.5;  // ft
#endif

void setup() {
    Serial.begin(115200);
}

void loop() {

#if defined(CELSIUS)
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

    Serial.print("\nWind chill: ");
    Serial.print(calc.windChill_c(temp, wind_speed));

    Serial.print(" *C\nHeat index: ");
    Serial.print(calc.heatIndex_c(temp, humidity));

    Serial.print(" *C\nApparent temperature: ");
    Serial.print(calc.apparentTemp_c(temp, humidity, wind_speed));

    Serial.print(" *C\nCloud height: ");
    Serial.print(calc.cloudBase_m(temp, humidity));

    Serial.print(" metres\nRelative pressure: ");
    Serial.print(calc.relativePressure_c(pressure, above_sea, temp));

    Serial.print(" Pa\nAbsolute humidity: ");
    Serial.print(calc.absoluteHumidity_c(temp, humidity));
    Serial.println(" g/m3\n");

#elif defined(FAHRENHEIT)
    Serial.print("Wind speed: ");
    Serial.print(calc.msToKmh(wind_speed));

    Serial.print(" km/h\nWind speed: ");
    Serial.print(calc.msToMph(wind_speed));

    Serial.print(" m/h\nWind speed knots: ");
    Serial.print(calc.msToKn(wind_speed));

    Serial.print(" knots\nWind beaufort: ");
    Serial.print(calc.beaufort(wind_speed));

    Serial.print(" \nHumidex: ");
    Serial.print(calc.humidex_f(temp, humidity));

    Serial.print(" *F\nDew point: ");
    Serial.print(calc.dewPoint_f(temp, humidity));

    Serial.print(" *F\nBeaufort wind scale: ");
    Serial.print(calc.beaufort(wind_speed));

    Serial.print("\nWind chill: ");
    Serial.print(calc.windChill_f(temp, wind_speed));

    Serial.print(" *F\nHeat index: ");
    Serial.print(calc.heatIndex_f(temp, humidity));

    Serial.print(" *F\nApparent temperature: ");
    Serial.print(calc.apparentTemp_f(temp, humidity, wind_speed));

    Serial.print(" *F\nCloud height: ");
    Serial.print(calc.cloudBase_f(temp, humidity));

    Serial.print(" feet\nRelative pressure: ");
    Serial.print(calc.relativePressure_f(pressure, above_sea, temp));

    Serial.print(" inHg\nAbsolute humidity: ");
    Serial.print(calc.absoluteHumidity_f(temp, humidity));
    Serial.println(" gr/ft3\n");
#endif
    delay(5000);
}