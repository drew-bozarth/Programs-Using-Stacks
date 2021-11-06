/* Drew Bozarth
2373658
dbozarth@chapman.edu
CPSC 350-02
Assignment 4 - RPNCalc.cpp */

/*
This is the .cpp file for RPNCalc
*/

//this statement includes the RPNCalc.h file
#include "RPNCalc.h"

/*
Function: RPNCalc()
Return: none
Parameters: none (default constructor)
Exceptions: none
*/
RPNCalc::RPNCalc(){

}

/*
Function: ~RPNCalc()
Return: none
Parameters: none (destructor)
Exceptions: none
*/
RPNCalc::~RPNCalc(){

}

/*
Function: runCalculator()
Return: void
Parameters: none
Exceptions: none
*/
/*runs the simulation of the RPN calculator that prompts the user
for input in the console to use the calculator. It takes the user input
and pushes the operators and operands onto a stack and uses the calculate
method to print the result of the calculation the user entered.
*/
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
      //this is creating a string with each character of the input string, then once a space is reached,
      //the tempString is pushed onto the stack of strings
      for (int i = 0; i < userInput.length(); ++i){
        if (userInput[i] != ' '){
          currentString += userInput[i];
        }
        else {
          stack->push(currentString);
          currentString = "";
        }
      }
      //there is one final string that needs to be pushed onto the stack after the for loop
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
      //it first stores the first string as the left operand
      leftVal = stoi(newStack->pop());
      // a while loop runs while there are strings left on the stack
      while(!newStack->isEmpty()){
        //if the string is not an operator, it must be the right operand
        if (!isOperator(newStack->peek())){
          rightVal = stoi(newStack->pop());
        }
        //if it is an operator, it is stored as such
        if (isOperator(newStack->peek())){
          currOperator = newStack->pop();
        }
        //this else statement will execute when there are multiple operands in a row,
        // and a different series of calculations is required
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
        //once we have our left and right operands, and our operator, we calculate
        leftVal = calculate(leftVal, rightVal, currOperator);
      }
      //the result is printed once the stack is empty and the entire operation was performed
      cout << "RESULT: " << leftVal << "\n\n";
    }
  }
  delete stack;
  delete newStack;
}

/*
Function: calculate()
Return: int
Parameters: int left (left operand), int right (right operand), string symbol (operator)
Exceptions: none
*/
//this function checks what the operator is, and performs the correct operation and returns the result
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

/*
Function: isOperator()
Return: bool
Parameters: string symbol
Exceptions: none
*/
//this function takes in a string and returns a bool check to see if it is an operator or not
bool RPNCalc::isOperator(string symbol){
  return (symbol == "+" || symbol == "-" || symbol == "*" || symbol == "/" || symbol == "%");
}
