/*******************************************************************************
 * @brief			Message processing.
 * @author		llHoYall <hoya128@gmail.com>
 * @version		v0.0.5
 * @note
 * 	- 2018.05.14	Created.
 ******************************************************************************/

/* Include Headers -----------------------------------------------------------*/
// Standard
#include <stdint.h>
// System
#include "message.h"

#ifdef __cplusplus
extern "C" {
#endif

/* Private Structures --------------------------------------------------------*/
typedef struct {
  msg_e msg;
  uint32_t param1;
  uint32_t param2;
} message_t;

/* Definitions ---------------------------------------------------------------*/
#define MESSAGE_QUEUE_LENGTH (30)

/* Private Variables ---------------------------------------------------------*/
static message_t g_message_queue[MESSAGE_QUEUE_LENGTH] = {MSG_NONE};
static uint8_t g_message_queue_head = 0;
static uint8_t g_message_queue_tail = 0;

/* APIs ----------------------------------------------------------------------*/
msg_status_e clearMessage(void) {
  g_message_queue_head = 0;
  g_message_queue_tail = 0;
  return MSG_SUCCESS;
}

msg_status_e enqueueMessage(msg_e msg, uint32_t param1, uint32_t param2) {
  g_message_queue[g_message_queue_tail].msg = msg;
  g_message_queue[g_message_queue_tail].param1 = param1;
  g_message_queue[g_message_queue_tail].param2 = param2;
  ++g_message_queue_tail;
  if (g_message_queue_tail >= MESSAGE_QUEUE_LENGTH) {
    g_message_queue_tail = 0;
  }
  return MSG_SUCCESS;
}

msg_status_e dequeueMessage(msg_e *msg, uint32_t *param1, uint32_t *param2) {
  if (g_message_queue_head == g_message_queue_tail) {
    return MSG_FAIL_EMPTY;
  }

  *msg = g_message_queue[g_message_queue_head].msg;
  *param1 = g_message_queue[g_message_queue_head].param1;
  *param2 = g_message_queue[g_message_queue_head].param2;
  ++g_message_queue_head;
  if (g_message_queue_head >= MESSAGE_QUEUE_LENGTH) {
    g_message_queue_head = 0;
  }
  return MSG_SUCCESS;
}

#ifdef __cplusplus
}
#endif