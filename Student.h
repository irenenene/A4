#ifndef STUDENT_H
#define STUDENT_H
#include <iostream>

using namespace std;

class Student {
public:
  Student();
  Student(const Student& other) {idNumber = other.idNumber;}
  Student(unsigned int id);
  ~Student();
  unsigned int getID();

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
