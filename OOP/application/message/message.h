/*******************************************************************************
 * @brief			Message processing.
 * @author		llHoYall <hoya128@gmail.com>
 * @version		v0.0.5
 * @note
 * 	- 2018.05.14	Created.
 ******************************************************************************/

#ifndef __HoYa_MESSAGE_H__
#define __HoYa_MESSAGE_H__

/* Include Headers -----------------------------------------------------------*/
// Standard
#include <stdint.h>

/* Enumerations --------------------------------------------------------------*/
// Status
typedef enum {
	MSG_SUCCESS = 0,
	MSG_FAIL_EMPTY = -1,
} msg_status_e;

// Message
typedef enum {
	MSG_NONE = 0,
	MSG_ACCEL_PEDAL,
	MSG_BRAKE_PEDAL,
	MSG_MAX_COUNT
} msg_e;

/* API Prototypes ------------------------------------------------------------*/
extern msg_status_e clearMessage(void);
extern msg_status_e enqueueMessage(msg_e msg, uint32_t param1, uint32_t param2);
extern msg_status_e dequeueMessage(msg_e *msg, uint32_t *param1, uint32_t *param2);

#endif
