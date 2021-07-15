/*
Danny Lei - 164700197
07/04/21
I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.
*/
#include <vector>
#include <list>
#include "Vehicle.h"
#ifndef SDDS_AUTOSHOP_H
#define SDDS_AUTOSHOP_H
namespace sdds {
    class Autoshop {
        std::vector<Vehicle*> m_vehicles{};
    public: 
        ~Autoshop();
        Autoshop& operator +=(Vehicle* theVehicle);
        void display(std::ostream& out) const;
        template<class T>
        void select(T test, std::list<const Vehicle*>& vehicles) {
            for(auto& i : m_vehicles) {
                if(test(i)) {
                    vehicles.push_back(i);
                }
            }
        }
    };
}
#endif