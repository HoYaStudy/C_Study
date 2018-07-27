/*******************************************************************************
 *  @brief    Observer pattern module.
 *  @author   llHoYall <hoya128@gmail.com>
 *  @version  v1.0
 *  @note
 *    - 2018.07.27  Created.
 ******************************************************************************/

#ifndef __OBSERVER_PATTERN_H__
#define __OBSERVER_PATTERN_H__

/* Include Headers -----------------------------------------------------------*/
#include <stdbool.h>
#include <stdint.h>

/* Definitions ---------------------------------------------------------------*/
#define MAX_OBSERVER_COUNT 10

/* Type Definitions ----------------------------------------------------------*/
typedef void (*observer_handler_t)(uint32_t value1, uint32_t value2);

/* APIs ----------------------------------------------------------------------*/
extern void init_observer(void);
extern bool register_observer(observer_handler_t observer);
extern bool unregister_observer(observer_handler_t observer);
extern void process_observer(void);

#endif
