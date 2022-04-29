#include "FileProcessor.h"

// default constructor
FileProcessor::FileProcessor(){}

// default destructor
FileProcessor::~FileProcessor(){}

//function to read the file and put the contents of the file into a queue
void FileProcessor::processFile(string inputFile){
  Queue<int> waitingQueue;
  Simulation s;

  // input file stream
  ifstream inFS;
  string line;

  //opens the input file
  inFS.open(inputFile);

  // throws an error if file does not open
  if(!inFS.is_open()){
    throw runtime_error("Could not open file");
  }

  //grabs the first line of the file
  getline(inFS,line);
  int first = stoi(line);

  //puts the first line into the queue
  waitingQueue.enqueue(first);

  //loops through the file and enqueue the contents line by line into the Queue
  while(getline(inFS,line)){
    int temp = stoi(line);
    waitingQueue.enqueue(temp);
  }

  //run the simulation with the queue
  s.runSimulation(waitingQueue);
  
  //Done with file, so close it
  inFS.close();
}
