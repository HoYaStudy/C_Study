/*******************************************************************************
 * @brief		Linked list module.
 * @author	llChameleoNll <hoya128@gmail.com>
 * @version	v1.0
 * @history
 * 		2017.03.08	Created
 ******************************************************************************/

#ifndef __LINKED_LIST_H__
#define __LINKED_LIST_H__

/* Include Header ------------------------------------------------------------*/
#include <stdbool.h>

/* Structure -----------------------------------------------------------------*/
typedef struct _ListItem {
	struct _ListItem*	next;
	void*	data;
} ListItem;

/* Function Prototype --------------------------------------------------------*/
bool insertFront(ListItem** _head, void* _data);
bool deleteItem(ListItem** _head, ListItem* _del);
void deleteAll(ListItem** _head);

#endif
