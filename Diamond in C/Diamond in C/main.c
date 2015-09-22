#include <stdio.h>
int main()
{
	//Declare our variables
	int diamondSize = 15;
	int center = diamondSize / 2;
	int spaces = center;
	int os = 1;
	int lineNumber = 1;

	while (spaces <= diamondSize)
	{
		for (int x = 1; x <= spaces; x++)
		{
			printf(" ");
		}

		for (int y = 1; y <= os; y++)
		{
			printf("o");
		}

		if (lineNumber <= center)
		{
			spaces--;
			os += 2;
		}
		
		else
		{
			spaces++;
			os -= 2;
		}
		

		
		lineNumber++;
		printf("\n");
	}
	
	/*while (spaces <= center)
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
	}*/
	




	return 0;
}
