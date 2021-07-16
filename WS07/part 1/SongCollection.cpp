/*
Danny Lei - 164700197
07/16/21
I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.
*/
#include <fstream>
#include <iostream>
#include <algorithm>
#include "SongCollection.h"
namespace sdds {
    SongCollection::SongCollection(const std::string fileName) {
        auto trim = [=](std::string str) {
            str.erase(0, str.find_first_not_of(" \t\f\n\v\r"));
            str.erase(str.find_last_not_of(" \t\f\n\v\r") + 1);
            return str;
        };
        std::fstream file(fileName);
        if(!file) {
            throw "File cannot to opened";
        }
        else {
            Song song;
            std::string tmp;
            while(getline(file, tmp)) {
                song.m_song = trim(tmp.substr(0,25));
                song.m_artist = trim(tmp.substr(25,25));
                song.m_album = trim(tmp.substr(50,25));
                try{
                    song.m_releaseYear = stoi(tmp.substr(75,5));
                }catch(...) {
                    song.m_releaseYear = 0;
                }
                song.m_length = stoi(tmp.substr(80,5));
                song.m_price = stod(tmp.substr(85,5));
                m_collection.push_back(song);
            }
        }
    }

   void SongCollection::display(std::ostream& out) const {
       std::for_each(m_collection.begin(), m_collection.end(), [&out](const Song &songs){
           out << songs << std::endl;
       });
   }

   std::ostream& operator<<(std::ostream& out, const Song& theSong) {
       out <<"helllo";
       return out;
   }
}
