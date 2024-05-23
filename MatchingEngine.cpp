#include <iostream>
#include "Client.h"
#include "Order.h"

int main() { 
  Client::readcsv("./example-set/input_clients.csv");
  Order::readcsv("./example-set/input_orders.csv");
  return 0;
}