#pragma once
#include <iostream>
#include <string>
#include "Instrument.h"
#include "Client.h"
#include <unordered_map>
#include <unordered_set>
#include <fstream>
#include <vector>
#include <sstream> // std::stringstream

using namespace std;

class Order {
  public:
    static unordered_set<Order> ordersSet;
    string id;
    Instrument instrument;
    int quantity;
    double price;
    bool side;
    Client client;
    static void readcsv(string filename);
};