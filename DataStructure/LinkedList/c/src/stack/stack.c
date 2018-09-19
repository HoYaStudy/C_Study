/*******************************************************************************
 * @brief		Stack module using linked list.
 * @author	llChameleoNll <hoya128@gmail.com>
 * @version	v1.0
 * @history
 * 		2017.03.08	Created
 ******************************************************************************/

/* Include Header ------------------------------------------------------------*/
// Standard
#include <Stdlib.h>
#include <stdio.h>
// stack
#include "../../inc/stack/stack.h"

/* Private Function Prototype ------------------------------------------------*/
void displayIntStack(void* _data);
void displayDoubleStack(void* _data);

/* Function ------------------------------------------------------------------*/
bool pushStack(Stack* _stack, void* _data) {
	ListItem* newItem = (ListItem*)malloc(sizeof(ListItem));
	if (!newItem)
		return false;

	newItem->next = _stack->top;
	newItem->data = _data;
	_stack->top = newItem;
	++_stack->count;

	return true;
}

bool popStack(Stack* _stack) {
	if (!_stack->top)
		return false;

	ListItem* delItem = _stack->top;
	_stack->top = delItem->next;
	--_stack->count;

	return true;
}

void displayStack(Stack _stack, uint8_t _mode) {
	ListItem* item = _stack.top;

	printf("[   Stack   ]\n");
	while (item) {
		printf("[   ");
		switch (_mode) {
			case 0:
				displayIntStack(item->data);
				break;

			case 1:
				displayDoubleStack(item->data);
				break;
		}
		printf("   ]\n");
		item = item->next;
	}
	printf("\n");
}

/* Private Function ----------------------------------------------------------*/
void displayIntStack(void* _data) {
	printf("%5d", *(int*)_data);
}

void displayDoubleStack(void* _data) {
	printf("%5.1f", *(double*)_data);
}
