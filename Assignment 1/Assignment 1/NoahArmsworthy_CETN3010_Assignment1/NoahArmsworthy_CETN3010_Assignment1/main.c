#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

int main()
{
	float number;
	float secondNumber = 0;
	char letter;

	printf("Hello. This is a simple 'console' calculator.\n");
	printf("Simply enter the number followed by the operator that you wish to use.\n");
	printf("It is possible to use the standard operators (+, -, *, / ) as well as two extra operators : \n");
	printf("1) S, which set the accumulator; and\n");
	printf("2) N, that ends the calculation (N.B. Must place a zero before N).\n");
	printf("\n");
	
	printf("Please enter a number and an operator: ");
	scanf("%d%c", &number, &letter);
	
	do
	{
		printf("%i\n", number);

		printf("Please enter a number and an operator: ");
		scanf("%d%c", &secondNumber, &letter);
		
		switch (letter)
		{
		case 'S':;
		case 'N':
			if (number == 0)
			{
				exit;
			}
		case '+':
			(number = number + secondNumber);
			break;
		case '-':
			(number = number - secondNumber);
			break;
		case '*':
			(number = number * secondNumber);
			break;
		case '/':
			(number = number / secondNumber);
			break;
		default: 
			printf("Error. Please ensure you enter a correct number and operator.");
		}
		
	}while (letter != 'N');
	
	


	return 0;
}