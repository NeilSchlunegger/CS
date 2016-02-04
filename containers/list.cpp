/*
     Class definition file for list demo
     ListDemo
*/
#include "list.h"
using namespace std;

// Constructor
ListDemo::ListDemo() 
{
     // Local variables
     string buffer;                               // Input buffer

     // Prompt the user and create a list
     cout << endl << "Enter a list of words on a single line: ";
     getline(cin,buffer);                         // Read the user's input
     stringstream in(buffer,ios::in);             // Convert to stream
     myList = new list<string>;                   // Create empty list

     while(in.peek() != EOF)
     {
          in >> buffer;                           // Get a word
          myList->insert(myList->begin(),buffer); // Insert new word at head of list
     }
}

// Destructor
ListDemo::~ListDemo()
{
     delete myList;                               // Release the list

}

// Accessors
list<string>::iterator ListDemo::begin() { return myList->begin(); }
list<string>::iterator ListDemo::end() { return myList->end(); }

// Converter
string * ListDemo::array()
{
     string * result = new string[myList->size()];          // Allocate the array
     int idx = 0;                                           // Array index
     for(auto itr = myList->begin(); itr != myList->end(); itr++)
     {
          result[idx++] = *itr;                             // Copy the string
     }
     return result;
}

          
