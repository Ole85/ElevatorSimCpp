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
    printw("InsertNumber %i\n", insertNumber);
    move(10, 20);
    printw("Direction: %i", values.directionElevator);
    move(11, 0);
    printw("Timer Elevator: %i", values.timerElevator);
    move(11, 20);
    printw("Timer Door: %i", values.timerDoor);
    // printw("TimerDoor: ");
    // move(11, 20);
    // printw("TimerElevator: ");
    // printw("CallCheck: %i", returnCallCheck(arrayCalls)); //
    // move(12, 20);
    // printw("ReturnPos: %i\n", Position);
    // printw("DoorState: %i\n", *ptrDoorState);
    move(12, 20);
    refresh();
  }
}

// void ElevatorIOPanel::displayPosition(int arrayPos[]) {
//   int my;
//   int mx;
//   move(0, 0);
//   for (int i = 0; i < 4; i++) {

//     if (arrayPos[i] == 0) {

//       printw(" \n");
//       attron(COLOR_PAIR(1));
//       getyx(stdscr, my, mx);
//       move(my, 10);
//       printw(" %i \n", i + 1);
//       attroff(COLOR_PAIR(1));
//     } else if (arrayPos[i] == 1) {
//       printw(" \n");

//       printw(" ");
//       attron(COLOR_PAIR(2));
//       getyx(stdscr, my, mx);
//       move(my, 10);
//       printw(" %i \n", i + 1);
//       attroff(COLOR_PAIR(2));
//     }
//   }
// }

void ElevatorIOPanel::getInput(int arrayElevatorCalls[]) {
  insertNumber = getch() - '0';
  for (index = 0; index < 4; index++) {
    if ((insertNumber - 1) == index) {
      arrayElevatorCalls[index] = 1;
    }
  }
}

// void ElevatorIOPanel::displayMonitor(data values) {
//   move(10, 0);
//   printw("InsertNumber %i\n", insertNumber);
//   move(10, 20);
//   printw("Direction: %i", values.directionElevator);
//   move(11, 0);
//   printw("Timer Elevator: %i", values.timerElevator);
//   move(11, 20);
//   printw("Timer Door: %i", values.timerDoor);
//   // printw("TimerDoor: ");
//   // move(11, 20);
//   // printw("TimerElevator: ");
//   // printw("CallCheck: %i", returnCallCheck(arrayCalls)); //
//   // move(12, 20);
//   // printw("ReturnPos: %i\n", Position);
//   // printw("DoorState: %i\n", *ptrDoorState);
//   move(12, 20);
//   refresh();
// }
