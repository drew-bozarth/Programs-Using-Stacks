/* Drew Bozarth
2373658
dbozarth@chapman.edu
CPSC 350-02
Assignment 4 - FileProcessor.h */
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
