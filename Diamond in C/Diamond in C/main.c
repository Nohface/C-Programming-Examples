#include <stdio.h>
int main()
{
	//Declare our variables
	int diamondSize = 15;
	int center = diamondSize / 2;
	int spaces = center;
	int os = 1;

	while (spaces >= 1)
	{
		for (int x = 1; x <= spaces; x++)
		{
			printf(" ");
		}

		for (int y = 1; y <= os; y++)
		{
			printf("o");
		}
		
		spaces--;
		os += 2;
		printf("\n");
	}
	
	while (spaces <= center)
	{
		for (int x = 1; x <= spaces; x++)
		{
			printf(" ");
		}

		for (int y = 1; y <= os; y++)
		{
			printf("o");
		}

		spaces++;
		os -= 2;
		printf("\n");
	}
	




	return 0;
}
