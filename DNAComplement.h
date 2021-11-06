/* Drew Bozarth
2373658
dbozarth@chapman.edu
CPSC 350-02
Assignment 4 - DNAComplement.h */
#ifndef DNACOMPLEMENT_H
#define DNACOMPLEMENT_H

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

#endif
