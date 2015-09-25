#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

int main()
{
	float number;
	float total = 0;
	char letter;

	printf("Hello. This is a simple 'console' calculator.\n");
	printf("Simply enter the number followed by the operator that you wish to use.\n");
	printf("It is possible to use the standard operators (+, -, *, / ) as well as two extra operators : \n");
	printf("1) S, which set the accumulator; and\n");
	printf("2) N, that ends the calculation (N.B. Must place a zero before N).\n");
	printf("\n");
	
	
	
	do
	{
		printf("Please enter a number and an operator: ");
		scanf("%f%c", &number, &letter);
		printf("%f\n", total);
		
		switch (letter)
		{
		case 'S':
			(total = number);
		case 'N':
			if (number == 0)
			{
				break;
			}
		case '+':
			( total = total + number);
			break;
		case '-':
			(total = total - number);
			break;
		case '*':
			(total = total * number);
			break;
		case '/':
			(total = total / number);
			break;
		default: 
			printf("Error. Please ensure you enter a correct number and operator.\n");
		}
		
	}while (letter != 'N');
	
	


	return 0;
}