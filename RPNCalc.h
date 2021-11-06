/* Drew Bozarth
2373658
dbozarth@chapman.edu
CPSC 350-02
Assignment 4 - RPNCalc.h */

/*
This is the .h file for RPNCalc
*/

//these are the header guards
#ifndef RPNCALC_H
#define RPNCALC_H
//these include some of the system defined libraries in C++
#include <iostream>
#include <exception>
#include "GenStack.h"

using namespace std;

class RPNCalc{

  public:
    RPNCalc(); //default constructor
    ~RPNCalc(); //destructor

    void runCalculator();
    int calculate(int left, int right, string symbol);
    bool isOperator(string symbol);

};
//end of the header guards
#endif
