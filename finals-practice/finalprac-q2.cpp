#include <iostream>
#include <string>
#include <algorithm>
#include <numeric>
#include <thread>
#include <vector>
using namespace std;

struct Gem {
  string name;
  string colour;
  int shine;
  bool polished;
};

class Box {
  vector<unique_ptr<Gem>> gems;
public: 
  Box& operator+=(const Gem &gem){
    unique_ptr<Gem> tmp(new Gem(gem));
    gems.push_back(move(tmp));
    return *this;
  };

  Box& operator-=(const string &gemName){
    auto it = remove_if(gems.begin(),gems.end(),[&gemName](unique_ptr<Gem> &gem){
      return gem->name == gemName;
    });

    if(it == gems.end()) {
      throw gemName + " not found";
    }
    else {
      gems.erase(it, gems.end());
      cout << gemName << " has been removed" <<endl;
    }
    return *this;
  };

  void display(){
    for_each(gems.begin(), gems.end(),[](unique_ptr<Gem> &gem) {
      string polished = (gem->polished)? "polished" : "non-polished";
      cout << gem->name << " " << gem->colour << " " << gem->shine << " " << polished << endl;
    });
  };

  void process(){
    vector<thread> threadVector;
    for_each(gems.begin(),gems.end(),[&](unique_ptr<Gem> &gem){
      if(gem->polished == false) {
        threadVector.push_back(thread([&](){
          gem->polished = true;
          gem->shine += 20;
        }));
      }
    });
    for(auto&i: threadVector) {
      i.join();
    }
  };
};

int main() {

  Box b;

  cout << "\nAdding Gems" << endl;
  b += Gem{"Emerald", "Green", 20, false};
  b += Gem{"Emerald", "Green2", 20, false};
  b += Gem{"Ruby", "Red", 50, true};
  b += Gem{"Sapphire", "Blue", 80, false};
  b += Gem{"Onyx", "Black", 60, false};
  b += Gem{"Opal", "White", 10, false};
  b.display();

  cout << "\nRemoving Gems" << endl;
  try {
    b -= "Ruby";
    b -= "Emerald";
    b -= "Diamond";
    b.display();
  }
  catch (string c) {
    cout << c << endl;
  }

  b.display();

  cout << "\nPolishing Gems" << endl;
  b.process();
  b.display();


  cout << "\nVector of Boxes" << endl;
  vector<unique_ptr<Box>> boxes;
  unique_ptr<Box> b1(new Box());
  unique_ptr<Box> b2(new Box());
  unique_ptr<Box> b3(new Box());
  boxes.push_back(move(b1));
  boxes.push_back(move(b2));
  boxes.push_back(move(b3));
  
  //boxes.push_back(new Box());
  //boxes.push_back(new Box());
  //boxes.push_back(new Box());

  for_each(boxes.begin(),boxes.end(),[](unique_ptr<Box> &x){
        x->operator+=(Gem{ "Emerald", "Green", 20, false });
      x->operator+=(Gem{ "Ruby", "Red", 90, false });
      x->operator+=(Gem{ "Sapphire", "Blue", 40, false });
  });

  for_each(boxes.begin(),boxes.end(),[](unique_ptr<Box> &x){
        x->display();
  });
}