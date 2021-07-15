/*
Danny Lei - 164700197
06/04/21
I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.
*/
#ifndef SDDS_PAIR_H_
#define SDDS_PAIR_H_
namespace sdds {
    template<class V, class K>
    class Pair {
        V m_value;
        K m_key;
    public:
        Pair() {};
        Pair(const K& key, const V& value) : m_value{ value }, m_key{ key }{};
        const V& value() const { return m_value; };
        const K& key() const{ return m_key; };
        virtual void display(std::ostream& os) const {
            os << key() << " : " << value() << std::endl;
        }
    };
    
    template<class V, class K>
    std::ostream& operator<<(std::ostream& os, const Pair<V, K>& pair) {
        pair.display(os);
        return os;
    }
}
#endif