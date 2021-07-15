/*
Danny Lei - 164700197
06/04/21
I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.
*/
#ifndef SDDS_SET_H_
#define SDDS_SET_H_
namespace sdds {
    template<size_t N, class T>
    class Set {
        T m_collection[N];
        size_t m_numOfElements { 0 };
    public:
        size_t size() const{
            return m_numOfElements;
        }
        const T& get(size_t idx) const {
            return m_collection[idx];
        }
        void operator+=(const T& item) {
            if (m_numOfElements < N) {
                m_collection[m_numOfElements++] = item;
            }
        }
    };
}
#endif