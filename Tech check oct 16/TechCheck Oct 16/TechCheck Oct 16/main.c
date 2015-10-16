#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main()
{
	int number = 0;
	int i = 0;
	int totalSum = 0;
	int totalDiff = 0;
	int totalProd = 0;
	float totalQuo = 0;
	
	printf("Please enter a number between 1 and 5: ");
	scanf("%i", &number);
	totalDiff = number;
	totalProd = number;
	totalQuo = number; 

	for (i = 0; i < 5; i++)
	{			
		printf("%i\n", number);
		totalSum = totalSum + number;
		number++;
		if (i != 4)
		{
			totalDiff = totalDiff - number;
			totalProd = totalProd * number;
			totalQuo = totalQuo / number;
		}
		
	}
	

	printf("The sum of the numbers from top to bottom is %i\n", totalSum);
	printf("The difference of the numbers from top to bottom is %i\n", totalDiff);
	printf("The product of the numbers from top to bottom is %i\n", totalProd);
	printf("The quotient of the numbers from top to bottom is %f\n", totalQuo);

	
	return 0;
}