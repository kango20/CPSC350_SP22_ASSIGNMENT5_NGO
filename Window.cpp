#include "Window.h"

//default constructor
Window::Window(){
  idleTime = 0;
  student = Student(0);
  studentAtWindow = false;
}

//destructor
Window::~Window(){}

//mutator of the window's idle time
void Window::SetIdleTime(int fileTimeWindow){
  idleTime = fileTimeWindow;
}

//accesssor of the window's idle time
int Window::getIdleTime(){
  return idleTime;
}

//sets a student object in the window
void Window::SetStudent(Student s){
  student = s;
  studentAtWindow = true;
}

//gets the student
Student Window::getStudent(){
  return student;
}

//increases the idle time when the window is unoccupied
void Window::incrementIdleTime(){
  idleTime++;
}

//removes the student from the window
void Window::removeStudentFromWindow(){
  studentAtWindow = false;
}

//checks if the window is occupied
bool Window::checkOccupied(){
  return studentAtWindow;
}

//defines ==
bool Window::operator== (Window w){
  if(idleTime == w.getIdleTime() && student == w.getStudent()){
    return true;
  }
  return false;
}

//defines !=
bool Window::operator!= (Window w){
  if(idleTime != w.getIdleTime() || student != w.getStudent()){
    return true;
  }
  return false;
}
