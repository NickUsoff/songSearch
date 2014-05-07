// read_lyics
//   purp: read in song data from a dk file
//   args: the name of the file, bool to ask for progress status
//   rets: nothing
//   does: calls a function each time a word is found
//
#include "WordList.h"
#include <vector>
#include <queue>
#include <unordered_map>

using namespace std;

//read_lyrics reads in song data from a file, and constructs Song objects,
//as well as calling a method to create WordContext objects
//NOTE: most of this method was written by Chris Gregg

void WordList::read_lyrics(const char* filename, bool show_progress, 
			   vector<Song> *songs)
{
        ifstream in(filename);			// creates an input stream
        int song_count = 0;			// for progress indicator
	string artist, title, word;
        
	// -- While more data to read...
	while ( ! in.eof() )
	{
		// -- First line is the artist
		getline(in, artist);
		if (in.fail()) break;
		// -- Second line is the title
		getline(in, title);
		if (in.fail()) break;
		//create a Song with the current title, artist, and song number
		Song currSong = Song(title, artist, song_count);
                
		if ( show_progress )
		{
			song_count++;
			if (song_count % 1000 == 0) {
				cout << "At "       << song_count <<
                                " Artist: " << artist     <<
                                " Title:"   << title << endl;
			}
		}
		// -- Then read all words until we hit the
		// -- special <BREAK> token
		int songLoc = 0;
		while ( in >> word && word != "<BREAK>" ){
		    
		    currSong.insertWord(word);
		    songLoc++;
		}
		//create a map of WordContext's, add the map to the wordTable 
		std::unordered_map<string, WordContext> songMap;
		currSong.insertWords(&songMap);
		addWords(&songMap);
		
		songs->push_back(currSong); //add to the vector of Songs
		// -- Important: skip the newline left behind
		in.ignore();
	}
}



//addWords() is passed an unordered map of lyrics within one song, and goes 
//through each WordContext in the unordered map of WordContext objects within 
//the song, adding them to wordTable

void WordList::addWords(std::unordered_map<string, WordContext> * songMap){
    for (auto& x: *songMap) {
	//insert the word context at the right location. Does not occur if 
	//the priority of the word context is high enough
	int maxPos = (int) wordTable[x.first].size() - 1;
	string word = alphaOnly(x.first); //only use the alphanumeric chars
	WordContext currContext = x.second;
	if (maxPos > 9) 
	    bubbleDown(word, currContext);
	else 
	    bubbleUp(word, currContext);
    }
}

//bubbleDown() is a helper method to addWords which inserts a word at slot 10
//in the vector of wordContexts, and keeps swapping with the WordContext before
//it until it is in the right place. 

void WordList::bubbleDown(string word, WordContext currContext){
    wordTable[word][10] = currContext;
    int posBefore = 9;
    int currOcc = currContext.getNumOccurences();
    while(posBefore >= 0){
	if(currOcc > wordTable[word][posBefore].getNumOccurences()){
	    //swap!
	    wordTable[word][posBefore + 1] = wordTable[word][posBefore];
	    wordTable[word][posBefore] = currContext;
	    posBefore--;
	}
	else
	    break;
    }
}



//bubble up is a helper method to addWords which find the right place in the
//vector to insert the WordContext, and emplants it there. This method is 
//only called when the vector size is less than 10 to ensure that the vector
//never grows beyond size 11.

void WordList::bubbleUp(string word, WordContext currContext){
    int size = (int) wordTable[word].size();
    int numOcc = currContext.getNumOccurences();
    int insertPos = 0;
    while(insertPos < size){
	if(wordTable[word][insertPos].getNumOccurences() > numOcc)
	    insertPos++; //move to next slot if bigger than current slot
	else
	    break;
    }
    wordTable[word].emplace(wordTable[word].begin() + insertPos, currContext);
}

//find() finds a word and prints out the occurences of that word in the ten 
//songs which contatin the word most. Takes in user input to find words until
//<BREAK> is inserted 

void WordList::find(vector<Song> *songs){
    string word = "";
    while(word != "<BREAK>"){
    	cin >> word;
    	int numOcc = (int) wordTable[word].size();
    	if(numOcc > 10) //limit the number of results to 10
	    numOcc = 10;
    	for(unsigned i = 0; i < numOcc; i++){
	    WordContext currContext = wordTable[word][i];
	    int songIndex = currContext.getId();
	    int instances = wordTable[word][i].getNumOccurences(); 
		//loop through each occurence of the word in the given song
	    for(int j = 0; j < instances; j++){
	    	cout << "Title: " << songs -> at(songIndex).getTitle() << endl;
	    	cout << "Artist: " << songs -> at(songIndex).getArtist() << 
					endl;
	    
	    	int wordInd = currContext.getAtIndex(j);
	    	string context = songs -> at(songIndex).getContext(wordInd);
	    	cout << "Context: " << context << endl;
	    	cout << endl; 
       	    }
    	}
    }
    cout << "<END-OF-REPORT>" << endl;
}

// alphaOnly() strips off non-alphabetic and non-digit characters
// and returns a string with just the alphas and digits.
//NOTE: this method was written by Chris Gregg
string WordList::alphaOnly(string s){
    ostringstream ss;
    for (size_t i=0;i<s.length();i++) {
	if (isalnum(s[i])){
	    ss << (char)(tolower(s[i]));
	}
    }
    return ss.str();
}
