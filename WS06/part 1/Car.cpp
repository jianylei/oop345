/*
Danny Lei - 164700197
07/04/21
I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.
*/
#include <iomanip>
#include "Car.h"
namespace sdds {
    Car::Car(std::istream& istr) {
      auto trimWS = [=](std::string str) {
            str.erase(0, str.find_first_not_of(" \t\f\n\v\r"));
            str.erase(str.find_last_not_of(" \t\f\n\v\r") + 1);
            return str;
        };

        getline(istr, m_maker, ',');
        m_maker = trimWS(m_maker);

        getline(istr, m_condition, ',');
        m_condition = trimWS(m_condition);

        if(m_condition == "" || m_condition.empty()) {
            m_condition = "n";
        }
        else if(m_condition != "n" && m_condition != "u" && m_condition != "b") {
            throw std::invalid_argument("Invalid record!");
        }
        try {
            std::string tmp;
            getline(istr, tmp, ',');
            m_topSpeed = stod(tmp);}
        catch(std::invalid_argument& err){
            throw std::invalid_argument("Invalid record!");
        }
    }

    std::string Car::condition() const{
        std::string tmp;
		if (m_condition == "n") {
			tmp = "new";
		}
		else if(m_condition == "u") {
			tmp = "used";
		}
		else if (m_condition == "b") {
			tmp = "broken";
		}
		return tmp;
    }

    double Car::topSpeed() const {
        return m_topSpeed;
    }

    void Car::display(std::ostream& out) const{
        out << "| " << std::right << std::setw(10) << m_maker << " | " << std::left << std::setw(6) << condition() << " | " << std::setw(6) << std::fixed << std::setprecision(2) << topSpeed() << " |";
    }
    
}
