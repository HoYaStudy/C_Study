/**
 * @file message_queue.h
 * @author llHoYall (hoya128@gmail.com)
 * @brief This file is message queue.
 * @version 1.0
 * @date 2021-11-07
 *
 * @copyright Copyright (c) 2021
 */

#ifndef __MESSAGE_QUEUE_H__
#define __MESSAGE_QUEUE_H__

//--- Includes ---------------------------------------------------------------//
#include "queue.h"

//--- Definitions ------------------------------------------------------------//
#define MESSAGE_SIZE (16)  ///< Size of a message
#define MESSAGE_COUNT (8)  ///< Number of messages

//--- Type Definitions -------------------------------------------------------//
/**
 * @struct MESSAGE
 * @brief Message queue
 */
typedef struct {
  uint8_t msgID;               ///< Message identifier
  uint8_t len;                 ///< Length of the message data
  uint8_t data[MESSAGE_SIZE];  ///< Data of the message
} MESSAGE, *PMESSAGE;

//--- External Functions -----------------------------------------------------//
/**
 * @brief Initialize the message queue
 */
extern void MessageQ_Init(void);

/**
 * @brief Set data into the message queue
 * @param[in] msg Message data to set
 * @return True if set message into the message queue
 */
extern bool MessageQ_Set(PMESSAGE msg);

/**
 * @brief Get data into the message queue
 * @return Pointer of the message data that is got
 */
extern PMESSAGE MessageQ_Get(void);

#endif
