#pragma once
#include <iostream>
#define position (index + 1)

enum directionsElevator { down, up, nodirection };
enum statesDoor { closed, open };
struct data {
  int arrayCalls[4] = {0, 0, 0, 0};
  int arrayPosition[4] = {0, 0, 1, 0};
  directionsElevator directionElevator = nodirection;
  statesDoor stateDoor = closed;
  int timerDoor = -1;
  int timerElevator = -1;
};

inline const char *directionAsName(const directionsElevator &direction) {
  switch (direction) {
  case down:
    return "down";
    break;
  case up:
    return "up";
    break;
  case nodirection:
    return "nodirection";
    break;
  default:
    return "nodirection";
    break;
  }
}
