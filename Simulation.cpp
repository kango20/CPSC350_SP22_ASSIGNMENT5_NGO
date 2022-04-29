#include "Simulation.h"

//default constructor
Simulation::Simulation(){}

//destructor
Simulation::~Simulation(){}

//function to checks if there is a window that is empty
bool Simulation::windowsEmpty(){

  for(int i = 0; i < windows.size(); ++i){

    //checks if there is a student at the window
    if(windows.at(i).checkOccupied()){
      return false;
    }
  }
  return true;
}

//function to calculate the student's mean wait time
double Simulation::meanWaitTime(){

  //if there are no students, returns 0
  if(studentWaitTimes.size() == 0){
    return 0;
  }

  int totalTime = 0;

  //calculates the total wait time of all the students
  for(int i = 0; i < studentWaitTimes.size(); ++i){
    totalTime += studentWaitTimes[i].getWaitTime();
  }

  //returns the average wait time
  return totalTime / (double)studentWaitTimes.size();
}

//function to calculate the median wait time
double Simulation::medWaitTime(){

  //if there are no students, return 0
  if(studentWaitTimes.size() == 0){
    return 0;
  }

  //creates a vector of integers to put the wait times  in
  vector<int> sortWaitTime;
  for(int i = 0; i < studentWaitTimes.size(); ++i){
    sortWaitTime.push_back(studentWaitTimes[i].getWaitTime());
  }

  //sorts the wait times from shortest time to longest time
  sort(sortWaitTime.begin(), sortWaitTime.end());

  //checks if the number of wait times is even
  if(sortWaitTime.size() % 2 == 0){

    //returns the median of the even number of wait times
    return ((sortWaitTime[sortWaitTime.size()/2-1] + sortWaitTime[sortWaitTime.size()/2]) / (double)2);
  }
  else{

    //returns the median of the odd number of wait times
    return (double)(sortWaitTime[sortWaitTime.size()/2]);
  }
}

//function to find the longest wait time
int Simulation::longestWaitTime(){

  //creates a vector of integers to put the wait times
  vector<int> sortWaitTime;
  for(int i = 0; i < studentWaitTimes.size(); ++i){
    sortWaitTime.push_back(studentWaitTimes[i].getWaitTime());
  }

  //returns the longest wait time
  return *max_element(sortWaitTime.begin(), sortWaitTime.end());
}

//function to find the amount of wait time of students that are over 10 minutes
int Simulation::numStudentsOver10(){
  int count = 0;

  //loops through all of the wait times and increases the count if the wait time is over 10 minutes
  for(int i = 0; i < studentWaitTimes.size(); ++i){
    if(studentWaitTimes[i].getWaitTime() > 10){
      count++;
    }
  }
  return count;
}

//function to find the mean window idle time
double Simulation::meanWindowIdleTime(){

  //if the vector of windows is empty, return 0 as the mean
  if(windows.size() == 0){
    return 0;
  }

  //calculates the total idle time
  int totalTime = 0;
  for(int i = 0; i < windows.size(); ++i){
    totalTime += windows[i].getIdleTime();
  }

  //returns the mean idle time
  return totalTime/(double)windows.size();
}

//function to find the longest window idle time
int Simulation::longestWindowTime(){

  //creates a vector of integers of all the idle times
  vector<int> sortWindowTime;
  for(int i = 0; i < windows.size(); ++i){
    sortWindowTime.push_back(windows[i].getIdleTime());
  }

  //returns the longest idle time
  return *max_element(sortWindowTime.begin(), sortWindowTime.end());
}

//function to calculate the number of window idle times over 5 minutes
int Simulation::numWindowsOver5(){
  int count = 0;

  //loops through all of the window idle times and increases the count if the idle time is over 5 minutes
  for(int i = 0; i < windows.size(); ++i){
    if(windows[i].getIdleTime() > 5){
      count++;
    }
  }
  return count;
}

//function to run the simulation
void Simulation::runSimulation(Queue<int> waitingQueue){
  //creates a queue of students
  Queue<Student> studentQueue;

  //grabs the number of windows and pushes it into the window vector
  int numWindows = waitingQueue.dequeue();
  for(int i = 0; i < numWindows; ++i){
    windows.push_back(Window());
  }

  time = 0;

  //runs the office simulation while there are open windows or there are students in the queue, or there are still numbers in the file to be read
  while(!waitingQueue.isEmpty() || !windowsEmpty() || !studentQueue.isEmpty()){

    //puts the student in the queue when the time matches the student entrance time
    if(!waitingQueue.isEmpty() && time == waitingQueue.peek()){
      waitingQueue.dequeue();

      //grabs the number of students that entered at the time
      int numStudents = waitingQueue.dequeue();

      //queue students with their required time
      for(int i = 0; i < numStudents; ++i){
        int requiredTime = waitingQueue.dequeue();
        studentQueue.enqueue(Student(requiredTime));
      }
    }

    //iterate through windows
    for(int i = 0; i < windows.size(); ++i){

      //if theres an open window and someone is in queue, put student into this window
      if(!windows.at(i).checkOccupied() && !studentQueue.isEmpty()){

        //put student into the window
        windows.at(i).SetStudent(studentQueue.peek());

        //remove the student from the queue
        studentQueue.dequeue();
      }
    }

    //iterate through queue and increment their wait time by 1 for waiting time
    for(int i = 0; i < studentQueue.getSize(); ++i){
      Student temp = studentQueue.dequeue();
      temp.incrementWaitTime();
      studentQueue.enqueue(temp);
    }

    //iterate through the windows
    for(int i = 0; i < windows.size(); ++i){

      //check if window is occupied
      if(windows.at(i).checkOccupied()){

        //decrements the required time when the student is in the window
        Student temp = windows.at(i).getStudent();
        temp.decrementRequiredTime();
        windows.at(i).SetStudent(temp);

        //student finishes their time at the window
        if(windows.at(i).getStudent().getRequiredTime() == 0){

          //puts the student into a vector
          studentWaitTimes.push_back(windows.at(i).getStudent());

          //removes the student from the window
          windows.at(i).removeStudentFromWindow();
        }
      }

      //if the window is not occupied, increments the windows idle time
      else{
        windows.at(i).incrementIdleTime();
      }
    }
    ++time;
  }

  //outputs the statistics
  cout << "Mean Student Wait Time: " << meanWaitTime() << endl;
  cout << "Median Student Wait Time: " << medWaitTime() << endl;
  cout << "Longest Student Wait Time: " << longestWaitTime() << endl;
  cout << "Number of Students Waiting over 10 Minutes: " << numStudentsOver10() << endl;
  cout << "Mean Window Idle Time: " << meanWindowIdleTime() << endl;
  cout << "Longest Window Idle Time: " << longestWindowTime() << endl;
  cout << "Number of Windows Idle for over 5 Minutes: " << numWindowsOver5() << endl;
}
