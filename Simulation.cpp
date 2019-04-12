#include "Simulation.h"

Simulation::Simulation() {
  totalStudents = 0;
  totalWindows = 0;
  currentWindows = 0;
  totalWaitTime = 0;
  currentTime = 0;
  nextTime = 0;
  listPosition = 0;

}

Simulation::~Simulation() {

}

bool Simulation::readFromFile(string path) {
  ifstream inputFile;
  inputFile.open(path);

  if(inputFile.is_open()) {
    string temp;
    while(getline(inputFile, temp)) {
      fileData.insertBack(temp);
    }
    inputFile.close();
    return true;
  }

  return false;
}

void Simulation::initialize() {
  totalWindows = stoi(fileData.head->data);
  listPosition++;

  for (int i = 0; i < totalWindows; i++) {
    windows.insertBack(Window());
  }

  //get the next time
  nextTime = stoi(*fileData.getValue(listPosition));
  listPosition++;
}

void Simulation::update() {
  /*
  cout << "Current time: " << currentTime << endl;
  cout << "Next event at:" << nextTime << endl;

  cout << "current listpos" << listPosition << endl;*/
  //check if any new people are arriving in line
  //if so, update line
  if (currentTime == nextTime)
  {
    //cout << "adding" << endl;
    addToLine();
    //cout << "done adding" << endl;
  }

  //check if any window's time remaining is zero
  //if so, move person from line to window
  lineToWindow();

/*
  cout << "Windows" << endl;
  windows.printList();*/
  /*
  cout << "Line" << endl;
  line.printList();*/

  //check if any people are finishing at the window and update windows
  finishWindow();

  //update waiting/idle times/timeRemaining
  updateTimers();

  //clockTick update
  currentTime++;

  //cout << "Finished updating" << endl;
}

void Simulation::lineToWindow() {
  if(!windows.isEmpty()) {
    //Window* currWindow = &windows.head->data;
    Node<Window>* winNode = windows.head;
    Window* currWindow = &winNode->data;

    for (int i = 0; i < windows.getSize(); i++) {
      if(line.isEmpty())
      {
        break;
      }
      else //there are students in line
      {
        if (!currWindow->hasStudent) { //add student
          currWindow->currentStudent = new Student(*line.peek()); //copy of stack student. will be deleted when student leaves
          currWindow->hasStudent = true;
          line.deleteNode(); //dequeue the line since student has been 'moved' to the window

          //record idle time and then reset to 0

          idleTimes.insert(Integer(currWindow->currentIdleTime));
          currWindow->currentIdleTime = 0;
          //record student's wait time.
          waitTimes.insert(Integer(currWindow->currentStudent->currentWaitTime));
        }

        winNode = winNode->next;
        currWindow = &winNode->data;
      }
    }
  }
}

void Simulation::addToLine() {
  //get the number of students arriving
//  cout << "start" << endl;
  int newStuds = stoi(*fileData.getValue(listPosition));
  listPosition++;
  //cout << newStuds << endl;

  for (int i = 0; i < newStuds; i++)
  {
    int wt = stoi(*fileData.getValue(listPosition));
    listPosition++;
    line.insert(Student(++totalStudents, wt)); //this is also where we update totalStudents
  }

  //get the next time
  if(listPosition < fileData.getSize()) {
    nextTime = stoi(*fileData.getValue(listPosition));
    listPosition++;
  }
}

void Simulation::finishWindow() {
  if(!windows.isEmpty()) {
    Node<Window>* winNode = windows.head;
    Window* currWindow = &winNode->data;

    for (int i = 0; i < windows.getSize(); i++) { //for each window
      currWindow->openWindow();

      winNode = winNode->next;
      currWindow = &winNode->data;
    }
  }
}

void Simulation::updateTimers() {

  //for each student currently waiting, increment their wait time
  if(!line.isEmpty()) {
    Node<Student> *currNode = line.head;
    Student* currStudent = &currNode->data;

    for(int i = 0; i < line.getSize(); i++) {
      currStudent->currentWaitTime++;

      currNode = currNode->next;
      currStudent = &currNode->data;
    }
  }
  //for each window without a student, increment their idle time
  //for each student currently at a window, decrement the windowtime
  if(!windows.isEmpty()) {
    Node<Window>* winNode = windows.head;
    Window* currWindow = &winNode->data;

    for (int i = 0; i < windows.getSize(); i++) { //for each window
      if(!currWindow->hasStudent)
      {
        currWindow->currentIdleTime++;
      }
      else {
        currWindow->currentStudent->windowTime--;
        //cout << currWindow->currentStudent->windowTime;
      }


      winNode = winNode->next;
      currWindow = &winNode->data;
    }
  }
}

bool Simulation::allEmpty() {
  bool empty = true;

  if(!windows.isEmpty()) {
    Node<Window>* winNode = windows.head;
    Window* currWindow = &winNode->data;

    for (int i = 0; i < windows.getSize(); i++) { //for each window
      if (currWindow->hasStudent) {
        empty = false;
        break;
      }

      winNode = winNode->next;
      currWindow = &winNode->data;
    }
  }

  return empty;
}

void Simulation::printResults() {
  int idleSum;
  int waitSum;

  if(!idleTimes.isEmpty()) {
    Node<Integer>* number = idleTimes.head;

    for (int i = 0; i < idleTimes.getSize(); i++) { //for each window
      idleSum += number->data.value;
      cout << idleSum << endl;
      number = number->next;
    }
  }
  if(!waitTimes.isEmpty()) {
    Node<Integer>* number = waitTimes.head;

    for (int i = 0; i < waitTimes.getSize(); i++) { //for each window
      waitSum += number->data.value;
      number = number->next;
    }
  }


  cout << "Mean Student Wait Time: " << waitSum << endl;
}
