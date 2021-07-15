// Name: Danny Lei
// Seneca Student ID: 164700197
// Seneca email: jylei1@senecacollege.ca
// Date of completion: 07/11/21
//
// I confirm that I am the only author of this file
//   and the content was created entirely by me.
#include <iomanip>
#include <algorithm>
#include "CustomerOrder.h"
#include "Utilities.h"
namespace sdds {
    size_t CustomerOrder::m_widthField;
    
    CustomerOrder::CustomerOrder(const std::string& str) {
        Utilities util;
        size_t pos{ 0u }, i{ 0u };
        bool more = true;

        m_name = util.extractToken(str, pos, more);
        m_product = util.extractToken(str, pos, more);
        m_cntItem = std::count(str.begin(), str.end(), util.getDelimiter()) - 1;
        m_lstItem = new Item*[m_cntItem];
        while(more) {
            m_lstItem[i++] = new Item(util.extractToken(str, pos, more));
        }
        m_widthField = (util.getFieldWidth() > m_widthField)? util.getFieldWidth(): m_widthField;
    }

    CustomerOrder::CustomerOrder(CustomerOrder&& co)noexcept {
        *this = std::move(co);
    }

    CustomerOrder&CustomerOrder::operator=(CustomerOrder&& co)noexcept {
        if(this != &co && co.m_cntItem != 0) {
            itemClear();
            m_name = co.m_name;
            m_product = co.m_product;
            m_cntItem = co.m_cntItem;
            m_lstItem = co.m_lstItem;
            m_widthField = co.m_widthField;

            co.m_name = "";
            co.m_product = "";
            co.m_cntItem = 0;
            co.m_lstItem = nullptr;
        }
        return *this;
    }

    CustomerOrder::~CustomerOrder() {
        itemClear();
    }

    bool CustomerOrder::isFilled() const {
        bool flag = true;
        for(size_t i = 0; i < m_cntItem && flag; i++) {
            flag = m_lstItem[i]->m_isFilled;
        }
        return flag;
    }

    bool CustomerOrder::isItemFilled(const std::string& itemName) const {
        bool flag = true;
        for(size_t i = 0; i < m_cntItem && flag; i++) {
            if(m_lstItem[i]->m_itemName == itemName) {
                flag = m_lstItem[i]->m_isFilled;
            }
        }
        return flag;
    }

    void CustomerOrder::fillItem(Station& station, std::ostream& os) {
        bool inStock = true;
        for(size_t i = 0; i < m_cntItem && inStock; i++) {
            if(m_lstItem[i]->m_itemName == station.getItemName()) {
                if(station.getQuantity() > 0) {
                    station.updateQuantity();
                    m_lstItem[i]->m_serialNumber = station.getNextSerialNumber();
                    m_lstItem[i]->m_isFilled = true;
                    os << "    Filled "; 
                }
                else {
                    inStock = false;
                    os << "Unable to fill ";
                }
                os << m_name << ", " << m_product << " [" << m_lstItem[i]->m_itemName << "]" << std::endl;
            }
        }
    }

    void CustomerOrder::display(std::ostream& os) const {
        os << m_name << " - " << m_product << std::endl;
        for(size_t i = 0; i < m_cntItem; i++) {
            os << "[" << std::right << std::setw(6) << std::setfill('0') << m_lstItem[i]->m_serialNumber << "] ";
            os << std::left << std::setw(m_widthField) << std::setfill(' ') << m_lstItem[i]->m_itemName << " - ";
            std::string str = (m_lstItem[i]->m_isFilled)? "FILLED": "TO BE FILLED";
            os << str << std::endl;
        }
    }

    void CustomerOrder::itemClear() {
        if(m_lstItem != nullptr) {
            for(size_t i = 0; i < m_cntItem; i++) {
                delete m_lstItem[i];
            }
            delete []m_lstItem;
            m_lstItem = nullptr;
            m_cntItem = 0;
        }
    }
}