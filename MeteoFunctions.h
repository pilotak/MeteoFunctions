#ifndef _METEOFUNCTIONS_H
#define _METEOFUNCTIONS_H

#if defined(__MBED__)
  #include "mbed.h"
#elif defined(ARDUINO)
  #if ARDUINO >= 100
    #include "Arduino.h"
  #else
    #include "WProgram.h"
  #endif
#endif

#include <math.h>

class MeteoFunctions {
 public:
  MeteoFunctions();
  float    c_f(float temp_c);
  float    f_c(float temp_f);
  float    msToKmh(float ms);
  float    msToMph(float ms);
  uint16_t msToKn(float ms);
  float    humidex_c(float temp_c, float humidity);
  float    humidex_f(float temp_f, float humidity);
  float    dewPoint_c(float temp_c, float humidity);
  float    dewPoint_f(float temp_f, float humidity);
  uint8_t  beaufort(float wind_speed_ms);
  float    windChill_c(float temp_c, float wind_speed_ms);
  float    windChill_f(float temp_f, float wind_speed_ms);
  float    heatIndex_c(float temp_c, float humidity);
  float    heatIndex_f(float temp_f, float humidity);
  float    apparentTemp_c(float temp_c, float humidity, float wind_speed_ms);
  float    apparentTemp_f(float temp_f, float humidity, float wind_speed_ms);
  float    cloudBase_m(float temp_c, float humidity);
};

#endif
