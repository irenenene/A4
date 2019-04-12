#include "Student.h"
#include "Window.h"
#include "List.h"
#include "Queue.h"
#include "LinkList.h"
#include "Simulation.h"

#include <iostream>
#include <fstream>
using namespace std;

int main (int argc, char **argv) {
  Simulation sim;
/*
  if(sim.readFromFile("testfile"))
    sim.fileData.printList();
    */

  sim.readFromFile("testfile");

  sim.initialize();
  sim.update();
  sim.update();

  /*Queue<Student> *intQueue;
  intQueue = new Queue<Student>();
  Student bob(10);
  Student alice(20);

  intQueue->insert(bob);
  intQueue->insert(alice);
  intQueue->printList();
  cout << *intQueue->peek();
  delete intQueue;*/
}
