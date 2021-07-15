/*
Danny Lei - 164700197
07/04/21
I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.
*/
#include <sstream>
#include "Utilities.h"
#include "Car.h"
#include "Racecar.h"
namespace sdds {
    Vehicle* createInstance(std::istream& in) {
        Vehicle* tmp = nullptr;
        std::string line;

        getline(in, line);
        line.erase(0, line.find_first_not_of(' '));
        if(!line.empty()) {
            std::stringstream sstream(line);

            getline(sstream, line, ',');

            if(line[0] == 'c' || line[0] == 'C') {
                tmp = new Car(sstream);
            }
            else if(line[0] == 'r' || line[0] == 'R') {
                tmp = new Racecar(sstream);
            }
            else {
                throw "Unrecognized record type: [" + line + "]";
            }
        }
        
        
        return tmp;
    }
    
}