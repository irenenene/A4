#include "Window.h"
#include <iostream>
using namespace std;

Window::Window() {
  currentIdleTime = 0;
  timeRemaining = 0; //use students time instead?
  hasStudent = false;
  currentStudent = NULL;
}

Window::~Window() {
//  cout << "Window Destructor" << endl;
  if (currentStudent != NULL)
    delete currentStudent;
  currentStudent = NULL;

}

void Window::openWindow() {
  //if student's windowtime == 0
  //get rid of student
  if(hasStudent) {
    if (currentStudent->windowTime <= 0) {
      hasStudent = false;
      delete currentStudent;
      currentStudent = NULL;

      //currentIdleTime = 0;
    }
  }
}

void Window::updateTimer() {
  if (!hasStudent) {
    currentIdleTime++;
  }
}
