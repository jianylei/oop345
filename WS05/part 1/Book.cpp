/*
Danny Lei - 164700197
6/21/21
I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.
*/
#include <iomanip>
#include "Book.h"
namespace sdds {
    Book::Book(const std::string& strBook) {
        std::string tmp = strBook;
        //trim ws beginning and end
        auto trimWS = [=](std::string str) {
            str = str.substr(str.find_first_not_of(" \t\f\n\v\r"));
            str = str.substr(0, str.find_last_not_of(" \t\f\n\v\r")+1);
            return str;
        };
        size_t i = tmp.find(',');
        m_auther = trimWS(tmp.substr(0, i));
        tmp.erase(0, ++i);

        i = tmp.find(',');
        m_title = trimWS(tmp.substr(0, i));
        tmp.erase(0, ++i);

        i = tmp.find(',');
        m_country = trimWS(tmp.substr(0, i));
        tmp.erase(0, ++i);

        i = tmp.find(',');
        m_price = stod(tmp.substr(0, i));
        tmp.erase(0, ++i);

        i = tmp.find(',');
        m_year = stoi(tmp.substr(0,i));
        tmp.erase(0, ++i);

        m_description = trimWS(tmp.substr(0));
    }
    
    const std::string& Book::title() const {
        return m_title;
    }

    const std::string& Book::country() const {
        return m_country;
    }

    const size_t& Book::year() const {
        return m_year;
    }

    double& Book::price() {
        return m_price;
    }

    std::ostream& operator<<(std::ostream& os, const Book& bk) {
        os << std::setw(20) << bk.m_auther << " | ";
        os << std::setw(22) << bk.m_title << " | ";
        os << std::setw(5) << bk.m_country << " | ";
        os << std::setw(4) << bk.m_year << " | ";
        os << std::setw(6) << std::fixed << std::setprecision(2) << bk.m_price << " | ";
        os << bk.m_description << std::endl;

        return os;
    }
}