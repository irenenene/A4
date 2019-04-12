#ifndef LIST_H
#define LIST_H

#include <iostream>
using namespace std;

//template <class T>
//class genList;

template <class T>
class Node {
  //friend class genList<T>;
  //friend class Queue<T>;
public:
  Node();
  Node(T d);
  ~Node();
//private:
  T data;
  Node *prev;
  Node *next;
};

template <class T>
class genList {
public:
  genList();
  virtual ~genList();
  bool isEmpty();
  unsigned int getSize();

  virtual void insert(T d) = 0;
  virtual void deleteNode() = 0;
  void printList();
  Node<T>* find(T value);

//protected:
  Node<T> *head;
  Node<T> *tail;
  unsigned int size;

};

/*** Node Implementation ***/

template <class T>
Node<T>::Node() {
  data = NULL;
  prev = NULL;
  next = NULL;
}

template <class T>
Node<T>::Node(T d) {
  data = d; // assumes T d uses a copy constructor
  prev = NULL;
  next = NULL;
}

template <class T>
Node<T>::~Node() {
  prev = NULL;
  next = NULL;
}

/** genList Implementation ***/

template <class T>
genList<T>::genList() {
  head = NULL;
  tail = NULL;
  size = 0;
}

template <class T>
genList<T>::~genList() {
  if (!isEmpty()) {
  //  cout << "not empty" << endl;
    Node<T> *curr = head;

    while (curr != NULL)
    {
        Node<T> *temp = curr;
        curr = curr->next;
        delete temp;
    }
  }

//  cout << "List dest" << endl;
}

template <class T>
bool genList<T>::isEmpty() {
  return (size == 0);
}

template <class T>
unsigned int genList<T>::getSize() {
  return size;
}

template <class T>
Node<T>* genList<T>::find(T value) {
  if(!isEmpty()) {
    Node<T> *curr = head;

    while(curr != NULL) {
      if (curr->data == value)
        return curr;
      else
        curr = curr->next;
    }
  }
  return NULL;
}

template <class T>
void genList<T>::printList() {
  Node<T> *curr = head;

  while (curr != NULL) {
    cout << curr->data << endl;
    curr = curr->next;
  }
}

#endif
