// Name: Danny Lei
// Seneca Student ID: 164700197
// Seneca email: jylei1@senecacollege.ca
// Date of completion: 07/05/21
//
// I confirm that I am the only author of this file
//   and the content was created entirely by me.
#include <iostream>
#include <iomanip>
#include "Station.h"
#include "Utilities.h"
namespace sdds {
    size_t Station::m_widthField;
    int Station::id_generator;
    
    Station::Station(const std::string& str) {
        Utilities util;
        size_t pos{ 0u };
        bool more = true;
        
        m_id = ++id_generator;
        try {
            m_name = util.extractToken(str, pos, more);
            m_serial = stoi(util.extractToken(str, pos, more));
            m_noOfItems = stoi(util.extractToken(str, pos, more));
            m_widthField = (m_widthField < util.getFieldWidth())? util.getFieldWidth(): m_widthField;
            m_description = util.extractToken(str, pos, more);
        } catch(std::string& err) {
            std::cout << err;
        }
    }

    const std::string& Station::getItemName() const {
        return m_name;
    }

    size_t Station::getNextSerialNumber() {
        return m_serial++;
    }

    size_t Station::getQuantity() const {
        return m_noOfItems;
    }

    void Station::updateQuantity() {
        //m_noOfItems = (--m_noOfItems >= 0)? m_noOfItems: 0;
        m_noOfItems--;
        if (m_noOfItems < 0) {
            m_noOfItems = 0;
        }
    }

    void Station::display(std::ostream& os, bool full) const {
        os << '[' << std::setw(3) << std::setfill('0') << std::right << m_id << "] ";
        os << "Item: " << std::setw(m_widthField) << std::setfill(' ') << std::left << m_name;
        os << " [" << std::setw(6) << std::setfill('0') << std::right << m_serial << "]";

        if(full) {
            os << " Quantity: " << std::setw(m_widthField) << std::setfill(' ') << std:: left << m_noOfItems;
            os << " Description: " << m_description << std::endl;
        }
        else {
            os << std::endl;
        }
    }
}