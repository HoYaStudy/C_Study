/*******************************************************************************
 *  @brief    Main routine of Observer pattern.
 *  @author   llHoYall <hoya128@gmail.com>
 *  @version  v1.0
 *  @note
 *    - 2018.07.27  Created.
 ******************************************************************************/

/* Include Headers -----------------------------------------------------------*/
#include <stdio.h>
#include <unistd.h>

#include "observer.h"

/* Private Function Prototypes -----------------------------------------------*/
static void observer1(uint32_t value1, uint32_t value2);
static void observer2(uint32_t value1, uint32_t value2);

/* Main Routine --------------------------------------------------------------*/
void main(void) {
  register_observer(observer1);
  register_observer(observer2);
  while (1) {
    process_observer();
    usleep(1000000);
  }
}

/* Private Functions ---------------------------------------------------------*/
static void observer1(uint32_t value1, uint32_t value2) {
  printf("Observer 1: %u, %u\n", value1, value2);
}

static void observer2(uint32_t value1, uint32_t value2) {
  printf("Observer 2: %u, %u\n", value1, value2);
}