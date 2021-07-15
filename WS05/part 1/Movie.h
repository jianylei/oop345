/*
Danny Lei - 164700197
6/21/21
I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.
*/
#ifndef SDDS_MOVIE_H_
#define SDDS_MOVIE_H_
namespace sdds {
    class Movie {
        std::string m_title;
        size_t m_year{ 0u };
        std::string m_description;
    public:
        Movie(){};
        Movie(const std::string& strMovie);
        const std::string& title() const;

        template <class T>
        void fixSpelling(T& spellChecker) {
            spellChecker(m_title);
            spellChecker(m_description);
        }

        friend std::ostream& operator<<(std::ostream& os, const Movie&);
    };
}
#endif