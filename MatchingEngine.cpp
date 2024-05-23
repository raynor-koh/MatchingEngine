#include <iostream>
#include "Client.h"
#include "Order.h"

int main() { 
  Client::readcsv("./example-set/input_clients.csv");
  Instrument::readcsv("./example-set/input_instruments.csv");
  Order::readcsv("./example-set/input_orders.csv");
  Order::printMap();
  return 0;
}

