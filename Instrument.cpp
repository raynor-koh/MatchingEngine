#include "Instrument.h"

using namespace std;

unordered_map<string, Instrument> Instrument::instrumentMap;
Instrument::Instrument() {};
void Instrument::readcsv(string filename) {
  ifstream File(filename);
  if(!File.is_open()) throw runtime_error("Could not open file");
  string row;
  getline(File, row);
  while (getline(File, row)) {
    stringstream ss(row);
    string word;
    vector<string> commaSepValues;
    while (getline(ss, word, ',')) {
      commaSepValues.push_back(word);
    }
    string readID = "";
    string readCurrency = "";
    int readLotsize = 0;
    for (int i = 0; i < commaSepValues.size(); i++) {
      if (i == 0) {
        readID = commaSepValues[i];
      } else if (i == 1) {
        readCurrency = commaSepValues[i];
      } else {
        readLotsize = stoi(commaSepValues[i]);
      }
    }
    Instrument newInstr = Instrument(readID, readCurrency, readLotsize);
    Instrument::instrumentMap.insert(make_pair(readID, newInstr));
    commaSepValues.clear();
  };
  File.close();
}

Instrument::Instrument(string id, string currency, int lotSize) {
  this->id = id;
  this->currency = currency;
  this->lotSize = lotSize;
}

void Instrument::printMap() {
  for (auto p : Instrument::instrumentMap) {
    cout << p.first << " " << p.second.id << " " << p.second.currency << " " << p.second.lotSize << endl;
  }
}
