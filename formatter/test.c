#include <stdio.h>
#include <stdint.h>

#include "test.h"

int main(void) {
  uint8_t var8;
  uint16_t var16;
  uint32_t var32;
  uint8_t* pvar8;
  uint16_t* pvar16;
  uint32_t* pvar32;

  printf("Hello Clang-Format !!!");

  if (var8 > 0) {

  } else if (var8 < 0) {

  } else {

  }

  switch (var8) {
    case 0:
      break;

    case 1:
      break;

    default:
      break;
  }

  for (var8 = 0; var8 < 5; ++var8) {

  }

  while (true) {

  }

  var16 = 5;
  while (var16) {
    --var16;
  }

  var32 = 0;
  do {
    ++var32;
  } while (var32 < 5);

  return 0;
}
