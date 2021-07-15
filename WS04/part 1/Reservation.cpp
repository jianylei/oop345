/*
Danny Lei - 164700197
6/14/21
I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.
*/
#include <iomanip>
#include "Reservation.h"

using namespace std;
namespace sdds {
    Reservation::Reservation(const string& res) {
        string str = res;
        size_t i = str.find(':');

        //lambda function to trim whitespaces
        auto trimWS = [=](string str) {
            str = str.substr(str.find_first_not_of(" \t\f\n\v\r"));
            str = str.substr(0, str.find_last_not_of(" \t\f\n\v\r")+1);
            return str;
        };
        m_resID = trimWS(str.substr(0, i++));
        str.erase(0,i);

        i = str.find(','); 
        m_name = trimWS(str.substr(0, i++));
        str.erase(0,i);

        i = str.find(','); 
        m_email = trimWS(str.substr(0, i++));
        str.erase(0,i);

        i = str.find(','); 
        m_partySize = atoi(str.substr(0, i++).c_str());
        str.erase(0,i);

        i = str.find(','); 
        m_day = atoi(str.substr(0, i++).c_str());
        str.erase(0,i);

        i = str.find(','); 
        m_hour = atoi(str.substr(0, i++).c_str());
    }
  

    ostream& operator<<(ostream& os, const Reservation& res)
    {
        os << "Reservation ";

		os << right << setw(10) << res.m_resID << ": ";

		os << setw(20) << res.m_name << "  ";

		os << left << setw(24) << "<" + res.m_email + ">";
		
        string temp;

        if (res.m_hour >= 6 && res.m_hour <= 9) { temp = "Breakfast"; }
        else if (res.m_hour >= 11 && res.m_hour <= 15) { temp = "Lunch"; }
        else if (res.m_hour >= 17 && res.m_hour <= 21) { temp = "Dinner"; }
        else { temp = "Drinks"; }

		os << left << temp + " on day ";

		os << res.m_day << " @ " << res.m_hour << ":00 for " << res.m_partySize;
		
		temp = (res.m_partySize == 1)? " person.": " people.";
        
        os << temp << endl;

		return os;
    }
    
}