/* CS261- Assignment 1 - Q.1*/
/* Name: Christian Roccanova
 * Date: 7/9/2017
 * Solution description: Generates an array of students containing both random id numbers and grades and prints it.  Then calculates the minimum, maximum and average scores.
 */
 
#include<stdio.h>
#include<stdlib.h>
#include<math.h>

struct student{
	int id;
	int score;
};

struct student* allocate(){
     /*Allocate memory for ten students*/
	struct student* studentPtr;
	studentPtr = (struct student*) malloc(10 * sizeof(struct student));
    
	/*return the pointer*/
	return studentPtr;
}

void generate(struct student* students){
     /*Generate random and unique ID and scores for ten students, ID being between 1 and 10, scores between 0 and 100*/
	int idNum;
	int grade;
	
	for (int i = 0; i < 10; i++)
	{
		/*Generates a random id number*/
		idNum = rand() % 10 + 1;
		
		/*Checks the generated id number against those already in the array and generates a new one if a match is found.*/
		for (int j = 0; j < 10; j++)
		{			
			if ((students + j)->id == idNum)
			{
				idNum = rand() % 10 + 1;
				j = -1;
				
			}
		}
		(students + i)->id = idNum;

		/*Generates a random grade.*/
		grade = rand() % 101;
		
		/*Checks the generated grade against those already in the array and generates a new one if a match is found.*/
		for (int k = 0; k < 10; k++)
		{
						
			if ((students + k)->score == grade)
			{
				grade = rand() % 101;
				k = -1;
				
			}
		}
		(students + i)->score = grade;
	}
	
	
}

void output(struct student* students){
     /*Output information about the ten students in the format:
              ID1 Score1
              ID2 score2
              ID3 score3
              ...
              ID10 score10*/

	for (int i = 0; i < 10; i++)
	{
		printf("ID# %d	Score: %d\n", (students + i)->id, (students + i)->score);
	}
}

void summary(struct student* students){
	int min = 100;
	int max = 0;
	int total = 0;
	int average;

	/*Compute and print the minimum, maximum and average scores of the ten students*/
     
	for (int i = 0; i < 10; i++)
	{

	/*Determines minimum*/
	
		if (min > (students + i)->score)
		{
			min = (students + i)->score;
		}
	
	/*Determines maximum*/

		if (max < (students + i)->score)
		{
			max = (students + i)->score;
		}
				
	/*sums scores*/
	
		total += (students + i)->score;
	}

	/*Computes the average score*/
	average = total / 10;

	/*prints the results*/
	printf("Minimum score: %d\n", min);
	printf("Maximum score: %d\n", max);
	printf("Average score: %d\n", average);
}

void deallocate(struct student* stud){
     /*Deallocate memory from stud*/
	free(stud);
}

int main(){
    struct student* stud = NULL;
    
    /*call allocate*/
	stud = allocate();
    /*call generate*/
	generate(stud);
    /*call output*/
	output(stud);
    /*call summary*/
	summary(stud);
    /*call deallocate*/
	deallocate(stud);
    return 0;
}
