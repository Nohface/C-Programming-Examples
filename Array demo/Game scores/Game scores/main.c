#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include "myfunctions.h"



int main()
{
	int gameScores[10] = { 12, 5, 21, 15, 32, 10 };
	int totalPoints = 0;
	int i = 0;
	float averagePoints;

	int numberofElements = sizeof(gameScores) / sizeof(int);


	for (i = 6; i < numberofElements; i++)
	{
		printf("What did the player scare in game %i?: ", i + 1);
		scanf(" %i", &gameScores[i]);
	}

	
	for (i = 0; i < numberofElements; i++)
	{
		totalPoints += gameScores[i];
	}

	averagePoints = totalPoints / numberofElements;

	printf("The player's scoring average is %.1f points per game. \n", averagePoints);



	return 0;
}