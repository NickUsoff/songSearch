/*Definition of the WordContext class
 *created by: Nick Usoff
 *modified on 
 */
#include "WordContext.h"
#include <vector>

//WordContext() is the only constructor for the WordContext class. It takes
//in an integer and sets the songId to that integer
WordContext::WordContext(int id){
    songId = id;
    numOccurences = 0;
}

//addLocation calls push_back on the locations vector to add a passed in int.
//It also increments numOccurences
void WordContext::addLocation(int location){
    locations.push_back(location);
    numOccurences++;
}

//addOccurence increments numOccurences
void WordContext::addOccurence(){
    numOccurences++;
}

//getNumOccurences is a getter for numOccurences
int WordContext::getNumOccurences(){
    return numOccurences;
}

//getId is a getter for songId
int WordContext::getId(){
    return songId;
}

//getAtIndex returns the location at a passed in index
int WordContext::getAtIndex(int index){
    return locations[index];
}


