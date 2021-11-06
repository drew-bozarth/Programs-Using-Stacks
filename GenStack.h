/* Drew Bozarth
2373658
dbozarth@chapman.edu
CPSC 350-02
Assignment 4 - GenStack.h */

/*
This is a template class for a LinkedList based Stack
*/

//these are the header guards
#ifndef GENSTACK_H
#define GENSTACK_H
//these include some of the system defined libraries in C++
#include <iostream>
#include <exception>
//standard namespace libaray in C++
using namespace std;

/*
Template Class: ListNode
*/
template <class T>
class ListNode{
  public:
    ListNode();
    ListNode(T d);
    virtual ~ListNode();
    T data;
    ListNode *next;
};

/*
Function: ListNode()
Return: none
Parameters: none (default constructor)
Exceptions: none
*/
template <class T>
ListNode<T>::ListNode(){

}

/*
Function: ListNode(T d)
Return: none
Parameters: T d (Type is T for the template class)
Exceptions: none
*/
template <class T>
ListNode<T>::ListNode(T d){
  data = d;
  next = NULL;
}

/*
Function: ~ListNode()
Return: none
Parameters: none (destructor)
Exceptions: none
*/
template <class T>
ListNode<T>::~ListNode(){
  next = NULL;
}


/*
Template Class: GenStack
*/
template <class T>
class GenStack{
  public:
    GenStack(); //default constructor
    virtual ~GenStack(); //destructor

    //core function
    void push(T data);
    T pop();

    //aux/helper functions
    T peek(); //aka top()
    bool isEmpty();
    bool isFull();
    unsigned int getSize();

  private:
    unsigned int mSize;
    ListNode<T> *front;
    ListNode<T> *back;
};

/*
Function: GenStack()
Return: none
Parameters: none (default constructor)
Exceptions: none
*/
template <class T>
GenStack<T>::GenStack(){
  mSize = 0;
  front = NULL;
  back = NULL;
}

/*
Function: ~GenStack()
Return: none
Parameters: none (destructor)
Exceptions: none
*/
template <class T>
GenStack<T>::~GenStack(){
  ListNode<T>* currentNode = front;
  ListNode<T>* nextNode = NULL;

  while (currentNode != NULL){
    nextNode = currentNode->next;
    delete currentNode;
    currentNode = nextNode;
  }
}

/*
Function: push
Return: void
Parameters: T data (Type T for template class)
Exceptions: none
*/
//adds an item to the top of the stack
template <class T>
void GenStack<T>::push(T data){
  ListNode<T> *node = new ListNode<T>(data);

  node->next = front;
  front = node;
  ++mSize;
}

/*
Function: pop()
Return: T (Type T for template class)
Parameters: none
Exceptions: none
*/
//returns and removes the item at the top of the stack
template <class T>
T GenStack<T>::pop(){
  if (isEmpty()){
    throw runtime_error("stack is empty, can not remove!!!");
  }
  T temp = front->data;
  ListNode<T> *oldfront = front;
  front = front->next;
  oldfront->next = NULL;
  --mSize;
  delete oldfront;
  return temp;
}

/*
Function: peek()
Return: T (Type T for template class)
Parameters: none
Exceptions: none
*/
//returns the item at the top of the stack without removing it
template <class T>
T GenStack<T>::peek(){
  if (isEmpty()){
    throw runtime_error("stack is empty, can not peek!!!");
  }
  T temp = front->data;
  return temp;
}

/*
Function: isEmpty()
Return: bool
Parameters: none
Exceptions: none
*/
//returns bool value that checks if the stack is empty
template <class T>
bool GenStack<T>::isEmpty(){
  return (mSize == 0);
}

/*
Function: getSize()
Return: unsigned int (the size of the stack will always be positive int)
Parameters: none
Exceptions: none
*/
//returns the number of elemennts in the stack
template <class T>
unsigned int GenStack<T>::getSize(){
  return mSize;
}
//end of the header guards
#endif
