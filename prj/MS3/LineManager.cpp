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
    LineManager::LineManager(const std::string& file, const std::vector<Workstation*>& stations) {
        std::fstream openedFile(file);
        if(!openedFile) { throw "File could not be opended"; }
        else {
            std::string line;
            std::string str;
            size_t pos{ 0u };
            bool more = true;
            Workstation * currentStation{ nullptr };
            Workstation * nextStation{ nullptr };
            Utilities utils;
            
            while(getline(openedFile, line)) {
                str = utils.extractToken(line, pos, more);
                currentStation = *std::find_if(stations.begin(), stations.end(), [](Workstation* stations){
                    return stations->getItemName() == str;
                });
                if(more) {
                    str = utils.extractToken(line, pos, more);
                    nextStation = *std::find_if(stations.begin(), stations.end(), [](Workstation* stations){
                        return stations->getItemName() == str;
                    }); 
                    currentStation->setNextStation(nextStation);
                }
                activeLine.push_back(currentStation);
            }
        }
    }
   
}