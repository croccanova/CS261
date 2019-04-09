/*
 * CS 261 Assignment 5
 * Name: Christian Roccanova
 * Date: 8/5/2017
 */

#include "dynamicArray.h"
#include "task.h"
#include <stdlib.h>
#include <string.h>
#include <stdio.h>

/**
 * Loads into heap a list from a file with lines formatted like
 * "priority, name".
 * @param heap
 * @param file
 */
void listLoad(DynamicArray* heap, FILE* file)
{
    const int FORMAT_LENGTH = 256;
    char format[FORMAT_LENGTH];
    snprintf(format, FORMAT_LENGTH, "%%d, %%%d[^\n]", TASK_NAME_SIZE);
    
    Task temp;
    while (fscanf(file, format, &temp.priority, &temp.name) == 2)
    {
        dyHeapAdd(heap, taskNew(temp.priority, temp.name), taskCompare);
    }
}

/**
 * Writes to a file all tasks in heap with lines formatted like
 * "priority, name".
 * @param heap
 * @param file
 */
void listSave(DynamicArray* heap, FILE* file)
{
    for (int i = 0; i < dySize(heap); i++)
    {
        Task* task = dyGet(heap, i);
        fprintf(file, "%d, %s\n", task->priority, task->name);
    }
}

/**
 * Prints every task in heap.
 * @param heap
 */
void listPrint(DynamicArray* heap)
{
    DynamicArray* temp = dyNew(1);
    dyCopy(heap, temp);
     while (dySize(temp) > 0)
    {
        Task* task = dyHeapGetMin(temp);
        printf("\n");
        taskPrint(task);
        printf("\n");
        dyHeapRemoveMin(temp, taskCompare);
    }
    dyDelete(temp);
}

/**
 * Handles the given command.
 * @param list
 * @param command
 */
void handleCommand(DynamicArray* list, char command)
{
    // FIXME: Implement
	char* file = malloc(sizeof(char) * 256);
	char* description = malloc(sizeof(char) * 256);
	int priority;

	//switch implements the main menu based on character input
	switch (command)
	{
		// loads a file, asks for file name
		case 'l':
			//prompts user for file name
			printf("Please enter the name of the file to be loaded.\n");
			fgets(file, 200, stdin);
			
			//loads data from file if it exists
			FILE* readFile = fopen(file, "r");
			if (readFile != NULL)
			{
				listLoad(list, readFile);
				printf("Load successful. \n");
				fclose(readFile);
			}
			//if file does not exist, prints that it was not found
			else
			{
				printf("File not found.\n");
			}
			break;

		// saves to a file, asks for file name
		case 's':

			//prompts user for file name
			printf("Please enter the name of the file to be saved.\n");
			fgets(file, 200, stdin);
			
			//writes data to a file 
			FILE* writeFile = fopen(file, "w+");
			listSave(list, writeFile);
			printf("Save successful. \n");
			fclose(writeFile);
			break;

		// adds a new task, asks for a descriptin and priority
		case 'a':
			
			//gets description
			printf("Please enter the description of your task.\n");			
			fgets(description, 200, stdin);
			
			//gets priority
			printf("Please enter the priority of your task as an integer.\n");
			scanf("%d", &priority);

			//creates a new task and adds it to the heap
			Task* newTask = taskNew(priority, description);
			dyHeapAdd(list, newTask, taskCompare);
			printf("Task successfully added.\n");
						
			break;

		case 'g':

			//if list is empty prints that it is so
			if (dySize(list) == 0)
			{
				printf("Sorry, your list is empty. \n");
			}
			//if list is not empty, prints first item
			else
			{
				printf("The first task on your list is: %s\n");
			}

			break;

		case 'r':

			//if list is empty prints that it is so
			if (dySize(list) == 0)
			{
				printf("Sorry, your list is empty. \n");
			}

			//if list is not empty, removes first item
			else
			{
				struct Task* firstTask = (struct Task*)dyHeapGetMin(list);
				dyHeapRemoveMin(list, taskCompare);
				taskDelete(firstTask);
				printf("The first task has been removed.\n");
			}

			break;

		case 'p':

			//if list is empty prints that it is so
			if (dySize(list) == 0)
			{
				printf("Sorry, your list is empty. \n");
			}

			//if list is not empty, prints list
			else
			{
				listPrint(list);
			}

			break;

		case 'e':
			//exits program
			break;
	}

}

int main()
{
    // Implement
    printf("\n\n** TO-DO LIST APPLICATION **\n\n");
    DynamicArray* list = dyNew(8);
    char command = ' ';
    do
    {
        printf("Press:\n"
               "'l' to load to-do list from a file\n"
               "'s' to save to-do list to a file\n"
               "'a' to add a new task\n"
               "'g' to get the first task\n"
               "'r' to remove the first task\n"
               "'p' to print the list\n"
               "'e' to exit the program\n"
        );
        command = getchar();
        // Eat newlines
        while (getchar() != '\n');
        handleCommand(list, command);
    }
    while (command != 'e');
 /* free dynamically allocated List pointers in array to avoid memory leaks */
         /* Fix it */
	for (int i = 0; i < dySize(list); i++)
	{
		Task* t = dyGet(list, i);
		taskDelete(t);
	}
    dyDelete(list);
    return 0;
}