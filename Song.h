/*Song.h is the interface for the Song class, which stores a title, an artist,
 *an id which represents the location of the song, and all of the words in 
 *the song as strings in a vector
 *created by: Nick Usoff
 *modified on: 4-28
 */

#ifndef __Included__Song__
#define __Included__Song__

#include <iostream>
#include <sstream>
#include <string>
#include <fstream>
#include <vector>
#include <unordered_map>
#include "WordContext.h"

class Song{

public:
    Song(std::string title, std::string artist, int id);
    std::string getTitle();
    std::string getArtist();
    void insertWord(std::string word);
    std::string getWord(int index);
    std::string getContext(int pos);
    void insertWords(std::unordered_map<std::string, WordContext>* tempTable);
    void destroyTempTable();
    int getLength();

private:
    std::string title;
    std::string artist;
    std::vector<std::string> lyrics;
    int id;
};
#endif
