
struct person{
	struct book * favoriteBook;
};


struct book{
	char title[100];
	int numberOfChapters;
	char author[25];
	int pages;
	float price;
};


int main()
{
	//int size = sizeof(struct book);
	//printf(" %i", &size);
	int i;

	struct book bigButts[3];
	int numbers[3];

	struct book * pBigButts;

	int size = sizeof(bigButts[3]) / sizeof(struct book);

	pBigButts = (struct book *)malloc(sizeof(struct book) * 3);
	/*for (i = 0; i < size; i++)
	{
		printf("what is name of book #%i?: ", i + 1);
		gets(bigButts[i].title);
		puts("who is the author");
		gets(bigButts[i].author);
		printf("How much did the book cost?: ");
		scanf(" %f", &bigButts[i].price);
		printf("How many pages?: ");
		scanf(" %i", &bigButts[i].pages);
		printf("How many chapters?: ");
		scanf(" %i", &bigButts[i].numberOfChapters);
		getchar();
	}*/
	
	for (i = 0; i < size; i++)
	{
		printf("what is name of book #%i?: ", i + 1);
		gets((pBigButts + i)->title);
		puts("who is the author");
		gets((pBigButts + i)->author);
		printf("How much did the book cost?: ");
		scanf(" %.2f", &((pBigButts + i)->price));
		printf("How many pages?: ");
		scanf(" %i", &((pBigButts + i)->pages));
		printf("How many chapters?: ");
		scanf(" %i", &((pBigButts + i)->numberOfChapters));
		getchar();
	}

	return 0;
}
