#ifndef INT_H
#define INT_H
#include <iostream>
using namespace std;

class Integer {
public:
  Integer();
  Integer(int);
  ~Integer();
  int value;

  friend bool operator== (const Integer &num1, const Integer &num2) {
    return num1.value == num2.value;
  };
  friend bool operator!= (const Integer &num1, const Integer &num2) {
    return !(num1.value == num2.value);
  };
  friend bool operator< (const Integer &num1, const Integer &num2) {
    return (num1.value < num2.value) && (num1.value != num2.value);
  };
  friend bool operator> (const Integer &num1, const Integer &num2) {
    return num1.value > num2.value;
  };
  friend bool operator<= (const Integer &num1, const Integer &num2) {
    return !(num1.value > num2.value);
  };
  friend bool operator>= (const Integer &num1, const Integer &num2) {
    return !(num1.value < num2.value);
  };
  friend ostream &operator<<(ostream& os, const Integer& number) {
    return os << number.value;
  }

};
#endif
