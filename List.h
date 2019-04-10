#ifndef LIST_H
#define LIST_H

#include <iostream>
using namespace std;

template <class T>
class LinkedList;

template <class T>
class Node {
  friend class LinkedList<T>;
private:
  T *data;
  Node *prev;
  Node *next;

  Node();
  Node(T *d);
  ~Node();
};

template <class T>
class LinkedList {
public:
  LinkedList();
  virtual ~LinkedList();
  bool isEmpty();
  unsigned int getSize();

  //search, insert, and delete
  Node<T>* find(T* value);
  virtual void insert() = 0;
  virtual void deleteNode() = 0;
//  void printList();
//  void insertBack(T* d);
//  void insertAfter(Node* pre);

private:
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
Node<T>::Node(T *d) {
  data = d;
  prev = NULL;
  next = NULL;
}

template <class T>
Node<T>::~Node() {
  prev = NULL;
  next = NULL;
  data = NULL;
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
  if (!isEmpty()) {
    Node<T> *curr = head;

    while (curr != NULL)
    {
        Node<T> *temp = curr;
        curr = curr->next;
        delete temp;
    }
  }
}

template <class T>
bool LinkedList<T>::isEmpty() {
  return (size > 0);
  //or check if head is null
}

template <class T>
unsigned int LinkedList<T>::getSize() {
  return size;
}

template <class T>
Node<T>* LinkedList<T>::find(T* value) {
  Node<T> *current = head;

  while(current != NULL) { //iterate through all nodes until the current is null
    if (current->data == value) //if data points to same object as value
      return current;

    current = current->next;
  }

  return current; //will point to null if not found
}

/*
template <class T>
void LinkedList<T>::insertFront(T *obj) {
  Node *newNode = new Node(obj); //create the node to be added

  if (!isEmpty) { //update pointers before making head point to newNode
    head->prev = newNode;
    newNode->next = head;
  }
  else
    tail = newNode;

  head = newNode;
  size++;
}

*/

/*
template <class T>
void LinkedList<T>::insertBack(T *obj) {
  Node *newNode = new Node(obj);

  if (!isEmpty) {
    newNode->prev = tail;
    tail->next = newNode;
  }
  else
    head = newNode;

  tail = newNode;
  size++;
}
*/


#endif
