/*******************************************************************************
 *  @brief    Observer pattern module.
 *  @author   llHoYall <hoya128@gmail.com>
 *  @version  v1.0
 *  @note
 *    - 2018.07.27  Created.
 ******************************************************************************/

/* Include Headers -----------------------------------------------------------*/
#include <stdio.h>
#include <stdbool.h>
#include <stdint.h>

#include "observer.h"

/* Private Variables ---------------------------------------------------------*/
static observer_handler_t observer_handlers[MAX_OBSERVER_COUNT];
static uint8_t observer_handler_count = 0;

/* APIs ----------------------------------------------------------------------*/
void init_observer(void) {
  for (uint8_t i = 0; i < MAX_OBSERVER_COUNT; ++i) {
    observer_handlers[i] = NULL;
  }
  observer_handler_count = 0;
}

bool register_observer(observer_handler_t observer) {
  if (MAX_OBSERVER_COUNT <= observer_handler_count) {
    return false;
  }

  for (uint8_t i = 0; i < MAX_OBSERVER_COUNT; ++i) {
    if (observer_handlers[i] == observer) {
      return true;
    }
  }

  observer_handlers[observer_handler_count++] = observer;
  return true;
}

bool unregister_observer(observer_handler_t observer) {
  for (uint8_t i = 0; i < observer_handler_count; ++i) {
    if (observer_handlers[i] == observer) {
      observer_handlers[i] = NULL;
      for (uint8_t j = i; j < observer_handler_count; ++j) {
        if ((j + 1) == observer_handler_count) {
          break;
        }
        observer_handlers[j] = observer_handlers[j + 1];
      }
      --observer_handler_count;
      return true;
    }
  }
  return false;
}

void process_observer(void) {
  static uint32_t v[4] = {0};

  v[0] += 1;
  v[1] += 2;
  v[2] += 3;
  v[3] += 4;

  for (uint8_t i = 0; i < observer_handler_count; ++i) {
    observer_handlers[i](v[i * 2 + 0], v[i * 2 + 1]);
  }
}
