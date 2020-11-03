#pragma once
#include <iostream>
#define position (index + 1)

enum directionsElevator { down, up, nodirection };
enum statesDoor { closed, open };
struct data {
  int arrayCalls[4] = {0, 0, 0, 0};
  int arrayPosition[4] = {1, 0, 0, 0};
  directionsElevator directionElevator = nodirection;
  statesDoor stateDoor = closed;
  int timerDoor = -1;
  int timerElevator = -1;
};

inline const char *directionAsName(const directionsElevator &direction) {
  switch (direction) {
  case down:
    return "DOWN";
    break;
  case up:
    return "UP";
    break;
  case nodirection:
    return "ELEVATOR STOPPED";
    break;
  default:
    return "No Calls";
    break;
  }
}

inline const char *timerElevatorAsText(const int &timerElevator) {
  if (timerElevator == -1) {
    return "ELEVATOR STOPPED";
  } else {
    std::string s = std::to_string(timerElevator);
    const char *buffer = s.c_str();
    return buffer;
  }
};

inline const char *timerDoorAsText(const int &timerDoor) {
  if (timerDoor == -1) {
    return "DOOR CLOSED";
  } else {
    std::string s = std::to_string(timerDoor);
    const char *buffer = s.c_str();
    return buffer;
  }
};
