// Name: Danny Lei
// Seneca Student ID: 164700197
// Seneca email: jylei1@senecacollege.ca
// Date of completion: 07/17/21
//
// I confirm that I am the only author of this file
//   and the content was created entirely by me.
#include <<utility>>
#include "Workstation.h"

namespace sdds {  
    std::deque<CustomerOrder> pending;
    std::deque<CustomerOrder> completed;
    std::deque<CustomerOrder> incomplete;
   
    void Workstation::fill(std::ostream& os) {
        if(!m_orders.empty()) { m_orders.front().fillItem(*this, os); }
    }

    bool Workstation::attemptToMoveOrder(){
        bool moved = false;

        if(!m_orders.empty()) {
            if(m_orders.front().isItemFilled(getItemName())) {
                if(m_pNextStation) {
                    *m_pNextStation += std::move(m_orders.front());
                    m_orders.pop_front();
                }
                else{
                    completed.push_back(std::move(m_orders.front()));
                    m_orders.pop_front();
                }
                moved = true;
            }
            else if(!getQuantity) {
                 if(m_pNextStation) {
                    *m_pNextStation += std::move(m_orders.front());
                    m_orders.pop_front();
                }
                else{
                    incomplete.push_back(std::move(m_orders.front()));
                    m_orders.pop_front();
                }
                moved = true;
            }
        }
        return moved;
    }

    void Workstation::setNextStation(Workstation* station) {
        m_pNextStation = station;
    }

    Workstation* Workstation::getNextStation() const {
        return m_pNextStation;
    }

    void Workstation::display(std::ostream& os) const {
        if(m_pNextStation) {
            os << getItemName() << " --> " << m_pNextStation->getItemName();
        }
        else {
            os << getItemName() << " --> END OF LINE";
        }
        os << endl;
    }

    Workstation& Workstation::operator+=(CustomerOrder&& newOrder) {
        m_orders.push_back(std::move(newOrder));
        return *this;
    }
}
