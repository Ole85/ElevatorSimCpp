# Elevator Simulator C++

![Alt text](elevator2.gif?raw=true "Optional Title")

---

### 1. Compile instructions

```
g++ main.cpp ElevatorIOPanel.cpp ElevatorLogic.cpp -o main -lncurses
```

The program is written with help of *ncurses*-Libray. It helps to design a text user interface in terminal.\
*ncurses*-Library is included in Linux-distribution.\
Using ncurses on Windows-Platforms you have to install PDCurses-Library.

---

### 2. Programm Description:

The **left column** demonstrates the calls. Each time you press a number (1 to 4) an elevator call is executed and saved in the call-array.\
The **right column** demonstrates the right-now position of elevator. The elevators will move to the levels until all elevator calls are done.\
Detailed comments can be found in the code.
