// Name: Danny Lei
// Seneca Student ID: 164700197
// Seneca email: jylei1@senecacollege.ca
// Date of completion: 07/17/21
//
// I confirm that I am the only author of this file
//   and the content was created entirely by me.
#include <fstream>
#include <algorithm>
#include "Utilities.h"
#include "LineManager.h"
namespace sdds {
    LineManager::LineManager(const std::string &file, const std::vector<Workstation *> &stations) {
        std::ifstream openedFile(file);     //throw err msg if file cannot be opened
        if (!openedFile) {
            throw "File could not be opended";
        }

        size_t pos = 0;
        std::string line;
        std::string str;
        Workstation *currentStation;
        Workstation *nextStation;
        Workstation *firstStation;
        Utilities utils;

        while (std::getline(openedFile, line)) {
            bool more = true;
            
            str = utils.extractToken(line, pos, more);    
            currentStation = *std::find_if(stations.begin(), stations.end(), [&](Workstation *ws) { return (ws->getItemName() == str); });

            if (more) {     
                str = utils.extractToken(line, pos, more);
                nextStation = *std::find_if(stations.begin(), stations.end(), [&](Workstation *ws) { return (ws->getItemName() == str); });                   
                currentStation->setNextStation(nextStation);
            }
            activeLine.push_back(currentStation);
        }

        //find first link to list
        firstStation = *std::find_if(activeLine.begin(), activeLine.end(), [&](Workstation *ws1) {
            return std::all_of(activeLine.begin(), activeLine.end(), [&](Workstation *ws2) {
                bool flag = true;

                if (ws2->getNextStation() != nullptr && ws2->getNextStation()->getItemName() == ws1->getItemName()) {
                    flag = false;
                }
                return flag;
            });
        });

        m_firstStation = firstStation;
        m_cntCustomerOrder = pending.size();
    }

    //sort stations from first to last
    void LineManager::linkStations() {
        std::vector <Workstation*> station;
        Workstation* tmpStation = m_firstStation;

        do {
            station.push_back(tmpStation);
            tmpStation = tmpStation->getNextStation();
        }while(tmpStation != nullptr);
        activeLine = station;
    }

    bool LineManager::run(std::ostream& os) {
        static size_t run_count{ 0u };
        bool flag = false;

        os << "Line Manager Iteration: " << ++run_count << std::endl;

        if(!pending.empty()) {
            *m_firstStation += std::move(pending.front());
            pending.pop_front();
        }

        for_each(activeLine.begin(), activeLine.end(), [&os](Workstation* station){ station->fill(os); });
        for_each(activeLine.begin(), activeLine.end(), [](Workstation* station){ station->attemptToMoveOrder(); });

        if(completed.size() + incomplete.size() == m_cntCustomerOrder) { flag = true; }
        return flag;
    }

    void LineManager::display(std::ostream& os) const {
        for_each(activeLine.begin(), activeLine.end(), [&os](Workstation* station){
            station->display(os);
        });
    }
}