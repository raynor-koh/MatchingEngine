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
    Time();
    Time(string time);
    bool operator <(const Time &rightTime) const;
    friend ostream& operator<<(ostream &strm, const Time &t);
};


#endif