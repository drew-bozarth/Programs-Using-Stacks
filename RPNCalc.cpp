/* Drew Bozarth
2373658
dbozarth@chapman.edu
CPSC 350-02
Assignment 4 - RPNCalc.cpp */
#include "RPNCalc.h"

RPNCalc::RPNCalc(){

}

RPNCalc::~RPNCalc(){

}

void RPNCalc::runCalculator(){
  cout << "Running RPN Calculator!" << endl;
  GenStack<string> *stack = new GenStack<string>();
  GenStack<string> *newStack = new GenStack<string>();
  bool calcRunning = true;
  string userInput;
  while (calcRunning){
    cout << "\n~~~RPN CALCULATOR~~~\n" << endl;
    cout << "Please use the calculator in Postfix Notation with integers!" << endl;
    cout << "Enter 'exit' to quit the calculator at any time" << endl;
    getline(cin, userInput);

    if (userInput == "exit"){
      calcRunning = false;
      return;
    }

    else{
      string currentString = "";
      for (int i = 0; i < userInput.length(); ++i){
        if (userInput[i] != ' '){
          currentString += userInput[i];
        }
        else {
          stack->push(currentString);
          currentString = "";
        }
      }
      stack->push(currentString);
      // we have a stack but it the reversed order of what we want
      while (!stack->isEmpty()){
        newStack->push(stack->pop());
      }
      // now we have a stack with the calculating input
      string currOperator;
      int leftVal = 0;
      int rightVal = 0;
      int tempLeft = 0;
      int tempRight = 0;
      leftVal = stoi(newStack->pop());
      while(!newStack->isEmpty()){
        if (!isOperator(newStack->peek())){
          rightVal = stoi(newStack->pop());
        }
        if (isOperator(newStack->peek())){
          currOperator = newStack->pop();
        }
        else {
          tempLeft = rightVal;
          tempRight = stoi(newStack->pop());
          if (isOperator(newStack->peek())){
            currOperator = newStack->pop();
          }
          rightVal = calculate(tempLeft,tempRight,currOperator);
          if (isOperator(newStack->peek())){
            currOperator = newStack->pop();
          }
        }
        leftVal = calculate(leftVal, rightVal, currOperator);
      }
      cout << "RESULT: " << leftVal << "\n\n";
    }
  }
  delete stack;
  delete newStack;
}

int RPNCalc::calculate(int left, int right, string symbol){
  if (symbol == "+"){
    return (left + right);
  }
  else if (symbol == "-"){
    return (left - right);
  }
  else if (symbol == "*"){
    return (left * right);
  }
  else if (symbol == "/"){
    return (left / right);
  }
  else if (symbol == "%"){
    return (left % right);
  }
  else {
    throw runtime_error("Operator not valid!");
  }
}

bool RPNCalc::isOperator(string symbol){
  return (symbol == "+" || symbol == "-" || symbol == "*" || symbol == "/" || symbol == "%");
}
