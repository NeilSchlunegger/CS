/*
     Class definition file for set demo
     SetDemo
*/
#include "set.h"
using namespace std;

// Constructor
SetDemo::SetDemo() 
{
     // Local variables
     string buffer;                               // Input buffer

     // Prompt the user and create a set
     cout << endl << "Enter a set of words on a single line: ";
     getline(cin,buffer);                         // Read the user's input
     stringstream in(buffer,ios::in);             // Convert to stream
     mySet = new set<string>;                    // Create empty set

     while(in.peek() != EOF)
     {
          in >> buffer;                           // Get a word
          mySet->insert(mySet->begin(),buffer); // Insert new word at head of set
     }
}

// Destructor
SetDemo::~SetDemo()
{
     delete mySet;                               // Release the set

}

// Accessors
set<string>::iterator SetDemo::begin() { return mySet->begin(); }
set<string>::iterator SetDemo::end() { return mySet->end(); }

// Converter
string * SetDemo::array()
{
     string * result = new string[mySet->size()];          // Allocate the array
     int idx = 0;                                           // Array index
     for(auto itr = mySet->begin(); itr != mySet->end(); itr++)
     {
          result[idx++] = *itr;                             // Copy the string
     }
     return result;
}

          
