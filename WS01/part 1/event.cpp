/*
Danny Lei - 164700197
05/24/21
I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.
*/
#include "event.h"
#include <iostream>
#include <cstring>

using namespace std;
unsigned int g_sysClock;

namespace sdds {
    Event::Event() {
    }

    Event::Event(const Event& org) {
        *this = org;
    }

    Event& Event::operator=(const Event& org) {
        if (this != &org) {
            if (org.m_cstr != nullptr && org.m_cstr[0] != '\0') { //check if 'org' is valid - if not, set current obj to default state
                if (m_cstr != nullptr) { //if m_cstr if currently occupied, reset current object
                   reset();
                }
                m_cstr = new char[strlen(org.m_cstr) + 1];
                strcpy(m_cstr, org.m_cstr);
                m_time = org.m_time;
            }
            else {
                reset();
            }
        }
        return *this;
    }

    Event::~Event() {
        reset(); //call reset function to deallocate any memory dynamically allocated
    }

    void Event::reset() { //used to set/reset an obj to default state
        m_time = 0; //resets time of object to 0
        if (m_cstr != nullptr) { //frees any memory used for cstr
           delete[] m_cstr;
        }
        m_cstr = nullptr; //resets cstr of object to nullptr
        
    }

    void Event::display() {
        int hr, min, sec;
        static int count = 0; count++;
        
        hr = m_time / 3600; //convert seconds into hours, minutes, seconds - format
        min = (m_time / 60) % 60;
        sec = m_time % 60;

        if (m_cstr == nullptr) {
            cout.width(2);
            cout.fill(' ');
            cout << count;
            cout << ". | No Event |" << endl;
        }
        else {
            cout.width(2);
            cout.fill(' ');
            cout << count;
            cout << ". ";
            cout.width(2);
			cout.fill('0');
			cout << hr;
			cout << ":";
			cout.width(2);
			cout.fill('0');
			cout << min;
			cout << ":";
			cout.width(2);
			cout.fill('0');
			cout << sec;
			cout << " => " << m_cstr << endl;
        }
    }

    void Event::set(char* cstr) {
        if (cstr != nullptr && cstr[0] != '\0') { //check if cstr is valid - if not, reset obj
            if (m_cstr != nullptr) {
                reset(); //if m_cstr if currently occupied, reset current object to default state
            }
            m_cstr = new char[strlen(cstr) + 1];
            strcpy(m_cstr, cstr);
            m_time = g_sysClock;
        }
        else {
            reset();
        }
    }
}