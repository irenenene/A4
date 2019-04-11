#ifndef LIST_H
#define LIST_H

#include <iostream>
using namespace std;

template <class T>
class LinkedList;

template <class T>
class Node {
  //friend class LinkedList<T>;
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
class LinkedList {
public:
  LinkedList();
  virtual ~LinkedList();
  bool isEmpty();
  unsigned int getSize();

  virtual void insert(T d) = 0;
  virtual void deleteNode() = 0;
  void printList();
  Node<T>* find(T value);

protected:
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
  data = d; // assumes your T uses a copy constructor
  prev = NULL;
  next = NULL;
}

template <class T>
Node<T>::~Node() {
  cout << "start Node dest" << endl;
  prev = NULL;
  next = NULL;
  //delete data;
  cout << "Node destructor done" << endl;
}

/** LinkedList Implementation ***/

template <class T>
LinkedList<T>::LinkedList() {
  head = NULL;
  tail = NULL;
  size = 0;
}

template <class T>
LinkedList<T>::~LinkedList() {
  cout << "begin ll dest" << endl;
  if (!isEmpty()) {
    Node<T> *curr = head;

    while (curr != NULL)
    {
      cout << "loop" << endl;
        Node<T> *temp = curr;
        curr = curr->next;
        delete temp;
    }
  }

  cout << "end LL dest" << endl;
}

template <class T>
bool LinkedList<T>::isEmpty() {
  return (size == 0);
}

template <class T>
unsigned int LinkedList<T>::getSize() {
  return size;
}

template <class T>
Node<T>* LinkedList<T>::find(T value) {
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
void LinkedList<T>::printList() {
  Node<T> *curr = head;

  while (curr != NULL) {
    cout << curr->data << endl;
    curr = curr->next;
  }
}

#endif
