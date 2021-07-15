/*
Danny Lei - 164700197
06/04/21
I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.
*/
#include "Pair.h"

#ifndef SDDS_PAIRSUMMABLE_H_
#define SDDS_PAIRSUMMABLE_H_
namespace sdds {
   template<typename V, typename K>
	class PairSummable : public Pair<V, K> {
		static V initial;
		static size_t m_minWidth; 
	public:
		PairSummable() {
		}

		PairSummable(const K& key, const V& value = initial) : Pair<V, K>(key, value) {
			//if size of key is greater than current m_minWidth, set m_minWidth to size of key
			if (key.size() > m_minWidth)
				m_minWidth = key.size();
		}

		bool isCompatibleWith(const PairSummable<V, K>& b) const {
			//return true if both objs have same key - else false 
			return b.key() == this->key();
		}

		PairSummable& operator+=(const PairSummable& ps) {
			*this = PairSummable(this->key(), this->value() + ps.value());
			return *this;
		}

		void display(std::ostream& os) const {
			os.setf(std::ios::left);
			os.width(m_minWidth);
			Pair<V, K>::display(os);
			os.unsetf(std::ios::left);
		};
	};
	//definition for static m_minWidth
	template <typename V, typename K>
	size_t PairSummable<V, K>::m_minWidth; //static size_t defaults to 0

	//definition for static initial
	template<typename V, typename K>
	V PairSummable<V, K>::initial; //static size_t, int, long... defaults to 0
								   //string defaults to empyty string

	//specialization for templated PairSummable class += operator
	template<>
	PairSummable<std::string, std::string>& PairSummable<std::string, std::string>::operator+=(const PairSummable <std::string, std::string>& ps) {
		//if current obj value is empty concat " " - else ", "
		*this = PairSummable(this->key(), this->value() + ((!this->value().empty()) ? ", " : "") + ps.value());
		
		return *this;
	};
}
#endif