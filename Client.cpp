#include "Client.h"
#include <iostream>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <fstream>
#include <vector>
#include <sstream> // std::stringstream
#include "Instrument.h"


unordered_map<string, Client> Client::clientMap;
Client::Client(string id, unordered_set<string> currencies, bool positionCheck, int rating) {
  this->id = id;
  this->currencies = currencies;
  this->positionCheck = positionCheck;
  this->rating = rating;
}
void Client::readcsv(string filename) {
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
    string readID;
    bool readPosCheck;
    int readRating;
    unordered_set<string> currencies = {};
    readID = commaSepValues[0];
    readPosCheck = (commaSepValues[commaSepValues.size() - 2] == "Y") ? true : false;
    readRating = stoi(commaSepValues[commaSepValues.size() - 1]);
    for (int i = 1; i <= commaSepValues.size() - 3; i++) {
      string curStr = commaSepValues[i];
      if (curStr[0] == '"') {
        currencies.insert(curStr.substr(1, curStr.length() - 1));
      } else if (curStr[curStr.length() - 1] == '"') {
        currencies.insert(curStr.substr(0, curStr.length() - 1));
      } else {
        currencies.insert(curStr);
      }
    }
    Client newClient = Client(readID, currencies, readPosCheck, readRating);
    Client::clientMap.insert(make_pair(readID, newClient));
  };
  File.close();
}

void Client::printMap() {
  for (auto p : Client::clientMap) {
    cout << p.first << " " << p.second.id << " " << p.second.positionCheck << " " << p.second.rating << endl;
  }
}





