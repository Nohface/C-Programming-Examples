//define error cancellation and include necessary libraries
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

//include main function
int main()
{
	//declare variables
	float number;
	float total = 0;
	char letter;

	//print welcome statement and instructions
	printf("Hello. This is a simple 'console' calculator.\n");
	printf("Simply enter the number followed by the operator that you wish to use.\n");
	printf("It is possible to use the standard operators (+, -, *, / ) as well as two extra operators : \n");
	printf("1) S, which set the accumulator; and\n");
	printf("2) N, that ends the calculation (N.B. Must place a zero before N).\n");
	printf("\n");
	
	
	//do function while N is not typed
	do
	{
		//ask for variable
		printf("Please enter a number and an operator: ");
		scanf("%f%c", &number, &letter);
		
		//switch statement relying on the letter that follows the number
		switch (letter)
		{
		case 'S':
			//S sets the input number as the total to work with
			(total = number);
			break;
		case 'N':
			//recognizes if the use types '0N'
			if (number == 0)
			{
				break;
			}
		case '+':
			//adds the new number to the total
			( total = total + number);
			break;
		case '-':
			//subtracts the new number from the total
			(total = total - number);
			break;
		case '*':
			//multiplies the new number by the total
			(total = total * number);
			break;
		case '/':
			//as long as the new number is not 0, devide the total by the new number
			if (number == 0)
			{
				printf("Cannot divide by zero.\n");
				break;
			}
			else
			{
				(total = total / number);
			}
			break;
		default: 
			//have a default error text if you type an unrecognized letter
			printf("Error. Please ensure you enter a correct number and operator.\n");
		}
		
		//print the total only if the user has not typed N or tried to divide by 0
		if ((letter != 'N' )&&(letter != '/' && number != 0))
		{
			printf("%f\n", total);
		}
	}while (letter != 'N');
	
	


	return 0;
}