#include <iostream>
#include <string>
#include <algorithm>
#include <numeric>
#include <vector>
#include <iostream>
#include <thread>
using namespace std;

struct ComputerParts {
  string partType;
  string model;
  double price;
  double powerConsumption;
  bool used;
};

void add() {
    cout << "thread test " << this_thread::get_id() << endl;
  }

int main() {

  vector<ComputerParts> wishList;

  // Task 1
  // Add to the vector some number of desired Computer Parts
  // Eg. GPU, RTX 3080, 1000, 300, false
  ComputerParts parts[] = {{"GPU", "RTX 3080", 1000, 300, true}, {"GPU", "RTX 3090", 1200.99, 400, true}, {"GPU", "RTX 3060", 850, 280, false}, {"GPU", "RTX 3080 Ti", 1200, 350, true}, {"Monitor", "Samsung LU28R550UQNXZA", 299, 100, false}, {"Monitor", "LG UltraFine 32UN880-B", 800, 80, false}};

  for(size_t i = 0; i < 6; i++)
    wishList.push_back(parts[i]);

  // Task 2
  // Sort the wishList by price in ascending order

  sort(wishList.begin(), wishList.end(),[](ComputerParts &p1, ComputerParts &p2){
    return p1.price < p2.price;
  });

  // Task 3
  // Print to the screen the part in the wishList the part that has the most and least powerConsumption

  auto pairPower = minmax_element(wishList.begin(), wishList.end(),[](const ComputerParts &a, const ComputerParts &b){
      return a.powerConsumption < b.powerConsumption;
  });

  cout << "least power: " << pairPower.first->model << endl;
  cout << "most power: " << pairPower.second->model << endl;

  // Task 4
  // Remove from the wishList all the parts that are 'used'

  auto it = remove_if(wishList.begin(), wishList.end(),[](ComputerParts &parts){
    return parts.used == true;
  });
  wishList.erase(it, wishList.end());
  cout << "it: " << it->model << endl;
  for_each(wishList.begin(), wishList.end(),[](ComputerParts & parts){
    cout << parts.model << endl;
  });


  // Task 5
  // Find the average cost of all the parts in the wishList
  double avg = 0;
  for_each(wishList.begin(), wishList.end(),[&avg](ComputerParts &parts){
    avg += parts.price;
  });

  avg = avg/wishList.size();
  cout << avg << endl;
  // Task 6
  // Change all the items in the wishList to 'used' and reduce their price by 20% and save this result to a new vector

  vector<ComputerParts> newList;

  for_each(wishList.begin(), wishList.end(),[&newList](ComputerParts & parts){
    parts.used = true;
    parts.price = parts.price - (parts.price * 0.20);
    newList.push_back(parts);
  });

  for_each(newList.begin(), newList.end(), [](ComputerParts &parts){
    cout <<  parts.model << " " << parts.price << endl;
  });

  // Task 7
  // Figure out how many of a given part type is in the wishList eg. how many CPUs and print to the screen

  auto count = count_if(wishList.begin(), wishList.end(), [](ComputerParts & parts){
    return parts.partType == "Monitor";
  });

  cout << count <<endl;

  // Task 8
  // Create new wishList of computer parts and combine it with the original one
  vector<ComputerParts> _list;
  ComputerParts newParts[] = {{"GPU", "RTX 3060", 650, 200, true}, {"GPU", "RTX 3090 Ti", 1450, 500, false}, {"GPU", "RTX 3060", 900, 280, false}, {"GPU", "Radeon RX 5500 XT", 200, 120, false}, {"Monitor", "ViewSonic Elite XG270", 499, 50, false}, {"Monitor", "Apple Pro Display XDR", 4999, 80, false}};
  for(size_t i = 0; i < 6; i++)
    _list.push_back(newParts[i]);

  vector<ComputerParts> combinedList;

  merge(wishList.begin(),wishList.end(), _list.begin(), _list.end(), back_inserter(combinedList),[](ComputerParts &p1, ComputerParts &p2) {
    return p1.price < p2.price;
  });

  for_each(combinedList.begin(), combinedList.end(), [](ComputerParts &parts){
    cout <<  parts.model << " " << parts.price << endl;
  });


}
