// Workshop 8 - Smart Pointers
// 2019/11 - Cornel


#include <memory>
#include <algorithm>
#include "List.h"
#include "Element.h"
#include "Utilities.h"

using namespace std;

namespace sdds {
	List<Product> mergeRaw(const List<Description>& desc, const List<Price>& price) {
		List<Product> priceList;
		for(auto i = 0; i < desc.size(); i++) {
			for(auto j = i; j < price.size(); j++) {
				if(desc[i].code == price[j].code) {
					Product *tmp = new Product(desc[i].desc, price[j].price);
					tmp->validate();
					priceList += tmp;
					delete tmp;
				}
			}
		}
		return priceList;
	}


		
	
}