#ifndef TIME_H
#define TIME_H
#include <string>

using namespace std;

class Time {
  public:
    int hour;
    int minute;
    int sec;
    string strtime;
    Time(string time);
    bool operator <(const Time &rightTime) const;
};


#endif