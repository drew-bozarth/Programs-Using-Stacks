/* Drew Bozarth
2373658
dbozarth@chapman.edu
CPSC 350-02
Assignment 4 - main.cpp */
#include "GenStack.h"
#include "FileProcessor.h"
#include "DNAComplement.h"
#include "RPNCalc.h"

using namespace std;

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
