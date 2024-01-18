#include "DS1307.h"
#include <Arduino.h>

int Ds1307::Begin(TwoWire &wire) {
  Rtc.Begin();
  Rtc.SetSquareWavePin(DS1307SquareWaveOut_Low);
  return 0;
}

int Ds1307::ReadTime(struct tm *tm_now) {
  RtcDateTime dt = Rtc.GetDateTime();
  if (!Rtc.IsDateTimeValid() && Rtc.LastError() != 0) {
    return 2;
  }

  tm_now->tm_sec = dt.Second();
  tm_now->tm_min = dt.Minute();
  tm_now->tm_hour = dt.Hour();
  tm_now->tm_mday = dt.Day();
  tm_now->tm_wday = dt.DayOfWeek();
  tm_now->tm_mon = dt.Month() - 1;
  tm_now->tm_year = dt.Year() + 100 - 2000;

  return 0;
}

int Ds1307::WriteTime(struct tm *tm_now) {
  RtcDateTime dt(tm_now->tm_year - 100 + 2000, tm_now->tm_mon + 1,
                 tm_now->tm_mday, tm_now->tm_hour, tm_now->tm_min,
                 tm_now->tm_sec);
  Rtc.SetDateTime(dt);
  return 0;
}

Ds1307 rtcx;
