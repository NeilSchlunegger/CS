/*
     Class definition file for map demo
     MapDemo
*/
#include "map.h"
using namespace std;

// Constructor
MapDemo::MapDemo() 
{
     // Local variables
     string buffer;                               // Input buffer

     // Prompt the user and create a map
     cout << endl << "Enter a map of words on a single line: ";
     getline(cin,buffer);                         // Read the user's input
     stringstream in(buffer,ios::in);             // Convert to stream
     myMap = new map<string,string>;                    // Create empty map

     while(in.peek() != EOF)
     {
          in >> buffer;                           // Get a word

          // In C++, map keys must be unique.  If a duplicate key is found, the insert will fail.
          // The return from the insert is a pointer to the value,  and you need to check it to see
          // if your insert worked or not
          auto result = myMap->insert( pair<string,string>(buffer.substr(0,1),buffer) ); // Insert new word at head of map
          if (result.second == false) {
               cerr << "?Duplicate map key \"" << buffer.substr(0,1) << "\".  Old data = \"" << result.first->second << "\", New data = \"" << buffer << "\"" << endl; 
          }
     }
}

// Destructor
MapDemo::~MapDemo()
{
     delete myMap;                               // Release the map

}

// Accessors
map<string,string>::iterator MapDemo::begin() { return myMap->begin(); }
map<string,string>::iterator MapDemo::end() { return myMap->end(); }

// Converter
string * MapDemo::array()
{
     string * result = new string[myMap->size()];          // Allocate the array
     int idx = 0;                                           // Array index
     for(auto itr = myMap->begin(); itr != myMap->end(); itr++)
     {
          result[idx++] = "[" + itr->first + "] = " + itr->second;                             // Copy the string
     }
     return result;
}

          
