#ifndef SIM_H
#define SIM_H

#include "Student.h"
#include "Window.h"
#include "List.h"
#include "Queue.h"
#include "LinkList.h"
#include "Integer.h"

#include <iostream>
#include <fstream>
#include <string>
using namespace std;

class Simulation {
public:
  Simulation();
  ~Simulation();
  LinkList<Integer> idleTimes;
  LinkList<Integer> waitTimes;
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
  bool allEmpty(); //returns true if all windows are empty
  void printResults();

//private:
  int totalStudents;
  int totalWindows;
  int currentWindows;
  int currentTime;
  int nextTime; //next time to add students
  int listPosition;
//for metrics

  int totalWaitTime;
/*  int longestWaitTime;
  int totalIdle;
  int longestIdle;*/
};

#endif
