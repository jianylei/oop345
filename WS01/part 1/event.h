/*
Danny Lei - 164700197
05/24/21
I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.
*/
#pragma once

extern unsigned int g_sysClock;

namespace sdds {
    class Event {
        char* m_cstr{ nullptr };
        unsigned int m_time{ 0 };
    public:
        Event();
        Event(const Event&);
        ~Event();
        Event& operator=(const Event&);
        void display();
        void set(char* cstr = nullptr);
        void reset(); //resets state of object to default state - frees any used memory
    };
    
}