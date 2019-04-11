#ifndef QUEUE_H
#define QUEUE_H

#include "List.h"
using namespace std;

template <class T>
class Queue : public LinkedList<T> {
public:
  Queue();
  ~Queue();
  void insert(T d); //enqueue
  void deleteNode(); //dequeue
  T* peek();
};

template <class T>
Queue<T>::Queue() : LinkedList<T>() {

}

template <class T>
Queue<T>::~Queue() { // base destructor will be called afterwards automatically
  cout << "Queue dest" << endl;
}

template <class T>
void Queue<T>::insert(T d) {
  Node<T> *newNode = new Node<T>(d);

  if (!this->isEmpty()) { //update pointers before making tail point to newNode
    this->tail->next = newNode;
    newNode->prev = this->tail;
  }
  else
    this->head = newNode;

  this->tail = newNode;
  this->size++;

  cout << this->size << endl;
}

template <class T>
void Queue<T>::deleteNode() {
  if(!this->isEmpty()) { //if there are nodes to delete
    Node<T> *curr = NULL;

    if (this->size == 1) { //only 1 item in queue
      curr = this->head;
      this->head = NULL;
      this->tail = NULL;
    }
    else if (this->size > 1) { //2 or more items in queue
      curr = this->head;
      this->head = this->head->next; //update head to next node
      this->head->prev = NULL; //make new head's prev point to null
    }

    curr->next = NULL; //prev should already be NULL
    this->size--;
    delete curr;
  }
}

template <class T>
T* Queue<T>::peek() { //returns a pointer to first NODE's DATA
  return &this->head->data;
}
#endif
