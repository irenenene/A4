#ifndef WINDOW_H
#define WINDOW_H

#include "Student.h"
#include <iostream>
using namespace std;

class Window {
public:
  Window();
  ~Window();
  void openWindow();
  void updateTimer();

  bool hasStudent;
  unsigned int currentIdleTime;
  unsigned int timeRemaining; //remaining time for current student
  Student *currentStudent;
  friend ostream &operator<<(ostream& os, const Window& win) {
    if (win.hasStudent)
      return os << win.currentStudent->getID();
    else
      return os << "Empty Window";
  }
};

#endif
