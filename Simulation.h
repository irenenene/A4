#ifndef SIM_H
#define SIM_H

#include "Student.h"
#include "List.h"
#include "Queue.h"

#include <iostream>
using namespace std;

class Simulation {
public:
  Simulation();
  ~Simulation();
  Queue<Student> *line;
  //void Initialize(); //file input

//private:
  unsigned int totalStudents;
  unsigned int totalWindows;
  unsigned int currentWindows;
  unsigned int totalTime;
  unsigned int currentTime;

};

#endif
