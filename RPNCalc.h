/* Drew Bozarth
2373658
dbozarth@chapman.edu
CPSC 350-02
Assignment 4 - RPNCalc.h */
#ifndef RPNCALC_H
#define RPNCALC_H

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

#endif
