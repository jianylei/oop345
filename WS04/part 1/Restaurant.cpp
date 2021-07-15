/*
Danny Lei - 164700197
6/14/21
I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.
*/
#include "Restaurant.h"

namespace sdds {
    Restaurant::Restaurant(const Reservation* reservations[], size_t cnt) {
        m_numOfRes = cnt;
        m_reservations = new Reservation[m_numOfRes];

        for(size_t i = 0; i < m_numOfRes; i++) {
            m_reservations[i] = *reservations[i];
        }
    }

    Restaurant::Restaurant(const Restaurant& res) {
        *this = res;
    }

    Restaurant& Restaurant::operator=(const Restaurant& res) {
        if(&res != this && res.size() > 0) {
            m_numOfRes = res.size();
            if(m_reservations != nullptr) {
                delete [] m_reservations;
            }

            m_reservations = new Reservation[m_numOfRes];
            for(size_t i = 0; i < m_numOfRes; i++) {
                m_reservations[i] = res.m_reservations[i];
            }
        }
        return *this;
    }

    Restaurant::Restaurant(Restaurant&& res)noexcept {
        *this = std::move(res);
    }


    Restaurant& Restaurant::operator=(Restaurant&& res)noexcept {
        if(&res != this && res.size() > 0) {
            if(m_reservations != nullptr) {
                delete [] m_reservations;
            }
            m_numOfRes = res.m_numOfRes;
            m_reservations = res.m_reservations;

            res.m_numOfRes = 0;
            res.m_reservations = nullptr;
        }
        return *this;
    }

    Restaurant::~Restaurant() {
        delete [] m_reservations;
        m_reservations = nullptr;
    }

    size_t Restaurant::size() const {
        return m_numOfRes;
    }

    std::ostream& operator<<(std::ostream& os, const Restaurant& res) {
        static size_t CALL_CNT;
        
        os << "--------------------------" << std::endl;
        os << "Fancy Restaurant (" << ++CALL_CNT << ")" << std::endl;
        os << "--------------------------" << std::endl;

        if(res.size() > 0) {
            for(size_t i = 0; i < res.size(); i++) {
                os << res.m_reservations[i];
            }
        }
        else {
            os << "This restaurant is empty!" << std::endl;
        }

        os << "--------------------------" << std::endl;
        return os;
    }
}
