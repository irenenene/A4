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
  string file = argv[1];
  sim.readFromFile(file);

  sim.initialize();
  while( (!sim.line.isEmpty()) || (sim.listPosition < sim.fileData.getSize()) || !sim.allEmpty())
  {
    sim.update();
  }
/*
  sim.idleTimes.sort();
  sim.waitTimes.sort();*/

  sim.printResults();

  return 0;
}
