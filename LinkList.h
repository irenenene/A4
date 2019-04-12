#ifndef LINK_H
#define LINK_H

#include "List.h"
using namespace std;

template <class T>
class LinkList : public genList<T> {
public:
  LinkList();
  ~LinkList();
  void insert(T d); //inserts to front
  void insertBack(T d);
  void deleteNode(); //deletes from rear
  T* getValue(int index);
};

template <class T>
LinkList<T>::LinkList() : genList<T>() {

}

template <class T>
LinkList<T>::~LinkList() {

}

template <class T>
void LinkList<T>::insert(T d) {
  Node<T> *newNode = new Node<T>(d);

  if (!this->isEmpty()) {
    newNode->next = this->head;
    this->head->prev = newNode;
  }
  else
    this->tail = newNode;

  this->head = newNode;
  this->size++;
}

template <class T>
void LinkList<T>::insertBack(T d) {
  Node<T> *newNode = new Node<T>(d);

  if (!this->isEmpty()) {
    this->tail->next = newNode;
    newNode->prev = this->tail;
  }
  else
    this->head = newNode;

  this->tail = newNode;
  this->size++;
}

template <class T>
void LinkList<T>::deleteNode() {
  if(!this->isEmpty()) {
    Node<T> *curr = NULL;

    if (this->size == 1) {
      curr = this->head;
      this->head = NULL;
      this->tail = NULL;
    }
    else if (this->size > 1) {
      curr = this->tail;
      this->tail = this->tail->prev;
      this->tail->next = NULL;
    }

    curr->prev = NULL;
    this->size--;
    delete curr;
  }
}

template <class T>
T* LinkList<T>::getValue(int index) {
  //cout << this->size;
  if (index < this->size) {
    Node<T>* curr = this->head;

    for ( int i = 0; i < index; i++) {
      curr = curr->next;
    }

    return &curr->data;
  }
}

#endif
