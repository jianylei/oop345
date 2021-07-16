/*
Danny Lei - 164700197
07/16/21
I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.
*/
#ifndef SDDS_SONGCOLLECTION_H_
#define SDDS_SONGCOLLECTION_H_
#include <string>
#include <vector>
namespace sdds {
    struct Song {
        std::string m_artist;
        std::string m_song;
        std::string m_album;
        double price{ 0 };
        size_t m_releaseYear{ 0u };
        size_t m_length{ 0u };
    };
   
   class SongCollection{
       std::vector<Song> m_collection;
   };
}
#endif