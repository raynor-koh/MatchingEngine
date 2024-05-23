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
    Order(string time, string id, Instrument &instrument, int quantity, Client &client, double price, bool side);
    static unordered_map<string, Order> ordersMap;
    //amend time to be proper type
    string time;
    string id;
    Instrument instrument;
    int quantity;
    double price;
    bool side;
    Client client;
    static void readcsv(string filename);
    static void printMap();
};