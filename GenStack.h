/* Drew Bozarth
2373658
dbozarth@chapman.edu
CPSC 350-02
Assignment 4 - GenStack.h */
#ifndef GENSTACK_H
#define GENSTACK_H
#include <iostream>
#include <exception>

using namespace std;

template <class T>
class ListNode{
  public:
    ListNode();
    ListNode(T d);
    virtual ~ListNode();
    T data;
    ListNode *next;
};

template <class T>
ListNode<T>::ListNode(){

}

template <class T>
ListNode<T>::ListNode(T d){
  data = d;
  next = NULL;
}

template <class T>
ListNode<T>::~ListNode(){
  //what does here???
  //build some character
  next = NULL;
}



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

template <class T>
GenStack<T>::GenStack(){
  mSize = 0;
  front = NULL;
  back = NULL;
}

template <class T>
GenStack<T>::~GenStack(){
  //do something
}

template <class T>
void GenStack<T>::push(T data){
  ListNode<T> *node = new ListNode<T>(data);

  node->next = front;
  front = node;
  ++mSize;
}

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

template <class T>
T GenStack<T>::peek(){
  if (isEmpty()){
    throw runtime_error("stack is empty, can not peek!!!");
  }
  T temp = front->data;
  return temp;
}

template <class T>
bool GenStack<T>::isEmpty(){
  return (mSize == 0);
}

//returns the number of elements in the stack
template <class T>
unsigned int GenStack<T>::getSize(){
  return mSize;
}

#endif
