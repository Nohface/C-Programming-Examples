float GetLargestNumber(float numbers[], int numberOfElements)
{
	int i;
	float largest = numbers[0];

	for (i = 0; i < numberOfElements; i++) 
	{
		if (numbers[i] > largest)
		{
			largest = numbers[i];
		}
	}

	return largest;
}