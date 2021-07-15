/*
Danny Lei - 164700197
05/31/21
I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.
*/
#ifndef SDDS_STRINGSET_H_
#define SDDS_STRINGSET_H_
namespace sdds {
    class StringSet{
        std::string* m_str{ nullptr };
        size_t numOfStrings{ 0 };
        void reset();
        void getNumString(std::ifstream&, char delim = ' ');
    public:
        StringSet();
        StringSet(const char* fileName);
        StringSet(const StringSet&);
        StringSet(StringSet&&)noexcept;
        ~StringSet();
        StringSet& operator=(const StringSet&);
        StringSet& operator=(StringSet&&)noexcept;
        size_t size();
        std::string operator[] (size_t);
    };

}
#endif