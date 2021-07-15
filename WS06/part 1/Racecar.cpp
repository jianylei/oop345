/*
Danny Lei - 164700197
07/04/21
I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.
*/
#include "Racecar.h"
namespace sdds {
    Racecar::Racecar(std::istream& in):Car(in) {
        std::string tmp;
        in >> m_booster;
        if(in.fail()) {
            throw std::invalid_argument("Invalid record!");
        }
    }

    void Racecar::display(std::ostream& out) const{
        Car::display(out);
        out << '*';
    }

    double Racecar::topSpeed() const{
        return Car::topSpeed()*(m_booster + 1);
    }
}