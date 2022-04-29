#include "FileProcessor.h"

int main(int argc, char **argv){
  // creates an instance of FileProcessor class
  FileProcessor f;

  try{

    //checks if user enters correct number of arguments
    if (argc != 2){
      cout << "Not enough command line arguments." << endl;

      //exits
      return 1;
    }

    //uses file processor to grab contents of the file
    f.processFile(argv[1]);
  }

  //catches runtime error
  catch(runtime_error& excpt){
    cout << excpt.what() << endl;
  }
  
  // exit
  return 0;
}
