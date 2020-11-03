#include "ElevatorIOPanel.hpp"

void ElevatorIOPanel::myColors() {
  start_color();
  init_pair(1, COLOR_BLACK, COLOR_WHITE);
  init_pair(2, COLOR_BLACK, COLOR_CYAN);
}
ElevatorIOPanel::ElevatorIOPanel() { this->myColors(); }

void ElevatorIOPanel::output(data values) {
  erase();
  printw("Calls");

  refresh();
  move(1, 0);
  for (int i = 0; i < 4; i++) {
    if (values.arrayCalls[i] == 0) {

      printw(" \n");

      printw(" ");
      attron(COLOR_PAIR(1));
      printw(" %i \n", i + 1);
      attroff(COLOR_PAIR(1));
    } else if (values.arrayCalls[i] == 1) {
      printw(" \n");

      printw(" ");
      attron(COLOR_PAIR(2));
      printw(" %i \n", i + 1);
      attroff(COLOR_PAIR(2));
    }
  }
  int my;
  int mx;
  move(0, 10);
  printw("Position");
  move(1, 10);
  index = 0;
  for (index = 0; index < 4; index++) {

    for (index = 0; index < 4; index++) {

      if (values.arrayPosition[index] == 0) {

        printw(" \n");
        attron(COLOR_PAIR(1));
        getyx(stdscr, my, mx);
        move(my, 10);
        printw(" %i \n", index + 1);
        attroff(COLOR_PAIR(1));
      } else if (values.arrayPosition[index] == 1) {
        printw(" \n");

        printw(" ");
        attron(COLOR_PAIR(2));
        getyx(stdscr, my, mx);
        move(my, 10);
        printw(" %i \n", index + 1);
        attroff(COLOR_PAIR(2));
      }
    }

    move(10, 0);
    // printw("InsertNumber %i\n", insertNumber);
    // move(10, 20);
    printw("Direction: %s", directionAsName(values.directionElevator));
    move(11, 0);
    printw("Timer Elevator: %s", timerElevatorAsText(values.timerElevator));
    move(12, 0);
    printw("Timer Door: %s", timerDoorAsText(values.timerDoor));
    refresh();
  }
}

void ElevatorIOPanel::getInput(int arrayElevatorCalls[]) {
  insertNumber = getch() - '0';
  if (insertNumber > 0 && insertNumber < 5) {
    for (index = 0; index < 4; index++) {
      if ((insertNumber - 1) == index) {
        arrayElevatorCalls[index] = 1;
      }
    }
  } else {
    insertNumber = -49;
  }
}