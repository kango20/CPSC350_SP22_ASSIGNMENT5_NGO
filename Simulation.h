#ifndef SIMULATION_H
#define SIMULATION_H

#include "Window.h"
#include "FileProcessor.h"
#include "Queue.h"
#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
using namespace std;

class Simulation{
public:
  Simulation();
  ~Simulation();
  bool windowsEmpty();
  void runSimulation(Queue<int> wQ);

  double meanWaitTime();
  double medWaitTime();
  int longestWaitTime();
  int numStudentsOver10();

  double meanWindowIdleTime();
  int longestWindowTime();
  int numWindowsOver5();


private:
  vector<Window> windows;
  vector<Student> studentWaitTimes;
  int time;

};

#endif
