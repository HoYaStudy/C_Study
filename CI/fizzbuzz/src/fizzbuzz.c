#include "fizzbuzz.h"

color_t getColor(int value) {
  if (((value % 3) == 0) && ((value % 5) == 0)) {
    return BLUE;
  } else if ((value % 3) == 0) {
    return RED;
  } else if ((value % 5) == 0) {
    return GREEN;
  }
  return NONE;
}