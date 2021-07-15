/*
Danny Lei - 164700197
6/21/21
I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.
*/
#include <string>
#include <iomanip>
#include "Movie.h"
namespace sdds{
    Movie::Movie(const std::string &strMovie) {
        std::string tmp = strMovie;
        auto trimWS = [=](std::string str) {
            str = str.substr(str.find_first_not_of(" \t\f\n\v\r"));
            str = str.substr(0, str.find_last_not_of(" \t\f\n\v\r") + 1);
            return str;
        };
        size_t i = tmp.find(',');
        m_title = trimWS(tmp.substr(0, i));
        tmp.erase(0, ++i);

        i = tmp.find(',');
        m_year = stoi(tmp.substr(0, i));
        tmp.erase(0, ++i);

        m_description = trimWS(tmp.substr(0));
    }

    const std::string& Movie::title() const {
        return m_title;
    }
    
    std::ostream& operator<<(std::ostream& os, const Movie& movie) {
        os << std::setw(40) << movie.m_title << " | " << std::setw(4) << movie.m_year;
        os << " | " << movie.m_description << std::endl;
        return os;
    }
}