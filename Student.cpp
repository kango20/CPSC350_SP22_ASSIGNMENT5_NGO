#include "Student.h"

//default constructor
Student::Student(){
  waitTime = 0;
  requiredTime = 0;
}

//overloaded constructor
Student::Student(int r){
  requiredTime = r;
}


//destructor
Student::~Student(){
}


//mutator for the student's required service time
void Student::SetRequiredTime(int fileRequiredTime){
  requiredTime = fileRequiredTime;
}

//mutator for the student's wait time
void Student::SetWaitTime(int studentWaitTime){
  waitTime = studentWaitTime;
}

//accessor for the students required service time
int Student::getRequiredTime(){
  return requiredTime;
}

//accessor for the students wait time
int Student::getWaitTime(){
  return waitTime;
}

//increments the students wait time
void Student::incrementWaitTime(){
  waitTime++;
}

//decrements the students required service time
void Student::decrementRequiredTime(){
  requiredTime--;

}

//defines ==
bool Student::operator == (Student s) {
  if (waitTime == s.getWaitTime() && requiredTime == s.getRequiredTime()){
    return true;
  }
  return false;
}

//defines !=
bool Student::operator != (Student s) {
  if (waitTime != s.getWaitTime() || requiredTime != s.getRequiredTime()){
    return true;
  }
  return false;
}
