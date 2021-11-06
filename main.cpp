/* Drew Bozarth
2373658
dbozarth@chapman.edu
CPSC 350-02
Assignment 4 - main.cpp */

/*
Main file for Assignment1. Uses main method then instantiates a
dynamic memory allocation of the class FileProcessor with a pointer,
and exectues the processFile method if there are enough command line
arguments given when the file is run. The command line arguments should
be the file names for the input file (English) and the output file (Tutnese).
These strings of the files names are passed as the parameters to the method
and the main method exits afterwards.
*/

//these statements include the user defined files into this file to be used
#include "GenStack.h"
#include "FileProcessor.h"
#include "DNAComplement.h"
#include "RPNCalc.h"
// standard namespace library in C++
using namespace std;
/*
Function: main
Return: int (returns a 0 or -1 based on if the main method runs correctly)
Parameters: int (argc, number of command line arguments), char** (argv, array of char pointers which is pretty much an array of the command line arguments)
Exceptions: none
*/
/*
The main method first checks for a command line argument either "RPN" or "DNA"
If neither of those were input, a runtime_error is returned. Otherwise, if it's "RPN",
the runCalculator() method is called, and if it is "DNA", the user is prompted for the file
path of the input file, then the files are processed with the user input file and a predetermined
output file
*/
int main(int argc, char** argv){
  FileProcessor *fp = new FileProcessor();
  RPNCalc *rpn = new RPNCalc();
  if(argc > 1){
    string programSelection = argv[1];
    if (programSelection == "RPN"){
      rpn->runCalculator();
    }
    else if (programSelection == "DNA"){
      string userFilePath;
      string outputFile = "dnaoutput.txt";
      cout << "Please enter the file path for the input file:" << endl;
      cin >> userFilePath;
      fp->processFile(userFilePath, outputFile);
      cout << "DNA file processed!" << endl;
    }
    else {
      throw runtime_error("Command line argument is not a valid program option");
      return -1;
    }
  }
  else {
    throw runtime_error("Invalid command line arguments!");
    return -1;
  }
  delete fp;
  delete rpn;

  return 0;
}
