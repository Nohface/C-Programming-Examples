//functions
//get the average
float GetAverage(int numbers[], int size){
	int i = 0;
	int total = 0;

	for (i = 0; i < size; i++)
	{
		total = total + numbers[i];
	}

	float average = (float)total / size;

	return average;
}


//sort numbers in ascending order
void SortedNumbers(int numbers[], int size){
	int i, j, temp;

	for (i = 0; i < size - 1; ++i)
		for (j = i + 1; j < size; ++j)
		if (numbers[i] > numbers[j])
		{
			temp = numbers[i];
			numbers[i] = numbers[j];
			numbers[j] = temp;
		}
}


//get the sum of the array numbers
int GetSum(int numbers[], int size){
	int i = 0;
	int total = 0;

	for (i = 0; i < size; i++)
	{
		total = total + numbers[i];
	}

	return total;
}


//print the numbers
void PrintNumbers(int numbers[], int size){
	int i = 0;

	for (i = 0; i < size - 1; i++)
	{
		printf("%i, ", numbers[i]);
	}

	printf("and %i\n\n", numbers[size - 1]);
}


//print the sum as binary
void PrintSumAsBinary(int numbers[], int size){
	
	int binarySize = 32;
	int i = 0;
	int total = 0;
	int value; 

	for (i = 0; i < size; i++)
	{
		total = total + numbers[i];
	}

	for (binarySize = 31; binarySize >= 0; binarySize--)
	{
		value = total >> binarySize;

		if (value & 1)
			printf("1");
		else
			printf("0");
	}

}