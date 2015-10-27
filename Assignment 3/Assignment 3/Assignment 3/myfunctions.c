void subString(char source[], char start, int count, char result[])
{
	//set the position variable knowing that strings start at 0
	int position = start - 1;
	int j = 0;
	int i = 0;

	//loop at position as many times as position+count, taking letters from first array to second
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
	//set variables, including length of strings
	int i = 0;
	int j = 0;
	int index = 0;
	int len = strlen(source);
	int len2 = strlen(stringToFind);

	//search for two similar characters and check that it is the full length of the word
	//return starting point of that word
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




void removeString(char source[], int startingIndex, int count)
{
	//declare variables
	int i = 0;
	int j = 0;
	
	//temporary array to store desired string
	char result[50];
	int position = startingIndex - 1;
	int len = strlen(source);
	int temp = position + count;

	//do while the length of the source file doesn't = 0
	do 
	{
		//while the index is less than the position
		while (i < position)
		{
			result[j] = source[i];
			j++;
			i++;
		}
		
		//and larger than the count
		//add those characters to the result array
		while (i > temp && i <= strlen(source))
		{
			result[j] = source[i];
			
			j++;
			i++;
		}

		i++;
		//decrease the length count of the source array each loop
		len--;

		//if the length is 0, add the null terminator
		if (len == 0)
			result[j] = '\0';

	} while (len != 0);

	
	//get the length of the result array & set the variable back to 0
	int len2 = strlen(result);
	j = 0;
	i = 0;

	//while j is less than the length of result, replace the characters in the source
	//with the ones from the result
	while (j <= len2)
	{
		source[i] = result[j];
		
		//when you get to the end of the result array, add a null terminator to the source array
		if (j == len2)
			source[i] = '\0';
		j++;
		i++;
	}
		

	

}


void insertString(char source[], char stringToInsert[], int insertPosition)
{

}