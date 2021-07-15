/*
Danny Lei - 164700197
6/21/21
I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.
*/
#ifndef SDDS_COLLECTION_H_
#define SDDS_COLLECTION_H_
namespace sdds {
    template <class T>
    class Collection {
        std::string m_name{};
        T* m_collection{ nullptr };
        size_t m_sizeOfCol{ 0u };
        void(*m_observer)(const Collection<T>&, const T&){ nullptr };
    public:
        Collection(const std::string& name) {
            m_name = name;
        }
        Collection(const Collection&) = delete;
        Collection& operator=(const Collection&) = delete;
        Collection(Collection&&) noexcept = delete;
		Collection& operator=(Collection&&) noexcept = delete;
        ~Collection() {
            delete[] m_collection;
            m_collection = nullptr;
        };
        
        const std::string& name() const {
            return m_name;
        }
        size_t size() const {
            return m_sizeOfCol;
        }
        void setObserver(void (*observer)(const Collection<T>&, const T&)) {
            m_observer = observer;
        }
        //resize collection and add new item
	    Collection<T>& operator+=(const T& item) {
			bool flag = false;

			for (unsigned i = 0; i < m_sizeOfCol; i++)
				if (item.title() == m_collection[i].title()) { flag = true; }

			if (!flag) {
				T* tempArray = new T[++m_sizeOfCol];
				for (size_t i = 0; i < m_sizeOfCol - 1; i++) { tempArray[i] = m_collection[i]; }
                tempArray[m_sizeOfCol - 1] = item;
				
				delete[] m_collection;
                m_collection = tempArray;

				if (m_observer)
					m_observer(*this, item);
			    }
			return *this;
		}
        T& operator[](size_t idx) const {
            if(idx < 0 || idx >= m_sizeOfCol) {
                throw std::out_of_range("Bad index [" + std::to_string(idx) + "]. Collection has [" + std::to_string(m_sizeOfCol) + "] items.");
            }
            else {
                return m_collection[idx];
            }
        }
        T* operator[](const std::string& title) const {
            T* tmp{ nullptr };
            bool flag = false;
            size_t i;
            for(i = 0; i < m_sizeOfCol && !flag; i++) {
                if(title == m_collection[i].title()) {
                    flag = true;
                }
            }
            if(flag) {
                tmp = &m_collection[i - 1];
            }
            return tmp;
        }
      
    };
    //helper
    template<class T>
    std::ostream& operator<<(std::ostream& os, const Collection<T>& col) {
		for (size_t i = 0; i < col.size(); i++) { os << col[i]; }
		return os;
	}
}
#endif