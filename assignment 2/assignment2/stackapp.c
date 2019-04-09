/* CS261- Assignment 2 - Part 3*/
/* Name: Christian Roccanova
* Date: 7/17/2017
* Solution description: Checks if the brackets (), {}, [] are balanced in a string by placing open brackets into a stack and comparing closed brackets to the top.
*/

/*	stack.c: Stack application. */
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include "dynArray.h"


/* ***************************************************************
Using stack to check for unbalanced parentheses.
***************************************************************** */

/* Returns the next character of the string, once reaches end return '0' (zero)
param: 	s pointer to a string
pre: s is not null
*/
char nextChar(char* s)
{
	static int i = -1;
	char c;
	++i;
	c = *(s + i);
	if (c == '\0')
		return '\0';
	else
		return c;
}

/* Checks whether the (), {}, and [] are balanced or not
param: 	s pointer to a string
pre: s is not null
post:
*/
int isBalanced(char* s)
{
	/* FIXME: You will write this function */
	assert(s != NULL);
	
	struct DynArr
	{
		TYPE* data;
		int size;
		int capacity;
	};

	DynArr* bracket = newDynArr(100);
	char c;
	
	//loops while there are still characters in the string
	while (nextChar(s) != 0)
	{
		c = nextChar(s);
		switch (c)
		{
			//open brackets are pushed onto the stack
			case '[':
				pushDynArr(bracket, c);
				break;
			case '{':
				pushDynArr(bracket, c);
				break;
			case '(':
				pushDynArr(bracket, c);
				break;

			//close brackets are compared to the top character.  If they do not match, returns 0 (not balanced).
			//If they do match, pops that character off the stack so the next one may be compared to the next character.
			case ']':
				if (topDynArr(bracket) == '[')
				{
					popDynArr(bracket);
					break;
				}
				return 0;

			case '}':
				if (topDynArr(bracket) == '{')
				{
					popDynArr(bracket);
					break;
				}
				return 0;

			case ')':
				if (topDynArr(bracket) == '(')
				{
					popDynArr(bracket);
					break;
				}
				return 0;
		}

	}
	
	deleteDynArr(bracket);	//free memory
	return 1;
}

int main(int argc, char* argv[]) {

	char* s = argv[1];
	int res;

	printf("Assignment 2\n");

	res = isBalanced(s);

	if (res)
		printf("The string %s is balanced\n", s);
	else
		printf("The string %s is not balanced\n", s);

	return 0;
}

