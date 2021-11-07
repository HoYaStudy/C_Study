/**
 * @file message_queue.c
 * @author llHoYall (hoya128@gmail.com)
 * @brief This file is message queue.
 * @version 1.0
 * @date 2021-11-07
 *
 * @copyright Copyright (c) 2021
 */

//--- Includes ---------------------------------------------------------------//
#include <stdbool.h>
#include <stddef.h>
#include <string.h>

#include "message_queue.h"

//--- Local Variables --------------------------------------------------------//
QUEUE tMessageQueue;              ///< Message queue
MESSAGE tMessage[MESSAGE_COUNT];  ///< Messages

//--- Local Function Prototypes ----------------------------------------------//
static bool MessageQ_CheckFull(void);
static bool MessageQ_CheckEmpty(void);

//--- External Functions -----------------------------------------------------//
/**
 * @brief Initialize the message queue
 */
void MessageQ_Init(void) {
  tMessageQueue.head = 0;
  tMessageQueue.tail = 0;
  tMessageQueue.len = MESSAGE_COUNT;
  tMessageQueue.data = &tMessage;
}

/**
 * @brief Set data into the message queue
 * @param[in] msg Message data to set
 * @return True if set message into the message queue
 */
bool MessageQ_Set(PMESSAGE msg) {
  bool result = false;
  if (MessageQ_CheckFull() == false) {
    memcpy(&tMessage[tMessageQueue.head], msg, sizeof(MESSAGE));
    tMessageQueue.head = (tMessageQueue.head + 1) % MESSAGE_COUNT;
    result = true;
  }
  return result;
}

/**
 * @brief Get data into the message queue
 * @return Pointer of the message data that is got
 */
PMESSAGE MessageQ_Get(void) {
  PMESSAGE result = NULL;
  if (MessageQ_CheckEmpty() == false) {
    result = &tMessage[tMessageQueue.tail];
    tMessageQueue.tail = (tMessageQueue.tail + 1) % MESSAGE_COUNT;
  }
  return result;
}

//--- Local Functions --------------------------------------------------------//
/**
 * @brief Check if the message queue is full
 * @return True if the message queue is full
 */
static bool MessageQ_CheckFull(void) {
  bool result = false;
  if ((tMessageQueue.head + 1) % MESSAGE_COUNT == tMessageQueue.tail) {
    result = true;
  }
  return result;
}

/**
 * @brief Check if the message queue is empty
 * @return True if the message queue is empty
 */
static bool MessageQ_CheckEmpty(void) {
  bool result = false;
  if (tMessageQueue.head == tMessageQueue.tail) {
    result = true;
  }
  return result;
}
