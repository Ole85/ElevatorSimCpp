#pragma once
#include "enums.hpp"
#include <iostream>
#include <ncurses.h>

class ElevatorIOPanel { // Elevator Panel for In Out Signals

public:
  ElevatorIOPanel();
  void getInput(int arrayCalls[]);
  void output(data values);
  void displayMonitor(data values);
  void myColors();

  int insertNumber = -49;

private:
  int index;
};
