#pragma once

#include <RtcDS1307.h>
#include <Wire.h>
#include <time.h> // for struct tm

class Ds1307 {
public:
  int Begin(TwoWire &wire);
  int ReadTime(struct tm *tm_now);
  int WriteTime(struct tm *tm_now);
  Ds1307() : Rtc(Wire1) {}

private:
  RtcDS1307<TwoWire> Rtc;
};

extern Ds1307 rtcx;
