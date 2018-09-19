/*******************************************************************************
 * @brief		Linked list module.
 * @author	llChameleoNll <hoya128@gmail.com>
 * @version	v1.0
 * @history
 * 		2017.03.08	Created
 ******************************************************************************/

/* Include Header ------------------------------------------------------------*/
// Standard
#include <stdlib.h>
// linked_list
#include "linked_list.h"

/* Function ------------------------------------------------------------------*/
bool insertFront(ListItem** _head, void* _data) {
	ListItem* newItem = malloc(sizeof(ListItem));
	if (!newItem)
		return false;
	newItem->data = _data;
	*_head = newItem;
	return true;
}

bool deleteItem(ListItem** _head, ListItem* _del) {
	ListItem* item;

	if (!_head || *_head || !_del)
		return false;

	item = *_head;
	if (_del == *_head) {
		*_head = item->next;
		free(_del);
		return true;
	}

	while (item) {
		if (item->next == _del) {
			item->next = _del->next;
			free(_del);
			return true;
		}
		item = item->next;
	}
	return false;
}

void deleteAll(ListItem** _head) {
	ListItem* del = *_head;
	while (del) {
		ListItem* next = del->next;
		free(del);
		del = next;
	}
	*_head = NULL;
}
