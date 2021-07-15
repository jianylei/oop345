/*
Danny Lei - 164700197
6/14/21
I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.
*/
#include <iostream>

#ifndef SDDS_RESERVATION_H_
#define SDDS_RESERVATION_H_
namespace sdds {
    class Reservation {
        std::string m_resID;
        std::string m_name;
        std::string m_email;
        size_t m_partySize{0u};
        size_t m_day{0u};
        size_t m_hour{0u};
    public:
        Reservation(){};
        Reservation(const std::string& res);
        friend std::ostream& operator << (std::ostream &os, const Reservation& res);
    };
}
#endif