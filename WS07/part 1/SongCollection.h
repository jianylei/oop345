/*
Danny Lei - 164700197
07/16/21
I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.
*/
#ifndef SDDS_SONGCOLLECTION_H_
#define SDDS_SONGCOLLECTION_H_
#include <string>
#include <list>
#include <vector>
namespace sdds {
    struct Song {
        std::string m_artist;
        std::string m_song;
        std::string m_album;
        double m_price{ 0 };
        size_t m_releaseYear{ 0u };
        size_t m_length{ 0u };
    };
   
   class SongCollection{
       std::vector<Song> m_collection;
    public:
        SongCollection(const std::string);
        void display(std::ostream& out) const;
        void sort(const std::string);
        void cleanAlbum();
        bool inCollection() const;
        std::list<Song> getSongsForArtist() const;
   };

   std::ostream& operator<<(std::ostream& out, const Song& theSong);
}
#endif