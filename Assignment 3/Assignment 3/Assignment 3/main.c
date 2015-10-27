//include libraries
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include "myfunctions.h"

int main()
{
	//declare variables
	char command;
	int start, length;
	bool loopCon = true;
	//and arrays to store strings
	char resultString[50];
	char searchString[50];
	char myString[50]= "Let us have some fun with strings!\0";

	//print string
	printf("%s", myString);
	printf("\n");;
	
	


	do {
		loopCon = true;

		printf("\nSelect one of the following commands:\n");
		printf("1 - Extract a substring\n");
		printf("2 - Find the location of a word in the string\n");
		printf("3 - Remove characters from the string\n");
		printf("4 - Insert a word into the string\n");
		printf("x - Exit the program\n");


		//collect user input
		printf("Your command:");
		scanf(" %c", &command);

		//switch command based on user input
		switch (command)
		{
		case '1':
			//get starting point and length of the substring to extract
			printf("Enter your starting point:");
			scanf(" %i", &start);
			printf("Enter your desired substring length:");
			scanf(" %i", &length);
			printf("\n");

			//put those numbers in function and return the resulting substring
			subString(myString, start, length, resultString);
			puts(resultString);
			break;

		case '2':
			//get word to locate
			printf("\nEnter the word you'd like to find:");
			scanf(" %[^\n]s", searchString);

			//set variable for the int the function will return
			int printIndex = findString(myString, searchString);

			//print the number returned
			printf("\nThe index position of your word is:%i", printIndex);
			printf("\n");
			break;
		case '3':
			printf("Enter your starting point:");
			scanf(" %i", &start);
			printf("Enter the length of characters to remove:");
			scanf(" %i", &length);
			printf("\n");

			/*removeString(myString, resultString, start, length);
			puts(myString);*/
			removeString(myString, start, length);
			puts(myString);
			break;
		case '4':
			printf("\nEnter the word you'd like to insert:");
			scanf(" %[^\n]s", searchString);
			printf("Enter the starting point of insertion:");
			scanf(" %i", &start);

			insertString(myString, searchString, start);
			puts(myString);
			break;
		case 'x':
			//end the loop, print thank you text
			loopCon = false;
			printf("Thanks for playing!\n");
			break;
		default:
			//print invalid message only if loop hasn't ended
			if (loopCon != false)
			{
				printf("\nInvalid command. Try again.\n");
			}

		}
	} while (command != 'x');



	
	
	
	
	
	return 0;
}