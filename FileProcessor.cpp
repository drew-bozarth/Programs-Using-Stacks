/* Drew Bozarth
2373658
dbozarth@chapman.edu
CPSC 350-02
Assignment 4 - FileProcessor.cpp */
#include "FileProcessor.h"

FileProcessor::FileProcessor(){

}

FileProcessor::~FileProcessor(){

}

void FileProcessor::processFile(string inputFilePath, string outputFile){
  string fileLine;
  ifstream input (inputFilePath);
  ofstream output (outputFile);

  if (input.is_open()){
    DNAComplement *dna = new DNAComplement();
    while ( getline(input,fileLine) ){
      if (output.is_open()){
        output << "DNA Sequence: " << fileLine << endl;
        output << "DNA Complement: " << dna->calculateComplement(fileLine) << endl;
        output << "DNA Reverse Complement: " << dna->calculateReverseComplement(fileLine) << endl;
        output << endl;
      }
      else {
        throw runtime_error("Could not open output file!");
      }
    }
    input.close();
    output.close();
    delete dna;
  }
  else {
    throw runtime_error("Could not open input file!");
  }
}
