// finalprac-q3.cpp
#include <iostream>
#include <string>
#include <string_view>
#include <vector>
#include <algorithm>
#include <numeric>
#include <thread>
#include <future>
#include "finalprac-q3.h"

TreasureBox::TreasureBox(const std::string* names, unsigned* weights, unsigned size){
  for (unsigned x = 0; x < size; ++x) {
    gems.push_back(Gem{ names[x], weights[x] });
    weight += weights[x];
  }
}

TreasureBox& TreasureBox::operator+=(const Gem& g) {
  gems.push_back(g);
  weight += g.weight;
  return *this;
}

void TreasureBox::update(const std::string& name) {
  std::vector<Gem>::iterator itr;
  for (itr = gems.begin(); itr != gems.end(); ++itr) {
    if (itr->name == name) {
      unsigned sum = 0;
      sum = std::accumulate(name.begin(), name.end(), 0);
      itr->weight += sum;
    }
  }
}

std::ostream& TreasureBox::display() const {
  std::cout << "TreasureBox Contents" << std::endl;
  for (auto& g : gems) {
    std::cout << g.name << " : " << g.weight << std::endl;
  }
  return std::cout;
}

void task(std::promise<unsigned>& p) {
  Gem gems[]{ {"Red" , 10}, {"Green", 20}, {"Blue", 30} };

  auto idx = std::find_if(gems, gems + 2, [](const Gem& g) {
    return g.name == "Green";
  });
}

int main() {

  std::string strs[]{ "Ruby", "Emerald", "Sapphire", "Opal" };
  unsigned nums[]{ 10, 20, 30, 40 };

  std::unique_ptr<TreasureBox> tbr(new TreasureBox());
  std::unique_ptr<TreasureBox> ptr(new TreasureBox(strs, nums, 4));
 
  std::string_view sv = "Ruby";
  std::string s = "Opal";
  ptr->update(sv);
  ptr->update(s);
  ptr->display();

  *ptr += Gem{ "Diamond", 50 } += Gem{ "Amber", 60 }; 
  (*ptr += Gem{ "Pearl", 70 }).display();

  std::promise<unsigned> pro;
  std::future<unsigned> fut = pro.get_future();

  std::thread t1;
  t1.join();
  t1 = std::thread(task, std::ref(pro));
  std::cout << "Promised Future: " << fut.get() << std::endl;
  t1.join();
}
