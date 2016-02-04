/*
     Declaration file for set demonstration
     SetDemo
*/
#pragma once

#include <iostream>
#include <iomanip>
#include <set>
#include <string>
#include <sstream>

class SetDemo
{
     public:
          SetDemo();                                   // Public constructor
          ~SetDemo();                                  // Public destructor
          std::set<std::string>::iterator begin();    // Return iterator to start of set
          std::set<std::string>::iterator end();      // Return iterator to end of set 
          std::string * array();                       // Return pointer to array of set items

     private:
          std::set<std::string> * mySet;             // We'll use string sets for the demonstration

};

