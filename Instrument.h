#ifndef INSTRUMENT_H
#define INSTRUMENT_H
#include <iostream>
#include <string>
#include <unordered_map>
#include <fstream>
#include <vector>
#include <sstream> // std::stringstream

using namespace std;

class Instrument {
  public:
    static unordered_map<string, Instrument> instrumentMap;
    string id;
    string currency;
    int lotSize;
    static void readcsv(string filename); 
    static void printMap();
    Instrument(string id, string currency, int lotSize);
};

#endif
