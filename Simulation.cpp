#include "Simulation.h"

Simulation::Simulation() {
  totalStudents = 0;
  totalWindows = 0;
  currentWindows = 0;
  totalTime = 0;
  currentTime = 0;
  line = new Queue<Student>();
}

Simulation::~Simulation() {
  delete line;
}

/*
Simulation::Initialize(string path) { //CHECK FOR INPUT ERRORS
  ifstream inputFile;
  inputFile.open(path);

  if(inputFile.is_open()) { //begin parsing the file
    getline(inputFile, totalWindows);
    currentWindows = totalWindows;
    unsigned int nextTime;
    unsigned int numArrivals;

    getline(inputFile, nextTime); // read line 2
    while (true){
      cout << "Time: " << currentTime++ << endl;

      if(currentTime == nextTime) { // if the current clock time matches, add students
        getline(inputFile, numArrivals);

        for (int i = 1; i <= numArrivals; i++) {
          unsigned int wTime;
          getline(inputFile, wTime);
          line->insert(Student(++totalStudents, wTime));
        }

        getline(inputFile, nextTime); // read line 2
      }


      if (currentWindows > 0) {

      }
    }

    }
    inputFile.close();
  }
}
*/
