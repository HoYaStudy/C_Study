/*******************************************************************************
 * @brief		Stack module using linked list.
 * @author	llChameleoNll <hoya128@gmail.com>
 * @version	v1.0
 * @history
 * 		2017.03.08	Created
 ******************************************************************************/

#ifndef __STACK_H__
#define __STACK_H__

/* Include Header ------------------------------------------------------------*/
#include <stdbool.h>
#include "../../inc/linked_list/linked_list.h"

/* Macro Function ------------------------------------------------------------*/
#define createStack(_stack)		Stack _stack;	\
	_stack.top = NULL;	\
	_stack.count = 0;

/* Structure -----------------------------------------------------------------*/
typedef struct _Stack {
	ListItem* top;
	int	count;
} Stack;

/* Function Prototype --------------------------------------------------------*/
bool pushStack(Stack* _stack, void* _data);
bool popStack(Stack* _stack);
void displayStack(Stack _stack, uint8_t _mode);

#endif
