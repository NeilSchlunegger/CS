/*
     Declaration file for list demonstration
     ListDemo
*/
#pragma once

#include <iostream>
#include <iomanip>
#include <list>
#include <string>
#include <sstream>

class ListDemo
{
     public:
          ListDemo();                                  // Public constructor
          ~ListDemo();                                 // Public destructor
          std::list<std::string>::iterator begin();    // Return iterator to start of list
          std::list<std::string>::iterator end();      // Return iterator to end of list 
          std::string * array();                       // Return pointer to array of list items

     private:
          std::list<std::string> * myList;             // We'll use string lists for the demonstration

};

