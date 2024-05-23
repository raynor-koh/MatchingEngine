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

using namespace std;


unordered_map<string, Order> Order::ordersMap;

// Order::Order(string time, string id, Instrument instrument, int quantity, Client client, double price, bool side) {
//   this->time = time;
//   this->instrument = instrument;
//   this->quantity = quantity;
//   this->client = client;
//   this->price = price;
//   this->side = side;
// }

Order::Order(string time) {
  
}
void Order::readcsv(string filename) {

}


