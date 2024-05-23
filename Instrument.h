#pragma once
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
    Instrument(string id, string currency, int lotSize);
    static void printMap();
};
