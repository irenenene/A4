#ifndef SIM_H
#define SIM_H

#include "Student.h"
#include "Window.h"
#include "List.h"
#include "Queue.h"
#include "LinkList.h"

#include <iostream>
#include <fstream>
#include <string>
using namespace std;

class Simulation {
public:
  Simulation();
  ~Simulation();
  Queue<Student> *line;
  LinkList<Window> *windows;
  LinkList<string> *fileData;
  void readFromFile(string); //file input, use with stoul?

//private:
  unsigned int totalStudents;
  unsigned int totalWindows;
  unsigned int currentWindows;
  unsigned int totalTime;
  unsigned int currentTime;

};

#endif
