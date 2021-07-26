// Workshop 8 - Smart Pointers
// 2019/11 - Cornel
// 2021/07 - Danny Lei

#include <memory>
#include <algorithm>
#include "List.h"
#include "Element.h"
#include "Utilities.h"

using namespace std;

namespace sdds {
	List<Product> mergeRaw(const List<Description>& desc, const List<Price>& price) {
		List<Product> priceList;
		for(size_t i = 0; i < desc.size(); i++) {
			for(size_t j = 0; j < price.size(); j++) {
				if(desc[i].code == price[j].code) {
					Product *p = new Product(desc[i].desc, price[j].price);
					try{
						p->validate();	
						priceList += p;
					} catch(std::string &err) {
						p->Trace = false;
						delete p;
						p->Trace = true;
						throw err;
					}
					delete p;
				}
			}
		}
		return priceList;
	}

	List<Product> mergeSmart(const List<Description>& desc, const List<Price>& price) {
		List<Product> priceList;
		for(size_t i = 0; i < desc.size(); i++) {
			for(size_t j = 0; j < price.size(); j++) {
				if(desc[i].code == price[j].code) {
					std::unique_ptr<Product> p(new Product(desc[i].desc, price[j].price));
					p->validate();
					priceList += p;
				}
			}
		}
		return priceList;
	}
}