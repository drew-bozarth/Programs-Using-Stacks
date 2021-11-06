/* Drew Bozarth
2373658
dbozarth@chapman.edu
CPSC 350-02
Assignment 4 - DNAComplement.cpp */

/*
This is the .cpp file for DNAComplement
*/

//this statement includes the DNAComplement.h file
#include "DNAComplement.h"

/*
Function: DNAComplement()
Return: none
Parameters: none (default constructor)
Exceptions: none
*/
DNAComplement::DNAComplement(){
}

/*
Function: ~DNAComplement()
Return: none
Parameters: none (destructor)
Exceptions: none
*/
DNAComplement::~DNAComplement(){
}

/*
Function: calculateComplement()
Return: string
Parameters: string dnaLine
Exceptions: none
*/
//takes in a DNA lines and returns the complement of that DNA string
string DNAComplement::calculateComplement(string dnaLine){
  string complement;
  for (int i = 0; i < dnaLine.length(); ++i){
    if (dnaLine[i] == 'A'){
      complement += 'T';
    }
    else if (dnaLine[i] == 'T'){
      complement += 'A';
    }
    else if (dnaLine[i] == 'G'){
      complement += 'C';
    }
    else if (dnaLine[i] == 'C'){
      complement += 'G';
    }
    else {
      complement = "INVALID DNA SEQUENCE";
      return complement;
    }
  }
  return complement;
}

/*
Function: calculateReverseComplement()
Return: string
Parameters: string dnaLine
Exceptions: none
*/
//takes in a complement of a DNA line, and returns the reversed line
string DNAComplement::calculateReverseComplement(string dnaLine){
  GenStack<char> *stack = new GenStack<char>();
  string reverseComplement;
  string complement = calculateComplement(dnaLine);
  for (int i = 0; i < complement.length(); ++i){
    stack->push(complement[i]);
  }
  while (!stack->isEmpty()){
    reverseComplement += stack->pop();
  }
  delete stack;
  return reverseComplement;
}
