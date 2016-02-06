/*
     Declaration file for map demonstration
     MapDemo
*/
#pragma once

#include <iostream>
#include <iomanip>
#include <map>
#include <string>
#include <sstream>

class MapDemo
{
     public:
          MapDemo();                                   // Public constructor
          ~MapDemo();                                  // Public destructor
          std::map<std::string,std::string>::iterator begin();    // Return iterator to start of map
          std::map<std::string,std::string>::iterator end();      // Return iterator to end of map 
          std::string * array();                       // Return pointer to array of map items

     private:
          std::map<std::string,std::string> * myMap;             // We'll use string maps for the demonstration

};

