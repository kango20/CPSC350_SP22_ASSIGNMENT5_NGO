#ifndef STUDENT_H
#define STUDENT_H

#include <iostream>
using namespace std;

class Student{
  public:
    Student();
    Student(int r);
    ~Student();

    void SetRequiredTime(int fileRequiredTime); //how much time a student needs at the window
    void SetWaitTime(int studentWaitTime); // keeps track of how long a student waits in the queue

    int getRequiredTime();
    int getWaitTime();

    void incrementWaitTime();
    void incrementServiceTime();
    void decrementRequiredTime();

    bool operator== (Student s);
    bool operator!= (Student s);

  private:
    int waitTime = 0;
    int requiredTime;

};

#endif
