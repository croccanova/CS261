/* CS261- Assignment 1 - Q. 0*/
/* Name: Christian Roccanova
 * Date: 7/9/2017
 * Solution description: Prints the value of x, its memory address and the address of a pointer to x.
 */
 
#include <stdio.h>
#include <stdlib.h>

void fooA(int* iptr){
     /*Print the value pointed to by iptr*/
	printf("The value stored in iptr is: %d\n", *iptr);
     /*Print the address pointed to by iptr*/
	printf("The address stored in iptr is: %p\n", iptr);
     /*Print the address of iptr itself*/
	printf("The address of iptr is: %p\n", *iptr);
}

int main(){
    
    /*declare an integer x*/
	int x = 5;
    /*print the address of x*/
	printf("The address of x is: %p\n", &x);
    /*Call fooA() with the address of x*/
	fooA(&x);
    /*print the value of x*/
	printf("x = %d\n", x);
    return 0;
}
