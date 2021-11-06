/* Drew Bozarth
2373658
dbozarth@chapman.edu
CPSC 350-02
Assignment 4 - FileProcessor.cpp */

/*
This is the .cpp file for FileProcessor
*/

//this statement includes the FileProcessor.h file
#include "FileProcessor.h"

/*
Function: FileProcessor()
Return: none
Parameters: none (default constructor)
Exceptions: none
*/
FileProcessor::FileProcessor(){

}

/*
Function: FileProcessor()
Return: none
Parameters: none (destructor)
Exceptions: none
*/
FileProcessor::~FileProcessor(){

}

/*
Function: processFile()
Return: void
Parameters: string inputFilePath, string outputFile
Exceptions: none
*/
/*
this method opens the input and output files, then creates an instance of the DNAComplement class.
For each line that is read in the file, it calculates the complement, and reverse Complement, then
prints out the original DNA line with the two new lines to the output file
*/
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
