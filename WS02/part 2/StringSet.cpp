/*
Danny Lei - 164700197
05/31/21
I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.
*/
#include <fstream>
#include "StringSet.h"

namespace sdds {
    StringSet::StringSet() { }

    StringSet::StringSet(const char* fileName) {
        std::ifstream file(fileName);
        std::string str, tmp = " ";
        size_t i = 0;

        getNumString(file); //call function to count number of strings

        m_str = new std::string[numOfStrings + 1];

        file.clear(); //reset flags
        file.seekg(0); //return to start pos.
        //store contents of file in m_str member variable
        while (i < numOfStrings && getline(file, str, ' ')) {
			//if (str != tmp) {
                m_str[i] = str;
			    i++;
            //}
		}
    }

    StringSet::StringSet(const StringSet& orig) {
        *this = orig;
    }

    StringSet& StringSet::operator=(const StringSet& orig) {
        if (this != &orig) {
            if (orig.m_str != nullptr) {
                if (m_str != nullptr) { //if m_store is "occupied", reset obj to default
                    reset();
                }
                numOfStrings = orig.numOfStrings;
                m_str = new std::string[numOfStrings + 1];

                size_t i = 0;
                while (i < numOfStrings) { //safe copy of original m_str contents into *this->m_str
                    m_str[i] = orig.m_str[i];
			        i++;
		        }
            }
            else { //if orig centents are empty, reset *this to default values
                reset();    
            }
        }
        return *this;
    }

    StringSet::StringSet(StringSet&& orig)noexcept {
        *this = std::move(orig);
    }

    StringSet& StringSet::operator=(StringSet&& orig)noexcept {
        if (this != &orig) {
            if (orig.m_str != nullptr) {
                if (m_str != nullptr) {
                    reset();
                }
                m_str = orig.m_str; //'move' contents of orig to *this. Reset orig to default
                numOfStrings = orig.numOfStrings;
                orig.m_str = nullptr;
                orig.numOfStrings = 0;
            }
            else { 
                reset();    
            }
        }
        return *this;
    }

    StringSet::~StringSet() {
        delete[] m_str; 
        m_str = nullptr;
    }

    void StringSet::reset() {
        if (m_str != nullptr) { 
            delete[] m_str; 
            m_str = nullptr;
        }
        numOfStrings = 0;
    }

    void StringSet::getNumString(std::ifstream& file, char delim) {
        std::string str, tmp = " ";
        //while loop continues until eof (getline fails)
        while (getline(file, str, delim)) {
            //if (str != tmp) { numOfStrings++; } //increment numOfStrings as appropraite strings are found (not ' ')
        numOfStrings++;
        }
    }

    size_t StringSet::size() {
        return numOfStrings;
    }

    std::string StringSet::operator[] (size_t val) {
        return (val < numOfStrings) ? m_str[val] : "";
    }
}