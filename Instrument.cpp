#include <iostream>
#include <string>
#include <unordered_map>
using namespace std;

class Instrument {
  public:
    static unordered_map<string, Instrument> instrumentMap = {};
    string id;
    string currency;
    int lotSize;

    static void readcsv(string filename) {
      
    }
}