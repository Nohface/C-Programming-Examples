#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include "myfunctions.h"  // <- header file which contains the definition
						  // of my functions

int main()
{
	int gameScores[10] = { 12, 5, 21, 15, 32, 10 };
	int totalPoints = 0;
	int i = 0;
	float averagePoints;

	//determine the number of elements total in the array
	int numberOfElements = sizeof(gameScores) / sizeof(int); // <- 40 / 4

	//get last four values in the array
	//for (i = 6; i < 10 ;i++)
	for (i = 6; i < numberOfElements; i++)
	{
		printf("What did the player score in game %i?: ", i+1);
		scanf(" %i", &gameScores[i]);
	}

	//tally the total points in the array
	for (i = 0; i < numberOfElements; i++)
	{
		totalPoints = totalPoints + gameScores[i];
		//totalPoints += gameScores[i];   <-same thing
	}

	averagePoints = getAveragePoints(totalPoints, numberOfElements);

	printf("The player's scoring average is %.1f points per game.\n", averagePoints);

	return 0;
}

