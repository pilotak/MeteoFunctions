#include "MeteoFunctions.h"

MeteoFunctions calc;

#define CELSIUS
//#define FAHRENHEIT

#if defined(CELSIUS)
    float wind_speed = 2;   // m/s
    float temp = 21.0;      // °C
    float humidity = 60.0;  // %
#elif defined(FAHRENHEIT)
    float wind_speed = 2;   // m/s
    float temp = 69.8;      // °F
    float humidity = 60.0;  // %
#endif

void setup() {
    Serial.begin(9600);
}

void loop() {

#if defined(CELSIUS)
    Serial.print("Wind speed: ");
    Serial.print(calc.msToKmh(wind_speed));

    Serial.print(" km/h\nWind speed: ");
    Serial.print(calc.msToMph(wind_speed));

    Serial.print(" m/h\nWind speed knots: ");
    Serial.print(calc.msToKn(wind_speed));

    Serial.print(" knots\nHumidex: ");
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
    Serial.println(" metres");

#elif defined(FAHRENHEIT)
    Serial.print("Wind speed: ");
    Serial.print(calc.msToKmh(wind_speed));

    Serial.print(" km/h\nWind speed: ");
    Serial.print(calc.msToMph(wind_speed));

    Serial.print(" m/h\nWind speed knots: ");
    Serial.print(calc.msToKn(wind_speed));

    Serial.print(" knots\nHumidex: ");
    Serial.print(calc.humidex_f(temp, humidity));

    Serial.print(" *F\nDew point: ");
    Serial.print(calc.dewPoint_f(temp, humidity));

    Serial.print(" *F\nBeaufort wind scale: ");
    Serial.print(calc.beaufort(wind_speed));

    Serial.print("\n Wind chill: ");
    Serial.print(calc.windChill_f(temp, wind_speed));

    Serial.print(" *F\nHeat index: ");
    Serial.print(calc.heatIndex_f(temp, humidity));

    Serial.print(" *F\nApparent temperature: ");
    Serial.print(calc.apparentTemp_f(temp, humidity, wind_speed));

    Serial.print(" *F\n: ");
    Serial.print(calc.cloudBase_m(temp, humidity));
    Serial.println(" metres");
#endif
    delay(5000);
}