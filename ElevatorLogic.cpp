#include "ElevatorLogic.hpp"

int ElevatorLogic::returnQtyCalls() {
  int counter = 0;
  for (index = 0; index < 4; index++) {
    if (values.arrayCalls[index] == 1) {
      counter++;
    }
  }
  return counter;
}

void ElevatorLogic::update(int insertNumber) {
  move(12, 0);
  printw("hello\n");
  printw("%i", insertNumber);
  refresh();

  // Functions if no direction is defined
  if (values.directionElevator == nodirection && insertNumber != -49) {
    if (insertNumber > returnPosition()) {
      values.directionElevator = up;
      printw("up");
    } else if (insertNumber < returnPosition()) {
      values.directionElevator = down;
      printw("down");
    }
  }

  //   // Door related functions
  if (values.stateDoor == closed && values.timerElevator == -1) {
    if (returnPosition() == insertNumber) {
      values.stateDoor = open;
      values.timerDoor = 0;
    }
  }

  //   // Reset Door
  if (values.timerDoor > -1 && insertNumber == returnPosition()) {
    values.timerDoor = 0;
  }
  // Close door
  if (values.timerDoor == 6) {
    values.stateDoor = closed;
    values.timerDoor = -1;
    values.arrayCalls[returnPosition() - 1] = 0;
  }

  // start elevator timer
  if (values.timerElevator == -1 && values.stateDoor == closed &&
      values.directionElevator != nodirection) {
    values.timerElevator = 0;
  }

  // Switch logic
  if (values.timerElevator == 4) {

    if (values.directionElevator == up) {
      movePositionUp();
      if (returnPosition() == 4) {
        values.directionElevator = down;
        values.timerElevator = 0;
      } else {
        values.directionElevator = up;
        values.timerElevator = 0;
      }

      if (values.arrayCalls[returnPosition() - 1] == 1) {
        values.timerDoor = 0;
        values.stateDoor = open;
        values.timerElevator = -1;

        if (values.stateDoor == open && returnQtyCalls() == 1) {
          values.directionElevator = nodirection;
        }
      }
    } else if (values.directionElevator == down) {
      movePosDown();

      if (returnPosition() == 1) {
        values.directionElevator = up;
        values.timerElevator = 0;
      } else {
        values.directionElevator = down;
        values.timerElevator = 0;
      }

      if (values.arrayCalls[(returnPosition() - 1)] == 1) { // Elevator stops
        values.timerDoor = 0;
        values.stateDoor = open;
        values.timerElevator = -1;

        if (values.stateDoor == open && returnQtyCalls() == 1) {
          values.directionElevator = nodirection;
        }
      }
    }
  }
}

int ElevatorLogic::returnPosition() {
  int index = 0;
  for (index = 0; values.arrayPosition[index] != 1; index++) {
  }
  return index + 1;
}

void ElevatorLogic::timerUpdate() {
  if (values.timerDoor > -1) {
    values.timerDoor++;
  }

  if (values.timerElevator > -1) {
    values.timerElevator++;
  }
}

// // move arrayPos one position up
void ElevatorLogic::movePositionUp() {
  int index = returnPosition() - 1;
  values.arrayPosition[index] = 0;
  values.arrayPosition[index + 1] = 1;
}

// move ArrayPos one position down
void ElevatorLogic::movePosDown() {
  int index = returnPosition() - 1;
  values.arrayPosition[index] = 0;
  values.arrayPosition[index - 1] = 1;
}
