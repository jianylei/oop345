/*
Danny Lei - 164700197
6/21/21
I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.
*/
#include <fstream>
#include <iomanip>
#include "SpellChecker.h"
namespace sdds{
    SpellChecker::SpellChecker(const char* filename) {
        std::ifstream file(filename);

        if(!file) { throw "Bad file name!"; }
        else {
            std::string tmp;

            auto trimWS = [=](std::string str) {
                str = str.substr(str.find_first_not_of(" \t\f\n\v\r"));
                str = str.substr(0, str.find_last_not_of(" \t\f\n\v\r")+1);
                return str;
            };

            for(size_t i = 0; getline(file, tmp);i++) {
                m_badWords[i] = tmp.substr(0,tmp.find(' '));
                tmp.erase(0, m_badWords[i].length());
                m_goodWords[i] = trimWS(tmp);
            }
        }
    }

    void SpellChecker::operator()(std::string& text) {
        for(size_t i = 0; i < maxWords; i++) {
            while (text.find(m_badWords[i]) != std::string::npos) {
                text.replace(text.find(m_badWords[i]), m_badWords[i].size(), m_goodWords[i]);
                m_badWordsCNT[i]++;
            }
        }
    }

    void SpellChecker::showStatistics(std::ostream& out) const {
        out << "Spellchecker Statistics" << std::endl;
        for(size_t i = 0; i < maxWords; i++) {
            out << std::setw(15) << std::right << m_badWords[i];
            out << ": " << m_badWordsCNT[i] << " replacements" << std::endl;
        }
    }
}