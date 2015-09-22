#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
int main()
{
	int number;
	char letter;

	printf("Hello. This is a simple 'console' calculator.\n");
	printf("Simply enter the number followed by the operator that you wish to use.\n");
	printf("It is possible to use the standard operators (+, -, *, / ) as well as two extra operators : \n");
	printf("1) S, which set the accumulator; and\n");
	printf("2) N, that ends the calculation (N.B. Must place a zero before N).\n");
	printf("\n");
	
	
	printf("Please enter a number and an operator: ");
	scanf("%i%c", &number, &letter);

	
	
	switch (letter)
	{
	case 'S':;
	case 'N':;
	case '+':;
	case '-':;
	case '*':;
	case '/':;
	}
	


	return 0;
}