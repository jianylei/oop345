/*
Danny Lei - 164700197
07/04/21
I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.
*/
#ifndef SDDS_CAR_H
#define SDDS_CAR_H
#include "Vehicle.h"
namespace sdds {
    class Car: public Vehicle {
        std::string m_maker;
        std::string m_condition;
        double m_topSpeed{ 0.0 };
    public:
        Car(){};
        Car(std::istream&);
        std::string condition() const;
        double topSpeed() const;
        void display(std::ostream& out) const;
    };
}
#endif