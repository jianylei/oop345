/*
Danny Lei - 164700197
07/04/21
I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.
*/
#include "Autoshop.h"
namespace sdds {
    Autoshop::~Autoshop() {
        for(auto& i : m_vehicles){
            delete i;
        }
    }

    Autoshop& Autoshop::operator +=(Vehicle* theVehicle) {
        m_vehicles.push_back(theVehicle);
        return *this;
    }
    
    void Autoshop::display(std::ostream& out) const{
        out << "--------------------------------" << std::endl;
		out << "| Cars in the autoshop!        |" << std::endl;
		out << "--------------------------------" << std::endl;

        for(auto& i : m_vehicles){
            i->display(out);
            out << std::endl;
         }
        out << "--------------------------------" << std::endl;
    }
}