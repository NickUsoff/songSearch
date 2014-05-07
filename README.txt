README for Song Seach

COMPILE INSTRUCTIONS

Use the included Makefile with the command 'make'

FILES

WordList.h and WordList.cpp ---- The interface and implementation of the
	WordList class. This class contains methods to read in song lyrics
	and creates Song objects as well as populates the WordTable with
	WordContext objects. It also contains a method to search for a word

WordContext.h and WordContext.cpp ---- The interface and implementation of the
	WordContext class. This class contains data about where a particular
	word is; the songs it's in and the locations within that song that
	it exists.

Song.h and Song.cpp ---- The interface and implementation of the song class.
	This class represents a song by holding an artist, a title, and a 
	vector of all of the words in the lyrics

mainTest.cpp ---- The test file for the application. It creates a WordList, 
	creates a vector of songs, and then reads in the words and runs find()

Algorithms and Data structures

A vector  which stores Songs
A hashtable which holds words
        Key: strings (words in the songs)
        Value: vector of WordContext objects

Finding a word - first, use the hashing function to find the location of the
word. Then, loop through the vector of WordContext objects, which are stored 
in  order of frequency. An inner loop goes through each occurrence of the word
within the song, printing out the title and artist of the song, then using the
location value within WordContext in order to find and print out the context.

Inserting words - Done through the Song class. Word?s (WordContext and string 
of the word) are stored in a temporary hashtable by going through each word in
the song, and either inserting a new Word or updating the data on an already 
present Word. Then, each Word is accessed and added to the main hashtable.
