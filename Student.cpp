#include "Student.h"
using namespace std;

Student::Student() {
  idNumber = 0;
  currentWaitTime = 0;
  windowTime = 0;
}

Student::Student(unsigned int id, unsigned int wt) {
  idNumber = id;
  windowTime = wt;
  currentWaitTime = 0;
}

Student::~Student() {
  cout << "student dest" << endl;
}

unsigned int Student::getID() {
  return idNumber;
}
