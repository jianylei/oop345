// Name: Danny Lei
// Seneca Student ID: 164700197
// Seneca email: jylei1@senecacollege.ca
// Date of completion: 07/05/21
//
// I confirm that I am the only author of this file
//   and the content was created entirely by me.
#include <string>
#include "Utilities.h"
namespace sdds {
    char Utilities::m_delimiter = ' ';

    void Utilities::setFieldWidth(size_t newWidth) {
        m_widthField = newWidth;
    }

    size_t Utilities::getFieldWidth() const {
        return m_widthField;
    }

    std::string Utilities::extractToken(const std::string& str, size_t& next_pos, bool& more){
        std::string strExtracted{};
        if (m_delimiter == str.at(next_pos)) {
            more = false;
            throw "There is not any token between delimiters";
        }
        size_t pos = str.find(m_delimiter,next_pos);
        if (pos == std::string::npos) {
            more = false;
        }
        strExtracted = str.substr(next_pos, pos - next_pos);
        next_pos = pos + 1;
        if (strExtracted.length() > m_widthField) {
            setFieldWidth(strExtracted.length());
        }
        return strExtracted;
    }

    void Utilities::setDelimiter(char newDelimiter) {
        m_delimiter = newDelimiter;
    }

    char Utilities::getDelimiter() {
        return m_delimiter;
    }
}