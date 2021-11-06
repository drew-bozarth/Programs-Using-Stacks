/* Drew Bozarth
2373658
dbozarth@chapman.edu
CPSC 350-02
Assignment 4 - FileProcessor.h */

/*
This is the .h file for FileProcessor
*/

//these are the header guards
#ifndef FILEPROCESSOR_H
#define FILEPROCESSOR_H
//these include some of the system defined libraries in C++
#include <iostream>
#include <fstream>
#include <exception>
#include "DNAComplement.h"

using namespace std;

class FileProcessor{

  public:
    FileProcessor();
    ~FileProcessor();
    void processFile(string inputFilePath, string outputFile);
};
//end of the header guards
#endif
