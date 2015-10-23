#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include "myfunctions.h"

int main()
{
	char command;
	bool loopCon = true;
	
	char resultString[50] = { 0 };
	char searchString[50];
	char myString[50]= "Let us have some fun with strings!\n";


	printf("%s", myString);
	
	


	do {
		loopCon = true;

		printf("\nSelect one of the following commands:\n");
		printf("1 - Extract a substring\n");
		printf("2 - Find the location of a word in the string\n");
		printf("3 - Remove characters from the string\n");
		printf("4 - Insert a word into the string\n");
		printf("x - Exit the program\n");

		printf("Your command:");
		scanf(" %c", &command);

		switch (command)
		{
		case '1':
			; int start, length;
			printf("Enter your starting point:");
			scanf(" %i", &start);
			printf("Enter your desired substring length:");
			scanf(" %i", &length);
			printf("\n");

			subString(myString, start, length, resultString);
			puts(resultString);
			break;
		case '2':
			printf("\nEnter the word you'd like to find:");
			scanf(" %[^\n]s", searchString);
			int printIndex = findString(myString, searchString);
			printf("\nThe index position of your word is:%i", printIndex);
			printf("\n");
			break;
		case '3':
			break;
		case '4':
			break;
		case 'x':
			loopCon = false;
			printf("Thanks for playing!\n");
			break;
		default:
			if (loopCon != false)
			{
				printf("\nInvalid command. Try again.\n");
			}

		}
	} while (command != 'x');



	
	
	
	
	
	return 0;
}