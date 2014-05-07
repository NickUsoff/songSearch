/*Test file for the Song search class. Sets up the hashtable of words, and
 *runs the search 
 *created by: Nick Usoff
 *modified on: 4-30
 */

#include <iostream>
#include "WordList.h"
#include "Song.h"
#include <sstream>
#include <vector>

using namespace std;

int main(int argc, char *argv[])
{
    WordList wordlist;
    if (argc == 2) {
	vector<Song> test;
	wordlist.read_lyrics(argv[1],false, &test);
	wordlist.find(&test);
    }
    else {
	cout << "Usage: songsearch database.txt\n";
    }
    return 0;
}
