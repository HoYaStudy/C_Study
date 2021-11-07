/**
 * @file queue.h
 * @author llHoYall (you@domain.com)
 * @brief This is generic queue.
 * @version 1.0
 * @date 2021-11-07
 *
 * @copyright Copyright (c) 2021
 */

#ifndef __QUEUE_H__
#define __QUEUE_H__

//--- Includes ---------------------------------------------------------------//
#include <stdint.h>

//--- Type Definitions -------------------------------------------------------//
/**
 * @struct QUEUE
 * @brief Generic queue structure
 */
typedef struct {
  uint8_t head;  ///< Index of the queue that is item entering
  uint8_t tail;  ///< Index of the queue that is item exiting
  uint8_t len;   ///< Length of the queue
  void* data;    ///< Pointer that indicates data of the queue
} QUEUE, *PQUEUE;

#endif
