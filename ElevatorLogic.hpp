#pragma once

#include "enums.hpp"
#include <ncurses.h>

class ElevatorLogic {
public:
  ElevatorLogic() = default;
  int returnQtyCalls();
  void update(int insertNumber);
  void timerUpdate();
  int returnPosition();
  void movePositionUp();
  void movePosDown();

  data values;

private:
  int index;
};