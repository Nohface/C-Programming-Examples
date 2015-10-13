//Noah Armsworthy
//Assignment 2
//CETN

#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdbool.h>
#include "myfunctions.h"


int main()
{
	//assigning variables
	
	int numbers[5];
	int size = sizeof(numbers) / sizeof(int);
	int total = 0;
	int i = 0;
	float averageNumber;
	float sum;
	char command;
	bool loopCon = true;
	
	//welcome message
	printf("WELCOME TO FUN WITH FIVE NUMBERS!\n");


	//collect numbers, put in array
	for (i = 0; i < size; i++)
	{
		printf("Enter number %i: ", i + 1);
		scanf(" %i", &numbers[i]);
	}

	//repeat numbers in the array

	PrintNumbers(numbers, size);

	//do while x is not typed
	do {

		loopCon = true;

		//print options to user
		printf("Select one of the following commands (type x to finish):\n");
		printf("1 - Show the average of the numbers\n");
		printf("2 - Sort the numbers from smallest to largest\n");
		printf("3 - Show the sum of the numbers\n");
		printf("4 - Show the sum in 32-bit binary form\n");
		printf("5 - Change the five numbers\n");
		printf("x - End Program\n");

		printf("Your command: ");
		scanf(" %c", &command);

		
		switch (command)
		{
		case '1'://average number
			averageNumber = GetAverage(numbers, size);
			printf("The average of your numbers is %.1f \n\n", averageNumber);
			break;
			
		case '2'://acending order
			SortedNumbers(numbers, size);
			PrintNumbers(numbers, size);
			break;

		case '3'://sum of numbers
			sum = GetSum(numbers, size);
			printf("The sum of your numbers is %.1f \n\n", sum);
			break;
		
		case '4'://sum in binary
			printf("The sum of yours numbers in binary form is: ");
			PrintSumAsBinary(numbers, size);
			printf("\n\n");
			break;
		
		case '5'://new numbers
			for (i = 0; i < size; i++)
			{
				printf("Enter number %i: ", i + 1);
				scanf(" %i", &numbers[i]);
			}
			
			//repeat numbers in the array
			PrintNumbers(numbers, size);
			break;

		case 'x'://exit
			loopCon = false;
			printf("Thanks for playing!\n");
			break;

		default:
			if(loopCon != false)
			{
				printf("\nInvalid command. Try again.\n");
			}
			
		}
		
		

	} while (command != 'x');
	
	
	
	
	
	
	
	
	return 0;
}