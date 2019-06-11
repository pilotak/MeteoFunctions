/*
MIT License
Copyright (c) 2019 Pavel Slama
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

#ifndef METEOFUNCTIONS_H
#define METEOFUNCTIONS_H

#include <math.h>

#if defined(__MBED__)
  #include "mbed.h"
#else
  #include "Arduino.h"
#endif

class MeteoFunctions {
 public:
  MeteoFunctions();
  float   c_f(float temp_c);
  float   f_c(float temp_f);
  float   msToKmh(float ms);
  float   kmhToMs(float kmh);
  float   msToMph(float ms);
  float   mphToMs(float mph);
  float   msToKn(float ms);
  float   knToMs(float kn);
  float   m_ft(float meters);
  float   ft_m(float feet);
  float   gm3_grft3(float gm3);
  float   grft3_gm3(float grft3);
  float   hPa_inHg(float hPa);
  float   inHg_hPa(float inHg);
  float   humidex_c(float temp_c, float humidity);
  float   humidex_f(float temp_f, float humidity);
  float   dewPoint_c(float temp_c, float humidity);
  float   dewPoint_f(float temp_f, float humidity);
  uint8_t beaufort(float wind_speed_ms);
  float   windChill_c(float temp_c, float wind_speed_ms);
  float   windChill_f(float temp_f, float wind_speed_ms);
  float   heatIndex_c(float temp_c, float humidity);
  float   heatIndex_f(float temp_f, float humidity);
  float   apparentTemp_c(float temp_c, float humidity, float wind_speed_ms);
  float   apparentTemp_f(float temp_f, float humidity, float wind_speed_ms);
  float   cloudBase_m(float temp_c, float humidity);
  float   cloudBase_f(float temp_f, float humidity);
  float   relativePressure_c(float abs_pressure, float height_m, float temp_c);
  float   relativePressure_f(float abs_pressure, float height_ft, float temp_f);
  float   absoluteHumidity_c(float temp_c, float humidity);
  float   absoluteHumidity_f(float temp_f, float humidity);
};

#endif  // METEOFUNCTIONS_H
