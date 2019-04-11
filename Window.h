#ifndef WINDOW_H
#define WINDOW_H

#include "Student.h"
#include <iostream>

using namespace std;

class Window {
public:
  Window();
  ~Window();
  
  bool hasStudent;
  unsigned int currentIdleTime;
  unsigned int timeRemaining; //remaining time for current student
  Student currentStudent; //assumes copy constructor
};

#endif
