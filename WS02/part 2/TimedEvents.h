/*
Danny Lei - 164700197
05/31/21
I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.
*/
#ifndef SDDS_TIMEDEVENTS_H_
#define SDDS_TIMEDEVENTS_H_
#include <ostream>
#include <chrono>

namespace sdds {
    const int MaxEvents = 10;

    class TimedEvents {
        int m_numOfRecs{ 0 };
        std::chrono::steady_clock::time_point m_start;
        std::chrono::steady_clock::time_point m_end;
        struct Events {
            char* m_eventName{ nullptr };
            char* m_unitsOfTime{ nullptr };
            std::chrono::steady_clock::duration duration;
        } events[MaxEvents];
    public:
        TimedEvents();
        ~TimedEvents();
        void startClock();
        void stopClock();
        void addEvent(const char*);
        std::ostream& display(std::ostream&)const;
        friend std::ostream& operator<<(std::ostream&, const TimedEvents&);
    };

}
#endif