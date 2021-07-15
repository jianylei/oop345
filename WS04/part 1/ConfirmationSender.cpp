/*
Danny Lei - 164700197
6/14/21
I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.
*/
#include "ConfirmationSender.h"

namespace sdds {
    ConfirmationSender::ConfirmationSender(const ConfirmationSender& cs) {
        *this = cs;
    }
    
    ConfirmationSender& ConfirmationSender::operator=(const ConfirmationSender& cs) {
        if (&cs != this && cs.m_numOfRes > 0) {
            if(m_reservations != nullptr) { delete [] m_reservations; }

            m_numOfRes = cs.m_numOfRes;
            m_reservations = new const Reservation*[m_numOfRes];
            for(size_t i = 0; i < m_numOfRes; i++) {
                m_reservations[i] = cs.m_reservations[i];
            }
        }
        return *this;
    }

    ConfirmationSender::ConfirmationSender(ConfirmationSender&& cs)noexcept {
        *this = std::move(cs);
    }
    
    ConfirmationSender& ConfirmationSender::operator=(ConfirmationSender&& cs)noexcept {
        if(&cs != this && cs.m_numOfRes > 0) {
            if(m_reservations != nullptr) { delete[] m_reservations; }
            
            m_numOfRes = cs.m_numOfRes;
            m_reservations = cs.m_reservations;

            cs.m_numOfRes = 0;
            cs.m_reservations = nullptr;
        }
        return *this;
    }

    ConfirmationSender::~ConfirmationSender() {
        delete[] m_reservations;
        m_reservations = nullptr;
    }

    //returns index of res, 0 if not in array
    size_t ConfirmationSender::findRes(const Reservation& res) {
        size_t flag = 0;
        if(m_numOfRes > 0) {
            for(size_t i = 0; flag == 0 && i < m_numOfRes; i++) {
                if(&res == m_reservations[i]) { flag = i; }
            }
        }
        return flag;
    }

    ConfirmationSender& ConfirmationSender::operator+=(const Reservation& res) {
       size_t flag = findRes(res); //find index of res, 0 if not found

       if(flag == 0) {
           const Reservation** tmp = new const Reservation*[++m_numOfRes];

            if(m_numOfRes > 1) {
                for(size_t i = 0; i < m_numOfRes - 1; i++) {
                tmp[i] = m_reservations[i];
                }
            }
            tmp[m_numOfRes-1] = &res;

            if(m_numOfRes > 1) {
                delete [] m_reservations;
            }
            m_reservations = tmp;
       }
       return *this;
    }

    ConfirmationSender &ConfirmationSender::operator-=(const Reservation &res) {
        size_t flag = findRes(res); //find index of res, 0 if not found
        if (flag != 0) {
            if (m_numOfRes == 1) { //if size is only 1, delete
                delete[] m_reservations;
                m_reservations = nullptr;
            }
            else {
                const Reservation **tmp = new const Reservation *[--m_numOfRes];

                for (size_t i = 0, j = 0; j < m_numOfRes; i++) {
                    if (i != flag) {
                        tmp[j] = m_reservations[i];
                        j++;
                    };
                }
                delete[] m_reservations;
                m_reservations = tmp;
            }
        }
        return *this;
    }

    std::ostream& operator<<(std::ostream& os, const ConfirmationSender& cs) {
        os << "--------------------------" << std::endl;
		os << "Confirmations to Send" << std::endl;
		os << "--------------------------" << std::endl;

		if (cs.m_numOfRes == 0) { 
            os << "There are no confirmations to send!" << std::endl; 
        }
		else {
			for (size_t i = 0; i < cs.m_numOfRes; i++) {
				os << *cs.m_reservations[i];
			}
		}

		os << "--------------------------" << std::endl;
		return os;
    }
}