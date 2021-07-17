// Name: Danny Lei
// Seneca Student ID: 164700197
// Seneca email: jylei1@senecacollege.ca
// Date of completion: 07/05/21
//
// I confirm that I am the only author of this file
//   and the content was created entirely by me.
#ifndef SDDS_STATION_H
#define SDDS_STATION_H
namespace sdds {
    class Station{
        int m_id;
        std::string m_name;
        std::string m_description;
        size_t m_serial;
        size_t m_noOfItems;
        static size_t m_widthField;
        static int id_generator;
    public:
        Station(const std::string&);
        const std::string& getItemName() const;
        size_t getNextSerialNumber();
        size_t getQuantity() const;
        void updateQuantity();
        void display(std::ostream& os, bool full) const;
    };
}
#endif