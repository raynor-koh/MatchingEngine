#include <iostream>
#include <string>
#include "Instrument.h"
#include "Order.h"
#include "Client.h"
#include <unordered_map>
#include <unordered_set>
#include <fstream>
#include <vector>
#include <sstream> // std::stringstream
#include <limits>

using namespace std;


unordered_map<string, Order> Order::ordersMap;

Order::Order(string time, string id, Instrument &instrument, int quantity, Client &client, double price, bool side) {
  this->time = time;
  this->instrument = instrument;
  this->quantity = quantity;
  this->client = client;
  this->price = price;
  this->side = side;
}

void Order::readcsv(string filename) {
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
    string readTime;
    string readID;
    int quantity;
    double price;
    bool side;
    readID = commaSepValues[1];
    Instrument instrument = Instrument::instrumentMap.at(commaSepValues[2]);
    quantity = stoi(commaSepValues[3]);
    Client client = Client::clientMap.at(commaSepValues[4]);
    side =  commaSepValues[6] == "Buy" ? true : false;
    if (commaSepValues[6] == "Market") {
      price = side ? numeric_limits<double>::infinity() : -numeric_limits<double>::infinity();
    } else {
      price = stod(commaSepValues[6]);
    }

    Order neworder = Order(readTime, readID, instrument, quantity, client, price, side);
    Order::ordersMap.insert(make_pair(readID, neworder));
  };
  File.close();
}


