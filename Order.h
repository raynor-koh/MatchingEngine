#pragma once
#include "Instrument.h"
#include "Client.h"
#include <string>
#include <unordered_map>
#include <unordered_set>

using namespace std;

class Order {
  public:
    Order(string time, string id, Instrument &instrument, int quantity, Client &client, double price, bool side);
    static unordered_map<string, Order> ordersMap;
    //amend time to be proper type
    Time time;
    string id;
    Instrument instrument;
    int quantity;
    double price;
    bool side;
    Client client;
    static void readcsv(string filename);
    static void printMap();
};