/* Drew Bozarth
2373658
dbozarth@chapman.edu
CPSC 350-02
Assignment 4 - DNAComplement.h */
#include "DNAComplement.h"

DNAComplement::DNAComplement(){

}

DNAComplement::~DNAComplement(){

}

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
