/*The WordList class does three things - it reads in title, artist and lyrics
 *from a text file, adds data to collections of Songs and WordContexts, and
 *allows for a user to search for a word, giving the user the top 10 songs 
 *with the most frequent occurence of that song 
 *created by: Nick Usoff
 *modified on: 4-30
 */


#ifndef __Included__WordList__H__
#define __Included__WordList__H__


#include <unordered_map>
#include <vector>
#include <queue>
#include <iostream>
#include <sstream>
#include <string>
#include <fstream>
#include "Song.h"
#include "WordContext.h"

class WordList{

public:
	void read_lyrics(const char* filename, bool show_progress,
				   std::vector<Song> *songs);
	void addWords(std::unordered_map<std::string, WordContext> *songMap);
	void find(std::vector<Song> *songs);
private:

	std::unordered_map<std::string, std::vector<WordContext>> 
		wordTable;
	void bubbleDown(std::string word, WordContext currContext);
	void bubbleUp(std::string word, WordContext currContext);
	std::string alphaOnly(std::string s);
};
#endif
