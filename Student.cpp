#include "Student.h"
using namespace std;

Student::Student() {
  idNumber = 0;
  currentWaitTime = 0;
  windowTime = 0;
}

Student::Student( int id) {
  idNumber = id;
  currentWaitTime = 0;
  windowTime = 0;
}

Student::Student( int id,  int wt) {
  idNumber = id;
  windowTime = wt;
  currentWaitTime = 0;
}

Student::~Student() {
  //cout << "student dest" << endl;
}

 int Student::getID() {
  return idNumber;
}
