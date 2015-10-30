#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include "myfunctions.h"

int main()
{
	int i;
	float numbers[5];
	int size = 5;
	
	
	
	for (i = 0; i < size; i++)
	{
		printf("Enter number %i: ", i + 1);
		scanf(" %f", &numbers[i]);
	}

	float printNumber = GetLargestNumber(numbers, size);
	printf("Your largest number is: %.2f \n", printNumber);

	return 0;
}
