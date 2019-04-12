#include "Simulation.h"

Simulation::Simulation() {
  totalStudents = 0;
  totalWindows = 0;
  currentWindows = 0;
  totalWaitTime = 0;
  currentTime = 0;
  nextTime = 0;
  listPosition = 0;
//  line = new Queue<Student>();
//  windows = new LinkList<Window*>();
//  fileData = new LinkList<string>();
}

Simulation::~Simulation() {
//  delete line;
//  delete windows;
//  delete fileData;
  cout << "sim dest" << endl;
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
  cout << "total wins: " << totalWindows << endl;
  listPosition++;

  for (int i = 0; i < totalWindows; i++) {
    windows.insertBack(Window()); //START HERE
  }

  //get the next time
  nextTime = stoi(*fileData.getValue(listPosition));
  listPosition++;

  //line.insert(Student(++totalStudents));
}

void Simulation::update() {
  cout << "Current time: " << currentTime << endl;
  cout << "Next event at:" << nextTime << endl;
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

  cout << "Windows" << endl;
  windows.printList();
  cout << "Line" << endl;
  line.printList();

  //check if any people are finishing at the window and update windows
  void finishWindow();

  //update waiting/idle times/timeRemaining
  void updateTimers();
  //update maximums

  //clockTick update
  currentTime++;
}

void Simulation::lineToWindow() {
  /*
  if(!windows.isEmpty()) {
    Window* currWindow = &windows.head->data;

    if(!line.isEmpty()) { //check if people are in line
      //if there are people in line, check if any windows are open
      while (currWindow != NULL) {
        if (!currWindow->hasStudent) { //if window does not have student
          currWindow->currentStudent = new Student(*line.peek()); // will be deleted when student leaves
          currWindow->hasStudent = true;
          line.deleteNode(); //dequeue the line since student has been 'moved' to the window

          //record idle time and then reset to 0

          break;
        }
      }
    }
  }*/

  //version 2
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


          //record student's wait time.

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
  nextTime = stoi(*fileData.getValue(listPosition));
  listPosition++;
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
        currWindow->currentIdleTime++;
      else
        currWindow->currentStudent->windowTime--;

      winNode = winNode->next;
      currWindow = &winNode->data;
    }
  }
}

/*
Simulation::Initialize(string path) { //CHECK FOR INPUT ERRORS
  ifstream inputFile;
  inputFile.open(path);

  if(inputFile.is_open()) { //begin parsing the file
    getline(inputFile, totalWindows);
    currentWindows = totalWindows;
    unsigned int nextTime;
    unsigned int numArrivals;

    getline(inputFile, nextTime); // read line 2
    while (true){
      cout << "Time: " << currentTime++ << endl;

      if(currentTime == nextTime) { // if the current clock time matches, add students
        getline(inputFile, numArrivals);

        for (int i = 1; i <= numArrivals; i++) {
          unsigned int wTime;
          getline(inputFile, wTime);
          line->insert(Student(++totalStudents, wTime));
        }

        getline(inputFile, nextTime); // read line 2
      }


      if (currentWindows > 0) {

      }
    }

    }
    inputFile.close();
  }
}
*/
