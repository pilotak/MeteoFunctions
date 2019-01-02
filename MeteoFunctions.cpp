/*
MIT License
Copyright (c) 2018 Pavel Slama
Permission is hereby granted, free of charge, to any person obtaining a copy
of this software and associated documentation files (the "Software"), to deal
in the Software without restriction, including without limitation the rights
to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
copies of the Software, and to permit persons to whom the Software is
furnished to do so, subject to the following conditions:
The above copyright notice and this permission notice shall be included in all
copies or substantial portions of the Software.
THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
SOFTWARE.
*/

#include "MeteoFunctions.h"

MeteoFunctions::MeteoFunctions() {
}

/**
 * Converts Celsius to Fahrenheit
 */
float MeteoFunctions::c_f(float temp_c) {
    return temp_c * 9 / 5 + 32;
}

/**
 * Converts Fahrenheit to Celsius
 */
float MeteoFunctions::f_c(float temp_f) {
    return (temp_f - 32) * 5 / 9;
}

/**
 * Converts m/s to km/h
 */
float MeteoFunctions::msToKmh(float ms) {
    return ms * 18 / 5;
}

/**
 * Converts km/h to m/s
 */
float MeteoFunctions::kmhToMs(float kmh) {
    return kmh * 5 / 18;
}

/**
 * Converts m/s to m/h
 */
float MeteoFunctions::msToMph(float ms) {
    return ms / 0.44704;
}

/**
 * Converts m/h to m/h m/s
 */
float MeteoFunctions::mphToMs(float mph) {
    return mph * 2.236936;
}

/**
 * Converts m/s to knots
 */
float MeteoFunctions::msToKn(float ms) {
    return ms * 1.94384449;
}

/**
 * Converts knots to m/s
 */
float MeteoFunctions::knToMs(float kn) {
    return kn * 0.5144444;
}

/**
 * Converts meters to feet
 */
float MeteoFunctions::m_ft(float meters) {
    return meters * 3.2808399;
}

/**
 * Converts feet to meters
 */
float MeteoFunctions::ft_m(float feet) {
    return feet / 3.2808399;
}

/**
 * Converts hPa to inHg
 */
float MeteoFunctions::hPa_inHg(float hPa) {
    return 0.02952998751 * hPa;
}

/**
 * Converts inHg to hPa
 */
float MeteoFunctions::inHg_hPa(float inHg) {
    return inHg / 0.02952998751;
}

/**
 * Calculates humidex in Celsius
 */
float MeteoFunctions::humidex_c(float temp_c, float humidity) {
    double e = (6.112 * pow(10, (7.5 * temp_c / (237.7 + temp_c))) * humidity / 100);  // vapor pressure
    return float (temp_c + 0.5555555 * (e - 10.0));
}

/**
 * Calculates humidex in Fahrenheit
 */
float MeteoFunctions::humidex_f(float temp_f, float humidity) {
    return c_f(humidex_c(f_c(temp_f), humidity));
}

/**
 * Calculates dew point in Celsius
 */
float MeteoFunctions::dewPoint_c(float temp_c, float humidity) {
    return 243.04 * (log(humidity / 100) + ((17.625 * temp_c) / (243.04 + temp_c))) / (17.625 - log(humidity / 100) - ((17.625 * temp_c) /
            (243.04 + temp_c)));
}

/**
 * Calculates dew point in Fahrenheit
 */
float MeteoFunctions::dewPoint_f(float temp_f, float humidity) {
    return c_f(dewPoint_c(f_c(temp_f), humidity));
}

/**
 * Returns wind strength in Beaufort scale
 */
uint8_t MeteoFunctions::beaufort(float wind_speed_ms) {
    uint8_t res = 0;

    if (wind_speed_ms >= 32.6) res = 12;
    else if (wind_speed_ms >= 28.4) res = 11;
    else if (wind_speed_ms >= 24.5) res = 10;
    else if (wind_speed_ms >= 20.7) res = 9;
    else if (wind_speed_ms >= 17.2) res = 8;
    else if (wind_speed_ms >= 13.9) res = 7;
    else if (wind_speed_ms >= 10.8) res = 6;
    else if (wind_speed_ms >= 8.0) res = 5;
    else if (wind_speed_ms >= 5.5) res = 4;
    else if (wind_speed_ms >= 3.3) res = 3;
    else if (wind_speed_ms >= 1.5) res = 2;
    else if (wind_speed_ms >= 0.3) res = 1;

    return res;
}

/**
 * Calculates wind chill in Celsius
 */
