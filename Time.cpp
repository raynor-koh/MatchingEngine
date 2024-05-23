#include "Time.h"

Time::Time(int hour, int minute, int sec) {
  this->hour = hour;
  this->minute = minute;
  this->sec = sec;
}

bool Time::operator <(const Time &rightTime) const {
  return (this->hour < rightTime.hour) || 
    ((this->hour == rightTime.hour) && (this->minute < rightTime.minute)) ||
    ((this->hour == rightTime.hour) && (this->minute == rightTime.minute) && (this->sec < rightTime.sec));
}

