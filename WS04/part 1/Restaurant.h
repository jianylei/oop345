/*
Danny Lei - 164700197
6/14/21
I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.
*/
#ifndef SDDS_RESTAURANT_H_
#define SDDS_RESTAURANT_H_
#include "Reservation.h"

namespace sdds {
    class Restaurant {
       Reservation *m_reservations{ nullptr };
       size_t m_numOfRes{ 0 };
    public:
        Restaurant(){};
        Restaurant(const Reservation* reservations[], size_t cnt);
        Restaurant(const Restaurant&);
        Restaurant& operator=(const Restaurant&);
        Restaurant(Restaurant&&)noexcept;
        Restaurant& operator=(Restaurant&&)noexcept;
        ~Restaurant();
        size_t size() const;
        friend std::ostream& operator<<(std::ostream& os, const Restaurant& res);
    };
}
#endif