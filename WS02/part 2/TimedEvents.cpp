/*
Danny Lei - 164700197
05/31/21
I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.
*/
#include <iomanip>
#include <cstring>
#include "TimedEvents.h"

namespace sdds {
    TimedEvents::TimedEvents() { }

    TimedEvents::~TimedEvents() {
        for (int i = 0; i < m_numOfRecs; i++) {
            delete[] events[i].m_eventName;
            delete[] events[i].m_unitsOfTime;

            events[i].m_eventName = nullptr;
            events[i].m_unitsOfTime = nullptr;
        }
    }

    void TimedEvents::startClock() {
        m_start = std::chrono::steady_clock::now();
    }

    void TimedEvents::stopClock() {
        m_end = std::chrono::steady_clock::now();
    }

    void TimedEvents::addEvent(const char* name) {
        const char* unit = "nanoseconds";

        if (m_numOfRecs < MaxEvents) {
            if (name != nullptr) { //if 'name' is valid, set properties for current event obj
                events[m_numOfRecs].m_eventName = new char[strlen(name)+1];
                strcpy(events[m_numOfRecs].m_eventName, name);

                events[m_numOfRecs].m_unitsOfTime = new char[strlen(unit)+1];
                strcpy(events[m_numOfRecs].m_unitsOfTime, unit);
                
                events[m_numOfRecs].duration = std::chrono::duration_cast<std::chrono::nanoseconds>(m_end - m_start);

                m_numOfRecs++; //increment numOfRecs after setting values to set to next event obj
            }
        }
    }


    std::ostream& TimedEvents::display(std::ostream& ostr)const {
        ostr << "--------------------------" << std::endl;
        ostr << "Execution Times:" << std::endl;
        ostr << "--------------------------" << std::endl;

        for (int i = 0; i < m_numOfRecs; i++) { //loop through and print each event obj
            ostr << std::setw(21) << std::left << events[i].m_eventName;
            ostr << std::setw(13) << std::right << events[i].duration.count();
            ostr << ' ' << events[i].m_unitsOfTime << std::endl;
        }
        ostr << "--------------------------" << std::endl;
        return ostr;
    }

    std::ostream& operator<<(std::ostream& ostr, const TimedEvents& events) {
        return events.display(ostr);
    }
}