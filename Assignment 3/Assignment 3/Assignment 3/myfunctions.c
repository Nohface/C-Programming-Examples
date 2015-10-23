void subString(char source[], char start, int count, char result[])
{
	int position = start - 1;
	int j = 0;
	int i = 0;

	for (i = position; i < position + count; i++, j++)
	{
		result[j] = source[i];
		
		if (j == count - 1)
		{
			result[j + 1] = '\0';
		}
	}
		
}


int findString(char source[], char stringToFind[])
{
	int i = 0;
	int j = 0;
	int index = 0;
	int len = strlen(source);
	int len2 = strlen(stringToFind);

	while (len != 0)
	{
		if (source[i] == stringToFind[j])
		{
			j++;
			len2--;
			if (len2 == 0)
			{
				index = i - strlen(stringToFind) + 2;
			}
		}
		
		
		
		i++;
		len--;
		
	}
		
	return index;
}




void removeString(char source[], int startingIndex, int numberOfCharactersToRemove)
{

}


void insertString(char source[], char stringToInsert[], int insertPosition)
{

}