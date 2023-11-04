// **************************************************************************
// File       [main.cpp]
// Author     [Deitel How to program C++, 5ed. Ch 20, Fig. 20.07]
// Synopsis   [The main program of this demo]
// Modify     [2010/02/21 CM Li]
// **************************************************************************

#include <iostream>
using std::cout;
using std::endl;
#include <fstream>
#include <sstream>
#include <string>
#include "mergeSort.h" // class MergeSort definition
#include "tm_usage.h" // the tm_usage library

int main(int argc, char* argv[])
{

	CommonNs::TmUsage tmusg;
    CommonNs::TmStat stat;
    tmusg.periodStart();

    if(argc != 3){
        cout<< "Error!! Command is wrong  " <<endl;
        exit(0);
    }
    std::ifstream file_in(argv[1]); // declare the input file 
    std::fstream file_out;
    file_out.open(argv[2],std::ios::out);
    if (!file_in) {
        cout<< "Error!! Cannot open the File : "<<argv[1]<<endl;
        exit(0);
    }

   // create object to perform merge sort
   MergeSort sortVector(file_in);

   #ifdef _DEBUG_ON_
   cout << "Unsorted vector:" << endl;
   sortVector.displayElements(); // print unsorted vector
   cout << endl << endl;
   #endif
 
   sortVector.sort(); // sort vector

   #ifdef _DEBUG_ON_
   cout << "\nSorted vector:" << endl;
   sortVector.displayElements(); // print unsorted vector
   #endif
   sortVector.displayResult(file_out); // output sorted vector
   cout << endl;

   file_in.close();
   file_out.close();
   tmusg.getPeriodUsage(stat);
   cout <<"user time:" << stat.uTime / 1000000.0 << "s" << endl; // print period user time in seconds
   cout <<"system time:" << stat.sTime / 1000000.0 << "s" << endl; // print period system time in seconds
   cout <<"user+system time:" << (stat.uTime + stat.sTime) / 1000000.0 << "s" << endl; 
   return 0;
} // end main

