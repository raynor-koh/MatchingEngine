#include "Time.h"
#include <sstream>
#include <vector>
#include <string>

using namespace std;

Time::Time(string time) {
  stringstream ss(time);
  string word;
  vector<string> commaSepValues = {};
  while (getline(ss, word, ':')) {
    commaSepValues.push_back(word);
  }
  this->strtime = time;
  this->hour = stoi(commaSepValues[0]);
  this->minute = stoi(commaSepValues[1]);
  this->sec = stoi(commaSepValues[2]);
}

bool Time::operator <(const Time &rightTime) const {
  return (this->hour < rightTime.hour) || 
    ((this->hour == rightTime.hour) && (this->minute < rightTime.minute)) ||
    ((this->hour == rightTime.hour) && (this->minute == rightTime.minute) && (this->sec < rightTime.sec));
}

