/*
Danny Lei - 164700197
07/16/21
I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.
*/
#include <fstream>
#include <iomanip>
#include <algorithm>
#include <numeric>
#include <list>
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
                try{
                    song.m_length = stoi(tmp.substr(80,5));
                }catch(...) {
                    song.m_length = 0;
                }
                try{
                    song.m_price = stod(tmp.substr(85,5));
                }catch(...) {
                    song.m_price = 0;
                }               
                m_collection.push_back(song);
            }
        }
    }

   void SongCollection::display(std::ostream& out) const {

       std::for_each(m_collection.begin(), m_collection.end(), [&](const Song &songs){
           out << songs << std::endl;
       });

       size_t colllectionLength = std::accumulate(m_collection.begin(), m_collection.end(), 0u, [](const size_t &cnt, const Song &song) {
           return cnt + song.m_length;
       });
       out << std::setw(88) << std::setfill('-') << "\n" << std::setfill(' ');
       out << "| " << std::setw(77) << std::right << "Total Listening Time: " << colllectionLength / 3600 << ":" << (colllectionLength % 3600)/60 << ":" << colllectionLength %60 << " |" << std::endl;
   }

   std::ostream& operator<<(std::ostream& out, const Song& theSong) {
       out << "| " << std::setw(20) << std::left << theSong.m_song;
       out << " | " << std::setw(15) << theSong.m_artist;
       out << " | " << std::setw(20) << theSong.m_album;
       if(theSong.m_releaseYear) { out << " | " << std::setw(6) << std::right << theSong.m_releaseYear; }
       else { out << " | " << std::setw(6) << std::right << " "; }
       if(theSong.m_length) { out << " | " << std::right << (theSong.m_length % 3600)/60 << ':' << std::setw(2) << std::setfill('0') << theSong.m_length % 60 << std::setfill(' '); }
       else { out << " | " << " "; }
       if(theSong.m_price) { out << " | " << std::right << theSong.m_price << " |"; }
       else { out << " | " << " " << " |"; }

       return out;
   }

   void SongCollection::sort(const std::string str) {
       if(str == "title") {
           std::sort(m_collection.begin(), m_collection.end(), [](const Song &s1, const Song &s2) {
               return s1.m_song < s2.m_song;
           });
       }
       else if(str == "album") {
           std::sort(m_collection.begin(), m_collection.end(), [](const Song &s1, const Song &s2) {
               return s1.m_album < s2.m_album;
           });
       }
       else if(str == "length") {
           std::sort(m_collection.begin(), m_collection.end(), [](const Song &s1, const Song &s2) {
               return s1.m_length < s2.m_length;
           });
       }
   }

   void SongCollection::cleanAlbum() {
       std::for_each(m_collection.begin(), m_collection.end(), [](Song &song) {
           song.m_album = (song.m_album == "[None]")? "": song.m_album;
       });
   }

   bool SongCollection::inCollection(const std::string str) const {
       return std::any_of(m_collection.begin(), m_collection.end(), [&str](const Song &song) {
           return song.m_artist == str;
       });
   }

   std::list<Song> SongCollection::getSongsForArtist(const std::string str) const {
       int noOfSongs = std::count_if(m_collection.begin(), m_collection.end(), [&str](const Song &song) {
           return song.m_artist == str;
       });
       std::list<Song> listofSongs(noOfSongs);

       std::copy_if(m_collection.begin(), m_collection.end(), listofSongs.begin(), [&str](const Song &song) {
           return song.m_artist == str;
       });
       return listofSongs;
   }
}
