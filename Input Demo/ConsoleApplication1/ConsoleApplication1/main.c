#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main()
{
	int number; 
	char letter;

	printf("Please enter a number and a letter: ");
	scanf("%i%c", &number, &letter);
	
	printf("You typed %i\n", number);
	printf("and you typed %c\n", letter);

	switch (number)
	{
	case 1:
		switch (letter)
		{
		case 'A':
			printf("You win!\n");
			break;
		default:
			printf("You lose!\n");
		}
		printf("That an awfully small number.\n");
		break;
	case 10: 
		printf("That's a good sized number.\n");
		break;
	case 20:
		printf("That's a biggie number.\n");
		break;
	default:
		printf("Your number has no power here!\n");
	}
		
		
		
	return 0;
}
