/* CS261- Assignment 3 - Part 1*/
/* Name: Christian Roccanova
* Date: 7/24/2017
* Solution description: Creates functions to implement a Linked List Deque and uses those functions to implement a bag
*/

#include "linkedList.h"
#include <assert.h>
#include <stdlib.h>
#include <stdio.h>

// Double link
struct Link
{
	TYPE value;
	struct Link* next;
	struct Link* prev;
};

// Double linked list with front and back sentinels
struct LinkedList
{
	int size;
	struct Link* frontSentinel;
	struct Link* backSentinel;
};

/**
* Allocates the list's sentinel and sets the size to 0.
* The sentinels' next and prev should point to eachother or NULL
* as appropriate.
*/
static void init(struct LinkedList* list) {
	// FIXME: you must write this
	//allocates sentinels
	list->frontSentinel = malloc(sizeof(struct Link));
	assert(list->frontSentinel != 0);

	list->backSentinel = malloc(sizeof(struct Link));
	assert(list->backSentinel !=0);

	//points front and back sentinels to eachother
	list->frontSentinel->next = list->backSentinel;	
	list->backSentinel->prev = list->frontSentinel;
	
	//initial size set to 0
	list->size = 0;

}

/**
* Adds a new link with the given value before the given link and
* increments the list's size.
*/
static void addLinkBefore(struct LinkedList* list, struct Link* link, TYPE value)
{
	// FIXME: you must write this

	//creates new link
	struct Link *temp = (struct Link *) malloc(sizeof(struct Link));
	
	//inserts new link into the list having it become the prev of the current link and the next of that link's prev
	temp->value = value;
	temp->next = link;
	temp->prev = link->prev;
	link->prev->next = temp;
	link->prev = temp;

	//increases list size
	list->size++;
	
}

/**
* Removes the given link from the list and
* decrements the list's size.
*/
static void removeLink(struct LinkedList* list, struct Link* link)
{
	// FIXME: you must write this
	assert(list != 0);
	assert(link != 0);
	assert(linkedListIsEmpty(list) != 1);

	//removes link by having its prev point to its next and vice versa
	link->prev->next = link->next;
	link->next->prev = link->prev;

	//decreases list size
	list->size--;

	free(link);
}

/**
* Allocates and initializes a list.
*/
struct LinkedList* linkedListCreate()
{
	struct LinkedList* newDeque = malloc(sizeof(struct LinkedList));
	init(newDeque);
	return newDeque;
}

/**
* Deallocates every link in the list including the sentinels,
* and frees the list itself.
*/
void linkedListDestroy(struct LinkedList* list)
{
	while (!linkedListIsEmpty(list))
	{
		linkedListRemoveFront(list);
	}
	free(list->frontSentinel);
	free(list->backSentinel);
	free(list);
}

/**
* Adds a new link with the given value to the front of the deque.
*/
void linkedListAddFront(struct LinkedList* list, TYPE value)
{
	// FIXME: you must write this
	//adds a link to the front (after the front sentinel)
	addLinkBefore(list, list->frontSentinel->next, value);
}

/**
* Adds a new link with the given value to the back of the deque.
*/
void linkedListAddBack(struct LinkedList* list, TYPE value)
{
	// FIXME: you must write this
	//adds a link to the back (before the back sentinel)
	addLinkBefore(list, list->backSentinel, value);
}

/**
* Returns the value of the link at the front of the deque.
*/
TYPE linkedListFront(struct LinkedList* list)
{
	// FIXME: you must write this

	//makes sure list is not empty
	assert(linkedListIsEmpty(list) != 1);

	//returns value of the first link
	return list->frontSentinel->next->value;
}

/**
* Returns the value of the link at the back of the deque.
*/
TYPE linkedListBack(struct LinkedList* list)
{
	// FIXME: you must write this
	assert(linkedListIsEmpty(list) != 1);

	//returns value of the last link
	return list->backSentinel->prev->value;
}

/**
* Removes the link at the front of the deque.
*/
void linkedListRemoveFront(struct LinkedList* list)
{
	// FIXME: you must write this
	assert(linkedListIsEmpty(list) != 1);

	//calls remove link to delete the first link
	removeLink(list, list->frontSentinel->next);
}

/**
* Removes the link at the back of the deque.
*/
void linkedListRemoveBack(struct LinkedList* list)
{
	// FIXME: you must write this
	assert(linkedListIsEmpty(list) != 1);

	//calls remove link to delete the back link
	removeLink(list, list->backSentinel->prev);
}

/**
* Returns 1 if the deque is empty and 0 otherwise.
*/
int linkedListIsEmpty(struct LinkedList* list)
{
	// FIXME: you must write this

	//returns 1 (true) if the list is empty (size == 0)
	if (list->size == 0)
	{
		return 1;
	}

	return 0;
}

/**
* Prints the values of the links in the deque from front to back.
*/
void linkedListPrint(struct LinkedList* list)
{
	// FIXME: you must write this
	assert(linkedListIsEmpty(list) != 1);
	struct Link *current;

	//sets current to the first link
	current = list->frontSentinel->next;

	//cycles through links, printing the value of each
	while (current != list->backSentinel)
	{		
		printf("%d \n", current->value);

		//advances link
		current = current->next;
	}

}

/**
* Adds a link with the given value to the bag.
*/
void linkedListAdd(struct LinkedList* list, TYPE value)
{
	// FIXME: you must write this
	// adds a link to the front of the bag
	addLinkBefore(list, list->frontSentinel->next, value);
}

/**
* Returns 1 if a link with the value is in the bag and 0 otherwise.
*/
int linkedListContains(struct LinkedList* list, TYPE value)
{
	// FIXME: you must write this
	assert(linkedListIsEmpty(list) != 1);

	struct Link *temp;

	//sets temp to first link
	temp = list->frontSentinel->next;

	//cycles through links, returning 1 if a matching value is found
	while (temp->next != list->backSentinel)
	{
		//returns 1 (true) if a match is found
		if (temp->value == value)
		{
			return 1;
		}
		// advances link
		temp = temp->next;
	}

	return 0;

}

/**
* Removes the first occurrence of a link with the given value.
*/
void linkedListRemove(struct LinkedList* list, TYPE value)
{
	// FIXME: you must write this
	assert(linkedListIsEmpty(list) != 1);

	struct Link *temp;
	//int contains = 0;

	//sets temp to first link
	temp = list->frontSentinel->next;

	//cycles through links to find a match
	while (temp != list->backSentinel)
	{
		//sets contains to 1 (true) if a match is found
		if (temp->value == value)
		{
			temp = temp->next;
			removeLink(list, temp->prev);
					
		}

		// advances link
		temp = temp->next;
	}

	free(temp);

}
