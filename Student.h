#ifndef STUDENT_H
#define STUDENT_H
#include <iostream>
using namespace std;

class Student {
public:
  Student();
  Student(unsigned int);
  Student(const Student& other) {
    idNumber = other.idNumber;
    currentWaitTime = other.currentWaitTime;
    windowTime = other.windowTime;}

  Student(unsigned int id, unsigned int wt);
  ~Student();
  unsigned int getID();
  unsigned int currentWaitTime;
  unsigned int windowTime;

  bool operator!=(const Student& other) {
    return (this->idNumber != other.idNumber);
  }
  friend ostream &operator<<(ostream& os, const Student& person) {
    return os << person.idNumber;
  }
private:
  unsigned int idNumber;
};

#endif
