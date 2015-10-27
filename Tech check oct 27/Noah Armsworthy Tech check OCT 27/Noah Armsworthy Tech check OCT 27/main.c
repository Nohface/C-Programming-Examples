#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>


int main()
{
	int total = 0;
	int number;
	
	do
	{
		printf("\nEnter the whole number (enter zero to show the grand total):");
		scanf(" %i", &number);
		number == number;

		if (number % 2 == 0)
		{
			if(number != 0)
				printf("%d is an even number, so it had been added to the grand total\n", number);
			total = total + number;
		}
			
		else
		{
			printf("%d is an odd number, so it had been subtracted from the grand total\n", number);
			total = total - number;
		}
	} while (number != 0);

	printf("Your grand total is %i\n", total);


	return 0;
}