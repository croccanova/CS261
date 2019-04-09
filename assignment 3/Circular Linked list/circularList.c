/* CS261- Assignment 3 - Part 2*/
/* Name: Christian Roccanova
* Date: 7/24/2017
* Solution description: Creates functions to implement a Circular Linked List
*/

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include "circularList.h"

// Double link
struct Link
{
	TYPE value;
	struct Link * next;
	struct Link * prev;
};

struct CircularList
{
	int size;
	struct Link* sentinel;
};

/**
 * Allocates the list's sentinel and sets the size to 0.
 * The sentinel's next and prev should point to the sentinel itself.
 */
static void init(struct CircularList* list)
{
	// FIXME: you must write this
		
	list->size = 0;

	//allocates memory for the sentinel
	list->sentinel = (struct Link*)malloc(sizeof(struct Link));
	
	//makes sentinel next and prev point to itself
	list->sentinel->next = list->sentinel;
	list->sentinel->prev = list->sentinel;

}

/**
 * Creates a link with the given value and NULL next and prev pointers.
 */
static struct Link* createLink(TYPE value)
{
	// FIXME: you must write this

	//allocates memory for the new link
	struct Link* newLink = (struct Link*)malloc(sizeof(struct Link));
	newLink->value = value;

	return newLink;

}

/**
 * Adds a new link with the given value after the given link and
 * increments the list's size.
 */
static void addLinkAfter(struct CircularList* list, struct Link* link, TYPE value)
{
	// FIXME: you must write this
	//creates the new link
	struct Link* newLink = createLink(value);

	//sets pointers such that the new link is the next of the old link and the prev of that link's old next	
	link->next->prev = newLink;
	newLink->next = link->next;
	link->next = newLink;
	newLink->prev = link;
			
	//increases list size
	list->size++;
}

/**
 * Removes the given link from the list and
 * decrements the list's size.
 */
static void removeLink(struct CircularList* list, struct Link* link)
{
	// FIXME: you must write this
	assert(circularListIsEmpty(list) != 1);

	//makes previous link point to next link and vice versa
	link->prev->next = link->next;
	link->next->prev = link->prev;	

	//frees individual link memory
	free(link);
	
	//decreases list size
	list->size--;
}

/**
 * Allocates and initializes a list.
 */
struct CircularList* circularListCreate()
{
	struct CircularList* list = malloc(sizeof(struct CircularList));
	init(list);
	return list;
}

/**
 * Deallocates every link in the list and frees the list pointer.
 */
void circularListDestroy(struct CircularList* list)
{
	// FIXME: you must write this
	assert(circularListIsEmpty(list) != 1);
	//cycles through links while the list is not empty and deletes individual links
	while (circularListIsEmpty(list) != 1)
	{
		//memory for individual links is freed in the removeLink function
		circularListRemoveFront(list);
	}
	free(list->sentinel);
	free(list);
}

/**
 * Adds a new link with the given value to the front of the deque.
 */
void circularListAddFront(struct CircularList* list, TYPE value)
{
	// FIXME: you must write this

	addLinkAfter(list, list->sentinel, value);
}

/**
 * Adds a new link with the given value to the back of the deque.
 */
void circularListAddBack(struct CircularList* list, TYPE value)
{
	// FIXME: you must write this
	
	addLinkAfter(list, list->sentinel->prev, value);
}

/**
 * Returns the value of the link at the front of the deque.
 */
TYPE circularListFront(struct CircularList* list)
{
	// FIXME: you must write this
	assert(circularListIsEmpty(list) != 1);
	
	//returns value of first link (next link after sentinel)
	return list->sentinel->next->value;
		
}

/**
 * Returns the value of the link at the back of the deque.
 */
TYPE circularListBack(struct CircularList* list)
{
	// FIXME: you must write this
	assert(circularListIsEmpty(list) != 1);

	//returns value of the back link (link previous to sentinel)
	return list->sentinel->prev->value;
	
}

/**
 * Removes the link at the front of the deque.
 */
void circularListRemoveFront(struct CircularList* list)
{
	// FIXME: you must write this
	assert(circularListIsEmpty(list) != 1);

	//deletes the front link
	removeLink(list, list->sentinel->next);
}

/**
 * Removes the link at the back of the deque.
 */
void circularListRemoveBack(struct CircularList* list)
{
	// FIXME: you must write this
	assert(circularListIsEmpty(list) != 1);

	//deletes the back link
	removeLink(list, list->sentinel->prev);
}

/**
 * Returns 1 if the deque is empty and 0 otherwise.
 */
int circularListIsEmpty(struct CircularList* list)
{
	// FIXME: you must write this
	//returns 1 if empty, else returns 0
	if (list->size == 0)
	{
		return 1;
	}

	return 0;
}

/**
 * Prints the values of the links in the deque from front to back.
 */
void circularListPrint(struct CircularList* list)
{
	// FIXME: you must write this
	assert(circularListIsEmpty(list) != 1);

	struct Link* temp;
	temp = list->sentinel->next;

	//prints the values in the list until it gets back to the sentinel
	while (temp != list->sentinel)
	{
		printf("%f \n", temp->value);
		temp = temp->next;
	}
		
}

/**
 * Reverses the deque.
 */
void circularListReverse(struct CircularList* list)
{
	// FIXME: you must write this
	assert(circularListIsEmpty(list) != 1);
	struct Link* temp;
	struct Link* index;

	//swaps first and last links
	
	index = list->sentinel->next;
	
	//flips the sentinel prev
	list->sentinel->prev = index;
		
	//reverses the remaining links
	while (index != list->sentinel)
	{
		//advances link
		temp = index->next;

		//flips the sentinel next
		if (temp->next == list->sentinel)
		{
			list->sentinel->next = temp;
		}

		//flips the next and prev of index
		index->next = index->prev;
		index->prev = temp;
		index = temp;
	}
		
}
