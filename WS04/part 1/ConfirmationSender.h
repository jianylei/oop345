/*
Danny Lei - 164700197
6/14/21
I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.
*/
#ifndef SDDS_CONFIRMATIONSENDER_H_
#define SDDS_CONFIRMATIONSENDER_H_
#include "Reservation.h"

namespace sdds {
    class ConfirmationSender {
        const Reservation** m_reservations{ nullptr };
        size_t m_numOfRes{ 0 };
        size_t findRes(const Reservation& res);
    public:
        ConfirmationSender(){};
        ConfirmationSender(const ConfirmationSender&);
        ConfirmationSender& operator=(const ConfirmationSender&);
        ConfirmationSender(ConfirmationSender&&)noexcept;
        ConfirmationSender& operator=(ConfirmationSender&&)noexcept;
        ~ConfirmationSender();

        ConfirmationSender& operator+=(const Reservation& res);
        ConfirmationSender& operator-=(const Reservation& res);
        friend std::ostream& operator<<(std::ostream& os, const ConfirmationSender&);
    };
}
#endif