#ifndef CLIENT_H
#define CLIENT_H
#include <iostream>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <fstream>
#include <vector>
#include <sstream> // std::stringstream
#include "Instrument.h"


class Client {
  public:
    string id;
    unordered_set<string> currencies;
    bool positionCheck;
    int rating;
    unordered_map<string, int> position;
    // unordered_map<Instrument, int> position;
    static unordered_map<string, Client> clientMap;
    Client(string id, unordered_set<string> currencies, bool positionCheck, int rating);
    static void readcsv(string filename);
    static void printMap();
};
#endif