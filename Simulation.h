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
  Queue<Student> line;
  LinkList<Window> windows;
  LinkList<string> fileData;
  bool readFromFile(string); //file input, use with stoul?
  void initialize();
  void update();
  void lineToWindow();
  void addToLine();
  void finishWindow();
  void updateTimers();

//private:
  int totalStudents;
  int totalWindows;
  int currentWindows;
  int totalWaitTime;
  int currentTime;
  int nextTime; //next time to add students
  int listPosition;
};

#endif
