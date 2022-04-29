#ifndef QUEUE_H
#define QUEUE_H

#include "DoublyLinkedList.h"
#include "ListADT.h"
#include <iostream>
using namespace std;

template<class T>
class Queue{
  public:
    Queue(); //default constructor
    Queue(T maxSize); //overloaded constructor
    ~Queue(); //destructor

    //core functions
    T dequeue(); //aka dequeue
    void enqueue(T d); //priority queue

    //aux functions (helper functions)
    T peek();
    bool isEmpty();
    unsigned int getSize();

    DoublyLinkedList<T> *l = new DoublyLinkedList<T>();

  private:
    ListNode<T> *front;
    ListNode<T> *back;
    unsigned int size;
};


template<class T>
Queue<T>::Queue(){} //default constructor

template<class T>
Queue<T>::Queue(T maxSize){} //overloaded constructor

template<class T>
Queue<T>::~Queue(){ //destructor
  //delete l;
}

template<class T>
void Queue<T>::enqueue(T d){
  return l->insertBack(d);
} //aka enqueue

template<class T>
T Queue<T>::dequeue(){
  return l->removeFront();
} //aka dequeue


//aux functions (helper functions)
template<class T>
T Queue<T>::peek(){
  return l->peek();
}


template<class T>
bool Queue<T>::isEmpty(){
  return l->isEmpty();
}

template<class T>
unsigned int Queue<T>::getSize(){
  return l->getSize();
}


#endif
