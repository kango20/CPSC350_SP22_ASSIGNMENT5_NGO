#ifndef FILEPROCESSOR_H
#define FILEPROCESSOR_H

#include "Queue.h"
#include "Simulation.h"
#include <iostream>
#include <fstream>
#include <exception>
using namespace std;

class FileProcessor{
  public:
    FileProcessor(); // default constructor
    ~FileProcessor(); // default destructor
    void processFile(string inputFile); //function that takes in a string representing the input file with English text and output file with the Tutnese translation
  private:

};

#endif
