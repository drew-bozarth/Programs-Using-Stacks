/* Drew Bozarth
2373658
dbozarth@chapman.edu
CPSC 350-02
Assignment 4 - DNAComplement.h */

/*
This is the .h file for DNAComplement
*/

//these are the header guards
#ifndef DNACOMPLEMENT_H
#define DNACOMPLEMENT_H
//these include some of the system defined libraries in C++
#include <iostream>
#include <exception>
#include "GenStack.h"

using namespace std;

class DNAComplement{

  public:
    DNAComplement(); //default constructor
    ~DNAComplement(); //destructor

    string calculateComplement(string dnaLine);
    string calculateReverseComplement(string dnaLine);
};
//end of the header guards
#endif
