#ifndef WINDOW_H
#define WINDOW_H

#include "Student.h"
#include <iostream>
using namespace std;

class Window{
  public:
    Window();
    ~Window();

    void SetIdleTime(int fileTimeWindow);
    int getIdleTime();

    void SetStudent(Student s);
    Student getStudent();


    void incrementIdleTime();

    void removeStudentFromWindow();
    bool checkOccupied();

    bool operator== (Window w);
    bool operator!= (Window w);

  private:
    Student student;
    int idleTime = 0;
    bool studentAtWindow;

};

#endif
