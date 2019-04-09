/* CS261- Assignment 1 - Q.3*/
/* Name: Christian Roccanova
 * Date: 7/9/2017
 * Solution description: Generates an array of n random numbers and prints it.  Then takes that array, sorts it and prints it.
 */
 
#include <stdio.h>
#include<stdlib.h>
#include<math.h>


void sort(int* number, int n){
     /*Sort the given array number , of length n*/     
	int low;
	int temp;
	int position;

	for (int i = 0; i < n; i++)
	{
		low = *(number + i);
		temp = low;

		/*Checks if there are lower values in the array*/
		for (int j = i; j < n; j++)
		{
			if (low > *(number + j))
			{
				low = *(number + j);
				position = j;
			}
		}

		/*Swaps values if a lower one has been found*/
		if (temp > low)
		{
			*(number + i) = low;
			*(number + position) = temp;
		}
	}
}

int main(){
    /*Declare an integer n and assign it a value of 20.*/
	int n = 20;

    /*Allocate memory for an array of n integers using malloc.*/
	int* arr = (int*)malloc(n * sizeof(int));

    /*Fill this array with random numbers, using rand().*/
	for (int i = 0; i < n; i++)
	{
		*(arr + i) = rand() % 100 + 1;
	}

    /*Print the contents of the array.*/
	printf("Original array:\n");
	for (int i = 0; i < n; i++)
	{
		printf("%d\n", *(arr + i));
	}

    /*Pass this array along with n to the sort() function of part a.*/
	sort(arr, n);

    /*Print the contents of the array.*/    
	printf("Sorted array:\n");
	for (int i = 0; i < n; i++)
	{
		printf("%d\n", *(arr + i));
	}

    return 0;
}
