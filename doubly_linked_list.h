/**
 *  @file /IntercomPlus/app/inc/doubly_linked_list.h
 *  @brief 
 *  @author Kacper Kowalski - kacper.kowalski@novamedia.pl
 */
#ifndef APP_INC_DOUBLY_LINKED_LIST_H_
#define APP_INC_DOUBLY_LINKED_LIST_H_

#ifdef __FREERTOS__
#define alloc_mem		pvPortMalloc
#define free_mem		vPortFree
#else
#define alloc_mem		malloc
#define free_mem		free
#endif

#include <stdio.h>

#define for_each_in_dl_list(T, element, list) for(struct dll_node *n = list.head; n; n = n->next) \
													for(T *element = n->elem; element; element = NULL)

struct dll_node
{
	struct dll_node *next, *prev;
	void *elem;
};

struct doubly_linked_list
{
	struct dll_node *head, *tail;
	size_t elem_size;
};

/**
 *  @brief Initialize list pointers with NULL values and initialize size of an element held by a node
 *
 *  This is obligatory to firstly call this function before calling any other functions which operates on a list.
 */
void dl_list_init(struct doubly_linked_list *l, size_t elem_size);

struct dll_node * dl_list_insert_at_tail(struct doubly_linked_list *l, void *elem);
void dl_list_remove_node(struct doubly_linked_list *l, struct dll_node *n);
void dl_list_delete(struct doubly_linked_list *l);

#endif /* APP_INC_DOUBLY_LINKED_LIST_H_ */
