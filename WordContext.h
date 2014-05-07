/*This is a class which holds the context of a word within a song. Both
 *Song and WordList use this class
 *created by: Nick Usoff
 *modified on: 4-30
 */

#ifndef __Included__WordContext__
#define __Included__WordContext__

#include <vector>

class WordContext{

public:
    WordContext(int id);
    void addLocation(int location);
    void addOccurence();
    int getNumOccurences();
    int getId();
    int getAtIndex(int index);

private:
    int songId;
    int numOccurences;
    std::vector<int> locations;

};

#endif
