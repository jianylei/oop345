/*
Danny Lei - 164700197
6/21/21
I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.
*/
#ifndef SDDS_BOOK_H_
#define SDDS_BOOK_H_
#include <string>
namespace sdds {
    class Book {
        std::string m_auther;
        std::string m_title;
        std::string m_country;
        size_t m_year{ 0u };
        double m_price{ 0.0 };
        std::string m_description;
    public:
        Book(){};
        Book(const std::string& strBook);
        const std::string& title() const;
        const std::string& country() const;
        const size_t& year() const;
        double& price();

        friend std::ostream& operator<<(std::ostream& os, const Book&);

        template <class T>
        void fixSpelling(T& spellChecker) {
            spellChecker(m_description);
        }
    };
}
#endif