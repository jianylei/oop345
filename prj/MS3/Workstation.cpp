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
            if(m_orders.front().isItemFilled(Station::getItemName())) {
                if(m_pNextStation) {
                    m_pNextStation->m_orders.push_back(std::move(m_orders.front()));
                    m_orders.pop_front();
                }
                else{
                    completed.push_back(std::move(m_orders.front()));
                    m_orders.pop_front();
                }
                moved = true;
            }
            else if(!Station::getQuantity) {
                 if(m_pNextStation) {
                    m_pNextStation->m_orders.push_back(std::move(m_orders.front()));
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
}
