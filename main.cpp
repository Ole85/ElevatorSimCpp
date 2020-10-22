#include <iostream>
#include <ncurses.h>
#include <unistd.h>

#include "ElevatorIOPanel.hpp"
#include "ElevatorLogic.hpp"
#include "enums.hpp"

int main() {
  ElevatorLogic Logic;

  initscr();
  noecho();
  nodelay(stdscr, true);
  ElevatorIOPanel IOPanel;
  while (1) {

    IOPanel.getInput(Logic.values.arrayCalls);
    Logic.update(IOPanel.insertNumber);
    IOPanel.output(Logic.values);
    napms(1000);
    Logic.timerUpdate();
  }
  endwin();
  return 0;
}