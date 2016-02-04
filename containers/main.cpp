/*
     Container

     Demonstrate C++ STL Containers
*/
#include "main.h"


using namespace std;


int main(int argc, char **argv) {

     // Local variables for time control
     time_t now = chrono::system_clock::to_time_t(chrono::system_clock::now());      // Execution time
     tm *local = localtime(&now);                                                    // Convert to time structure
     ostringstream stamp;                                                            // For formatting only
     stamp << (local->tm_year) + 1900                                                // Current year (offset from 1900) 
           << " " << setw(2) << setfill('0') << local->tm_mon + 1                    // Current month (offset from 0) 
           << " " << setw(2) << setfill(' ') << local->tm_mday                       // Current day of month 
           << " " << setw(2) << setfill(' ') << local->tm_hour                       // Current hour
           << ":" << setw(2) << setfill(' ') << local->tm_min                        // Current minute
           << ":" << setw(2) << setfill(' ') << local->tm_sec                        // Local second
          ;

     // Display compile and execution time information
     cout << "[" << __FILE__ << " compiled " << __DATE__ << " " << __TIME__ << ", GCC " << __VERSION__ << "]" << endl;
     cout << "[Execution at " << stamp.str() << "]" << endl;

     // List Demonstration
     ListDemo * myList = new ListDemo();                                             // Create a list
     for(auto itr = myList->begin(); itr != myList->end(); itr++)
     {
          cout << *itr << " ";
     }
     cout << endl;
     delete myList;                                                                  // Kill the list

     // Set Demonstration
     SetDemo * mySet = new SetDemo();                                                // Create a set
     for (auto itr = mySet->begin(); itr != mySet->end(); itr++)
     {
          cout << *itr << " ";
     }
     cout << endl;
     delete mySet;

     // Map demonstration
     MapDemo * myMap = new MapDemo();                                                // Create a map
     for (auto itr = myMap->begin(); itr != myMap->end(); itr++)
     {
          cout << "[" << itr->first << "] = " << itr->second << endl;
     }


  return 0;
}
