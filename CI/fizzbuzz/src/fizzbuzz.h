#ifndef _FIZZBUZZ_H
#define _FIZZBUZZ_H

typedef enum {
  NONE,
  RED,
  GREEN,
  BLUE
} color_t;

color_t getColor(int value);

#endif // _FIZZBUZZ_H
