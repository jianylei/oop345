// Name: Danny Lei
// Seneca Student ID: 164700197
// Seneca email: jylei1@senecacollege.ca
// Date of completion: 07/11/21
//
// I confirm that I am the only author of this file
//   and the content was created entirely by me.
#ifndef SDDS_CUSTORDER_H
#define SDDS_CUSTORDER_H
#include <string>
#include "Station.h"
namespace sdds {  
    class CustomerOrder{
        std::string m_name;
        std::string m_product;  
        size_t m_cntItem{ 0u };
        struct Item {
	        std::string m_itemName;
	        size_t m_serialNumber{0};
	        bool m_isFilled{false};

	        Item(const std::string& src) : m_itemName(src) {};
        }** m_lstItem { nullptr };
        static size_t m_widthField;
        void itemClear();
    public:
        CustomerOrder(){};
        CustomerOrder(const std::string&);
        CustomerOrder(const CustomerOrder&) {
            throw "Copy constructor is NOT to be called!";
        };
        CustomerOrder&operator=(const CustomerOrder&) = delete;
        CustomerOrder(CustomerOrder&&)noexcept;
        CustomerOrder&operator=(CustomerOrder&&)noexcept;
        ~CustomerOrder();
        bool isFilled() const;
        bool isItemFilled(const std::string& itemName) const;
        void fillItem(Station& station, std::ostream& os);
        void display(std::ostream& os) const;
    };
}
#endif