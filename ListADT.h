#ifndef LISTADT_H
#define LISTADT_H

#include "DoublyLinkedList.h"
#include <iostream>
using namespace std;

template<class T>
class ListADT{
  public:
    virtual void insertFront(T d) = 0;
    virtual void insertBack(T d) = 0;
    virtual T removeFront() = 0;
    virtual T removeBack() = 0;
    virtual T removeNode(T value) = 0;
    virtual T find(T value) = 0;
    virtual T peek() = 0;
    virtual bool isEmpty() = 0;
    virtual unsigned int getSize() = 0;
};

#endif
