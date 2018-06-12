#include <stdio.h>
#include "fizzbuzz.h"

int main(void) {
  for (int i = 1; i <= 100; ++i) {
    printf("%d -> ", i);
    color_t color = getColor(i);
    switch (color) {
      case RED:
        printf("red");
        break;
      case GREEN:
        printf("green");
        break;
      case BLUE:
        printf("blue");
        break;
      case NONE:
        printf("none");
        break;
    }
    printf("\n");
  }
  return 0;
}