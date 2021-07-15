/*
Danny Lei - 164700197
6/21/21
I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.
*/
#ifndef SDDS_SPELLCHECKER_H_
#define SDDS_SPELLCHECKER_H_
#include <string>
namespace sdds {
    const int maxWords = 6;
    class SpellChecker {
        std::string m_badWords[maxWords];
        std::string m_goodWords[maxWords];
        size_t m_badWordsCNT[maxWords]{ 0 };
    public:
        SpellChecker(){};
        SpellChecker(const char* filename);
        void operator()(std::string& text);
        void showStatistics(std::ostream& out) const;
    };
}
#endif