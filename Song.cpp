/*This is the interface for the Song class, which holds an artist, title, 
 *and a vector which holds the lyrics of the song
 *created by: Nick Usoff
 *modified on: 4-28
 */


#include "Song.h"
#include "WordContext.h"
#include <vector>
#include <unordered_map>

using namespace std;

//The only constructor for the Song class. Takes in two strings and and int,
//which are set to the title, artest, and id
Song::Song(string titleInp, string artistInp, int idInp){
    title = titleInp;
    artist = artistInp;
    id = idInp;
}

//getTitle is a getter for title
string Song::getTitle(){
    return title;
}

//getArtist is a getter for artist
string Song::getArtist(){
    return artist;
}

//insertWord adds a string at the back of the lyrics vector
void Song::insertWord(string word){
    lyrics.push_back(word);
}

//getLength is a getter for the size of the lyrics vector
int Song::getLength(){
    return ((int)lyrics.size());
}

//getWord gets a word at a particular index in the lyrics vector
string Song::getWord(int index){
    return lyrics[index];
}

//getContext() - find the surrounding words of a given work location
//and creates a string of the five previous and 5 next words, which
//is then returned

string Song::getContext(int pos){
    string context = "";
    int lastPos = ((int) lyrics.size()) - 1;
    int startPos = pos - 5;
    if(startPos < 0)
	startPos = 0;
    int endPos = pos + 5;
    if(endPos > lastPos)
	endPos = lastPos;
    for(int i = startPos; i <= endPos; i++)
	context += lyrics[i] + " ";
    return context;
}

//Passed in a temporary hashtable of wordContexts. If there is a collision, 
//the WordContext at that location is updated by adding a location and
//updating the number of occurences. If not, a WordContext is created
//and added at that location

void Song::insertWords(std::unordered_map<string, WordContext>* tempTable){
    int sizeLyrics = (int) lyrics.size();
    for(int i = 0; i < sizeLyrics; i++){
	string input = lyrics[i];
	std::unordered_map<string,WordContext>::const_iterator got = 
		tempTable->find (input);
  	if ( got == tempTable->end() ){
	    WordContext curr(id);	    
	    curr.addLocation(i);
	    tempTable->emplace(input, curr);
	}
  	else{
	    tempTable->at(input).addLocation(i);
	} 
    }
}


//destroys the temporary table, as it is no longer necessary once words
//have been inserted into the wordTable

void Song::destroyTempTable(){
    //~tempTable();
}
