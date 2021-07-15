/*
Danny Lei - 164700197
06/04/21
I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.
*/
#include "Set.h"

#ifndef SDDS_SETSUMMABLE_H_
#define SDDS_SETSUMMABLE_H_
namespace sdds {
   template <size_t N, typename T>
	class SetSummable : public Set<N, T> {
	public:
		//adds obj with same key as "filter" into an obj of "collection"
		T accumulate(const std::string& filter) const {
			T collection(filter);
			for (size_t i = 0; i < this->size(); i++)
				if (collection.isCompatibleWith(this->get(i)))
					collection += this->get(i);
			return collection;
		}
	};
}
#endif