float MeteoFunctions::windChill_c(float temp_c, float wind_speed_ms) {
    float wind_chill_c;
    float wind_speed_kmh = msToKmh(wind_speed_ms);

    if (temp_c <= 10 && wind_speed_kmh >= 5) {
        wind_chill_c = 13.12;
        wind_chill_c += 0.6215 * temp_c;
        wind_chill_c -= 11.37 * pow(static_cast<double>(wind_speed_kmh), 0.16);
        wind_chill_c += 0.3965 * temp_c * pow(static_cast<double>(wind_speed_kmh), 0.16);

    } else {
        wind_chill_c = temp_c;
    }

    return wind_chill_c;
}

/**
 * Calculates wind chill in Fahrenheit
 */
float MeteoFunctions::windChill_f(float temp_f, float wind_speed_ms) {
    return c_f(windChill_c(f_c(temp_f), wind_speed_ms));
}

/**
 * Calculates heat index in Celsius
 */
float MeteoFunctions::heatIndex_c(float temp_c, float humidity) {
    return f_c(heatIndex_f(c_f(temp_c), humidity));
}

/**
 * Calculates heat index in Fahrenheit
 */
float MeteoFunctions::heatIndex_f(float temp_f, float humidity) {
    double heat_index_f = 0.5 * (temp_f + 61.0 + ((temp_f - 68.0) * 1.2) + (humidity * 0.094));

    if (temp_f <= 40) {  // heat index not aplicable below 40°F
        heat_index_f = temp_f;

    } else if ((heat_index_f + temp_f) / 2 > 80) {
        heat_index_f = -42.379 + (2.04901523 * temp_f) + (10.14333127 * humidity);
        heat_index_f -= (0.22475541 * temp_f * humidity) - (6.83783 * pow(10.0, -3.0) * pow(static_cast<double>(temp_f), 2.0));
        heat_index_f -= (5.481717 * pow(10.0, -2) * pow(static_cast<double>(humidity), 2.0)) + (1.22874 * pow(10.0,
                        -3.0) * pow(static_cast<double>(temp_f), 2.0) * humidity);
        heat_index_f += (8.5282 * pow(10.0, -4.0) * temp_f * pow(static_cast<double>(humidity), 2.0));
        heat_index_f -= (1.99 * pow(10.0, -6.0) * pow(static_cast<double>(temp_f), 2.0) * pow(static_cast<double>(humidity), 2.0));


        float heat_index_adj = 0;

        if (humidity < 13 && (temp_f >= 80 && temp_f <= 120)) heat_index_adj = ((13 - humidity) / 4) * sqrt((17 - abs(temp_f - 95.0)) / 17);
        else if (humidity > 85 && (temp_f >= 80 && temp_f <= 87)) heat_index_adj = ((humidity - 85) / 10) * ((87 - temp_f) / 5) * (-1.0);


        heat_index_f -= heat_index_adj;  // apply correction
    }

    return static_cast<float>(heat_index_f);
}

/**
 * Calculates apparent temperature in Celsius
 */
float MeteoFunctions::apparentTemp_c(float temp_c, float humidity, float wind_speed_ms) {
    double e = (humidity / 100) * 6.105;
    e = pow(e, ((17.27 * temp_c) / (237.7 + temp_c)));

    float q = 93.021511;  // net radiation absorbed per unit area of body surface (W/m2)

    return temp_c + (0.348 * e) - 0.7 * wind_speed_ms + (0.7 * (q / (wind_speed_ms + 10))) - 4.25;
}

/**
 * Calculates apparent temperature in Celsius
 */
float MeteoFunctions::apparentTemp_f(float temp_f, float humidity, float wind_speed_ms) {
    return c_f(apparentTemp_c(f_c(temp_f), humidity, wind_speed_ms));
}

/**
 * Calculates cloud base height
 */
float MeteoFunctions::cloudBase_m(float temp_c, float humidity) {
    return 121.92 * (temp_c - dewPoint_c(temp_c, humidity));
}

/**
 * Calculates cloud base height
 */
float MeteoFunctions::cloudBase_f(float temp_f, float humidity) {
    return m_ft(cloudBase_m(f_c(temp_f), humidity));
}

/**
 * Calculates relative pressure
 */
float MeteoFunctions::relativePressure_c(float abs_pressure, float height_m, float temp_c) {
    return (abs_pressure / pow(1.0 - 0.0065 * height_m / (temp_c  + 273.15), 5.255));  // ICAO formula
}

/**
 * Calculates relative pressure
 */
float MeteoFunctions::relativePressure_f(float abs_pressure, float height_ft, float temp_f) {
    return relativePressure_c(abs_pressure, ft_m(height_ft), f_c(temp_f));
}
