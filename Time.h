#ifndef TIME_H
#define TIME_H

class Time {
  int hour;
  int minute;
  int sec;
  Time(int hour, int minute, int sec);
  bool operator <(const Time &rightTime) const;
};


#endif