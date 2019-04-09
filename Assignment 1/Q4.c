/* CS261- Assignment 1 - Q.4*/
/* Name: Christian Roccanova
 * Date: 7/9/2017
 * Solution description: Generates an array of students containing both random id numbers and grades and prints it.  Then takes that array, sorts it by grade and prints it.
 */
 
#include <stdio.h>
#include<stdlib.h>
#include<math.h>

struct student{
	int id;
	int score;
};

void sort(struct student* students, int n)
{
     /*Sort the n students based on their score*/ 
	int lowScore;
	int lowId;
	int tempScore;
	int tempId;
	int position;

	for (int i = 0; i < n; i++)
	{
		tempScore = (students + i)->score;
		tempId = (students + i)->id;
		lowScore = tempScore;

		/*Checks if there are lower grades in the array*/
		for (int j = i; j < n; j++)
		{
			if (lowScore > (students + j)->score)
			{
				lowScore = (students + j)->score;
				lowId = (students + j)->id;
				position = j;
			}
		}

		/*Swaps values if a lower one has been found*/
		if (tempScore > lowScore)
		{
			(students + i)->score = lowScore;
			(students + position)->score = tempScore;
			(students + i)->id = lowId;
			(students + position)->id = tempId;
		}
	}
}

int main(){
    /*Declare an integer n and assign it a value.*/
	int n = 10;

    /*Allocate memory for n students using malloc.*/
	struct student* studentPtr;
	studentPtr = (struct student*) malloc(10 * sizeof(struct student));

    /*Generate random and unique IDs and random scores for the n students, using rand().*/
	int idNum;
	int grade;

	for (int i = 0; i < 10; i++)
	{
		/*Generates a random id number*/
		idNum = rand() % 10 + 1;
		
		/*Checks the generated id number against those already in the array and generates a new one if a match is found.*/
		for (int j = 0; j < 10; j++)
		{			
			if ((studentPtr + j)->id == idNum)
			{
				idNum = rand() % 10 + 1;
				j = -1;
			}
		}
		(studentPtr + i)->id = idNum;

		/*Generates a random grade.*/
		grade = rand() % 101;

		/*Checks the generated grade against those already in the array and generates a new one if a match is found.*/
		for (int k = 0; k < 10; k++)
		{
			if ((studentPtr + k)->score == grade)
			{
				grade = rand() % 101;
				k = -1;
			}
		}
		(studentPtr + i)->score = grade;
	}
    /*Print the contents of the array of n students.*/
	for (int i = 0; i < 10; i++)
	{
		printf("ID# %d	Score: %d\n", (studentPtr + i)->id, (studentPtr + i)->score);
	}

    /*Pass this array along with n to the sort() function*/
	sort(studentPtr, n);

    /*Print the contents of the array of n students.*/
	
	printf("The students sorted by grade are:\n");
	for (int i = 0; i < 10; i++)
	{		
		printf("ID# %d	Score: %d\n", (studentPtr + i)->id, (studentPtr + i)->score);
	}
    
    return 0;
}
