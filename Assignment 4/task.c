/*
 * CS 261 Assignment 5
 * Name: Christian Roccanova
 * Date: 8/5/2017
 */

#include "task.h"
#include <stdlib.h>
#include <string.h>
#include <stdio.h>

/**
 * Creates a new task with the given priority and name.
 * @param priority
 * @param name
 * @return  The new task.
 */
Task* taskNew(int priority, char* name)
{
    // FIXME: implement
	struct Task* newTask = malloc(sizeof(Task));
	strcpy(newTask->name, name);
	newTask->priority = priority;

    return newTask;
}

/**
 * Frees a dynamically allocated task.
 * @param task
 */
void taskDelete(Task* task)
{
    free(task);
}

/**
 * Casts left and right to Task pointers and returns
 * -1 if left's priority < right's priority,
 *  1 if left's priority > right's priority,
 *  0 if left's priority == right's priority.
 * @param left  Task pointer.
 * @param right  Task pointer.
 * @return 
 */
int taskCompare(void* left, void* right)
{
	
		// FIXME: implement
		struct Task* lft = left;
		struct Task* rght = right;

		int value = 0;

		//returns -1 if left has higher priority than right (lower number = higher priority)
		if (lft->priority < rght->priority)
		{
			value = -1;
		}
		//returns 1 if right has higher priority than left (lower number = higher priority)
		else if (lft->priority > rght->priority)
		{
			value = 1;
		}

		return value;
	
}


/**
 * Prints a task as a (priority, name) pair.
 * @param value  Task pointer.
 */
void taskPrint(void* value)
{
    struct Task* task = value;
    printf("(%d, %s)", task->priority, task->name);
}
