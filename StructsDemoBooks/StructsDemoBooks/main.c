//the data structure that comprises all data about a book.
struct book{
	char title[50];
	int numberOfChapters;
	char author[25];
	int pages;
	float price;
};

int main()
{
	//declare a static pointer array
	struct book myFavoriteBooks[3];
	//declare a pointer
	struct book * pMyFavoriteBooks;

	//determine the size of my array of books
	int size = sizeof(myFavoriteBooks) / sizeof(struct book);

	//initialize an address value to the variable by dynamically allocating enough memory to store three books
	pMyFavoriteBooks = (struct book *)malloc(sizeof(struct book) * 3); //<-we cast the memory allocation to type (struct book *)...which is the same as our pointer type


	//ask and store data in static books array
	for (int i = 0; i < size ; i++)
	{
		printf("What is the name of book #%i?: ", i + 1);
		gets(myFavoriteBooks[i].title);  //<- note the dot notation when accessing data from the struct
		printf("Who is the author?: ");
		gets(myFavoriteBooks[i].author);
		printf("How much did the book cost?: ");
		scanf(" %f", &myFavoriteBooks[i].price);
		printf("How many pages?: ");
		scanf(" %i", &myFavoriteBooks[i].pages);
		printf("How many chapters?: ");
		scanf(" %i", &myFavoriteBooks[i].numberOfChapters);
		getchar();
	}


	//ask for and store data in the dynamically allocated heap memory.
	for (int i = 0; i < size; i++)
	{
		printf("What is the name of book #%i?: ", i + 1);
		gets((pMyFavoriteBooks + i)->title); //note the -> notation when accessing data from the struct
		printf("Who is the author?: ");
		gets((pMyFavoriteBooks + i)->author);
		printf("How much did the book cost?: ");
		scanf(" %f", &(pMyFavoriteBooks + i)->price);
		printf("How many pages?: ");
		scanf(" %i", &(pMyFavoriteBooks + i)->pages);
		printf("How many chapters?: ");
		scanf(" %i", &(pMyFavoriteBooks + i)->numberOfChapters);
		getchar();
	}

	free(pMyFavoriteBooks); //free our dynamically allocated memory when finished

	return 0;
}

