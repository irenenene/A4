#ifndef STUDENT_H
#define STUDENT_H
#include <iostream>
using namespace std;

class Student {
public:
  Student();
  Student( int);
  Student(const Student& other) {
    idNumber = other.idNumber;
    currentWaitTime = other.currentWaitTime;
    windowTime = other.windowTime;}

  Student( int id,  int wt);
  ~Student();
   int getID();
   int currentWaitTime;
   int windowTime;

  bool operator!=(const Student& other) {
    return (this->idNumber != other.idNumber);
  }
  friend ostream &operator<<(ostream& os, const Student& person) {
    return os << person.idNumber;
  }
private:
   int idNumber;
};

#endif
