#include "Student.h"
using namespace std;

Student::Student() {
  idNumber = 0;
}

Student::Student(unsigned int id) {
  idNumber = id;
}

Student::~Student() {
  cout << "student dest" << endl;
}

unsigned int Student::getID() {
  return idNumber;
}
/*
bool Student::operator!=(const Student& other) {
  return (this.idNumber != other.idNumber);
}
*/
