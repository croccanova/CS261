/* CS261- Assignment 1 - Q.5*/
/* Name: Christian Roccanova
 * Date: 7/9/2017
 * Solution description: Takes a user input word, alternates the capitalization and prints it.
 */
 
#include <stdio.h>
#include <stdlib.h>

/*converts ch to upper case, assuming it is in lower case currently*/
char toUpperCase(char ch){
     return ch-'a'+'A';
}

/*converts ch to lower case, assuming it is in upper case currently*/
char toLowerCase(char ch){
     return ch-'A'+'a';
}

void sticky(char* word){
     /*obtains word length*/
	int length = 0;
	while (*(word + length))
	{
		length++;
	}

	/*Convert to sticky caps*/
	for (int i = 0; i < length; i++)
	{
		/*Checks if a number is even and if so, makes it lowercase*/
		if (i % 2 != 0)
		{
			/*First checks if the character is already lowercase*/
			if (*(word + i) <= 'Z' && *(word + i) >= 'A')
			{
				*(word + i) = toLowerCase(*(word + i));
			}
		}
		/*Capitalizes a character if it is not even*/
		else
		{
			/*First checks if the character is already uppercase*/
			if (*(word + i) <= 'z' && *(word + i) >= 'a')
			{
				*(word + i) = toUpperCase(*(word + i));
			}
		}
	}

}

int main(){
    /*Read word from the keyboard using scanf*/
	char myWord[100];
	printf("Please enter a word.\n");
	scanf("%s", myWord);

    /*Call sticky*/
	sticky(myWord);

    /*Print the new word*/
	printf("%s\n", myWord);

    return 0;
}
