
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

	//identify struct, with embedded struct for clarification
	struct student{
		char firstName[15];
		char lastName[25];

		struct dateOfBirth{
			int birthYear;
			int birthMonth;
			int birthDay;
		}date;
		//name the embedded structs

		struct address{
			char streetAddress[40];
			char city[20];
		}addressDetails;

		float grade;
	}gradeBook;


	int main()
	{
		//identify variables
		//array for month reference
		char * monthName[12] = { "January", "February", "March", "April", "May", "June", "July", "August", "September", "October", "November", "December" };
		char command;
		int i;
		int numberOfStudents = 0;
		//point the struct to gradeBook
		struct student * gradeBook = malloc(sizeof(struct student));
		char choice;

		// Welcome message and choice selection
		printf("Welcome to our student information program.\n\n");
		printf("Choose from the following options:\n");
		printf("1 - Enter data from scratch into the system\n");
		printf("2 - Load data from an existing file\n");
		printf("Your choice: ");
		scanf(" %c", &choice);


		//option for manual entry or file entry
		if (choice == '1')
		{
			//prompt user for how many students
			printf("How many students would you like to enter?: ");
			scanf(" %i", &numberOfStudents);

			//reallocate the memory based on how many students
			gradeBook = realloc(gradeBook, sizeof(struct student)*numberOfStudents);

			//for the amount of students required, ask and scan for details to fill struct
			for (i = 0; i < numberOfStudents; i++)
			{
				printf("\nPlease enter the name for student #%i\n", i + 1);
				printf("First name: ");
				scanf(" %s", &(gradeBook + i)->firstName);
				printf("Last name: ");
				scanf(" %s", &(gradeBook + i)->lastName);

				printf("\nPlease enter the Birth Date for %s %s", (gradeBook + i)->firstName, (gradeBook + i)->lastName);
				printf("\nYear of birth: ");
				//make sure to identify embedded struct reference
				scanf(" %i", &(gradeBook + i)->date.birthYear);
				printf("Birth Month (1-12): ");
				scanf(" %i", &(gradeBook + i)->date.birthMonth);
				printf("Birth Day: ");
				scanf(" %i", &(gradeBook + i)->date.birthDay);

				printf("\nPlease enter the Address for %s %s", gradeBook[i].firstName, gradeBook[i].lastName);
				printf("\nStreet Address: ");
				scanf(" %[^\n]s", &(gradeBook + i)->addressDetails.streetAddress);
				printf("City: ");
				scanf(" %s", &(gradeBook + i)->addressDetails.city);

				printf("\nPlease enter the final grade for %s %s", (gradeBook + i)->firstName, (gradeBook + i)->lastName);
				printf("\nGrade: ");
				scanf(" %f", &(gradeBook + i)->grade);
			}

			OPTIONS:
			do{
				//prompt user for choice in do while loop, q to exit
				printf("\nChoose from the follwoing list of options (type q to quit):");
				printf("\n1 - Display all students' names only\n");
				printf("2 - Display all students and their dates of birth\n");
				printf("3 - Display all students' data\n");
				printf("4 - Display the average grade for all students\n");
				printf("5 - Display the student(s) with the highest grade\n");
				printf("6 - Add another student\n");
				printf("7 - Save student data to file\n");

				printf("Your command:");
				scanf(" %c", &command);
				printf("\n");

				//switch to enter based on user command
				switch (command)
				{
				case '1':
					i = 0;
					//loop to print student names
					for (i = 0; i < numberOfStudents; i++)
					{
						printf("%s %s\n", (gradeBook + i)->firstName, (gradeBook + i)->lastName);
					}
					break;
				case '2':
					i = 0;
					//print names and birth dates, referencing the month array based on the user month input
					for (i = 0; i < numberOfStudents; i++)
					{
						printf("%s %s", (gradeBook + i)->firstName, (gradeBook + i)->lastName);
						printf(" born %s", monthName[(gradeBook + i)->date.birthMonth - 1]);
						printf(" %i, %i\n", (gradeBook + i)->date.birthDay, (gradeBook + i)->date.birthYear);
					}
					break;
				case '3':
					i = 0;
					//display all student info
					for (i = 0; i < numberOfStudents; i++)
					{
						printf("%s %s\n", (gradeBook + i)->firstName, (gradeBook + i)->lastName);
						printf("Birth Date: %s %i, %i\n", monthName[(gradeBook + i)->date.birthMonth - 1], (gradeBook + i)->date.birthDay, (gradeBook + i)->date.birthYear);
						printf("Address: %s, %s\n", (gradeBook + i)->addressDetails.streetAddress, (gradeBook + i)->addressDetails.city);
						printf("Final Grade: %.2f\n\n", (gradeBook + i)->grade);
					}
					break;
				case '4':
					i = 0;
					int average = 0;
					//collect all students grades and add them to "average", divide average by number of students
					for (i = 0; i < numberOfStudents; i++)
					{
						average = average + (gradeBook + i)->grade;
					}
					float printAverage = average / numberOfStudents;
					printf("The average grade for all %i students is %.2f\n", numberOfStudents, printAverage);
					break;
				case '5':
					; float highest = 0;
					//find the highest possible grade
					printf("Student(s) with the highest grade:\n");
					for (int i = 0; i < numberOfStudents; i++)
					{
						if ((gradeBook + i)->grade > highest)
							highest = (gradeBook + i)->grade;

					}

					//find all the students who have that grade
					for (int j = 0; j < numberOfStudents; j++)
					{
						if ((gradeBook + j)->grade == highest)
						{
							printf("%s %s - %.2f", (gradeBook + j)->firstName, (gradeBook + j)->lastName, highest);
							printf("\n");
						}
					}
					break;
				case '6':
					//add one to the number of students
					numberOfStudents++;

					//reallocate memory in gradeBook for another student
					gradeBook = realloc(gradeBook, sizeof(struct student)*numberOfStudents);

					//prompt the user to enter the new student's information
					printf("\nPlease enter the name for student #%i\n", numberOfStudents);
					printf("First name: ");
					scanf(" %s", &(gradeBook + numberOfStudents - 1)->firstName);
					printf("Last name: ");
					scanf(" %s", &(gradeBook + numberOfStudents - 1)->lastName);

					printf("\nPlease enter the Birth Date for %s %s", (gradeBook + numberOfStudents - 1)->firstName, (gradeBook + numberOfStudents - 1)->lastName);
					printf("\nYear of birth: ");
					scanf(" %i", &(gradeBook + numberOfStudents - 1)->date.birthYear);
					printf("Birth Month (1-12): ");
					scanf(" %i", &(gradeBook + numberOfStudents - 1)->date.birthMonth);
					printf("Birth Day: ");
					scanf(" %i", &(gradeBook + numberOfStudents - 1)->date.birthDay);

					printf("\nPlease enter the Address for %s %s", (gradeBook + numberOfStudents - 1)->firstName, (gradeBook + numberOfStudents - 1)->lastName);
					printf("\nStreet Address: ");
					scanf(" %[^\n]s", &(gradeBook + numberOfStudents - 1)->addressDetails.streetAddress);
					printf("City: ");
					scanf(" %s", &(gradeBook + numberOfStudents - 1)->addressDetails.city);

					printf("\nPlease enter the final grade for %s %s", (gradeBook + numberOfStudents - 1)->firstName, (gradeBook + numberOfStudents - 1)->lastName);
					printf("\nGrade: ");
					scanf(" %f", &(gradeBook + numberOfStudents - 1)->grade);
					break;
				case '7':
					//prompt user for the file path to new file
					GETNEWPATH:
					printf("Please enter the name of the path file: ");
					char filePath[100];
					scanf(" %s", filePath);

					//open the requested file path
					FILE * pRecords = fopen(filePath, "w");

					//error if file path is a no-go
					if (pRecords == NULL)
					{
						printf("Error. File path is invalid. \n\n");
						goto GETNEWPATH;
					}

					//print the records of all the students into the new file, based on the number of students
					for (i = 0; i < numberOfStudents; i++)
					{
						fprintf(pRecords, "%s\n", ((gradeBook + i)->firstName));
						fprintf(pRecords, "%s\n", ((gradeBook + i)->lastName));
						printf("\nSaved %s %s's information to requested file.\n", (gradeBook + i)->firstName, (gradeBook + i)->lastName);
						fprintf(pRecords, "%i\n", ((gradeBook + i)->date.birthDay));
						fprintf(pRecords, "%i\n", ((gradeBook + i)->date.birthMonth));
						fprintf(pRecords, "%i\n", ((gradeBook + i)->date.birthYear));
						fprintf(pRecords, "%s\n", ((gradeBook + i)->addressDetails.streetAddress));
						fprintf(pRecords, "%s\n", ((gradeBook + i)->addressDetails.city));
						fprintf(pRecords, "%.0f\n", ((gradeBook + i)->grade));

					}
					
					//close file
					fclose(pRecords);
					
					break;
				case 'q':
					break;
				}
			} while (command != 'q');

			free(gradeBook);
		}

		else if (choice == '2')
		{

			//variables
			int studentsInFile = 0;
			char filePath[100];
			
			//get file path of the file to load
			GETPATH:
			printf("\nWhat is the file path of the file you wish to load? ");
			scanf(" %s", &filePath);
		
			//identify all the buffers and open the file
			int iBuff = 0;
			float fBuff = 0;
			char buff[100];
			FILE * pFile = fopen(filePath, "r");
			int countLines = 0;
			int i;

			//error message is filepath is invalid
			if (pFile == NULL)
			{
				printf("Error. File path is invalid. \n\n");
				goto GETPATH;
			}
			
			//count the lines to the end of the file
			while ((i = fgetc(pFile)) != EOF)
			{
				if (i == '\n')
					countLines++;
			}
			
			//close the file
			fclose(pFile);
			//find out how many students based on the line count
			studentsInFile = countLines / 8;

			//reallocate memory
			gradeBook = realloc(gradeBook, sizeof(struct student)*(studentsInFile));
				
			//open the file	
			pFile = fopen(filePath, "r");

			//get string value and store in the buffer of each line and add to gradeBook
			//add a null terminator after string values
			for (int i = 0; i < studentsInFile; i++)
			{
				fgets(buff, 100, pFile);
				buff[strlen(buff) - 1] = '\0';
				printf("\nAdded %s to your Grade book!\n", buff);
				strcpy((gradeBook + i)->firstName, buff);
					
				fgets(buff, 100, pFile);
				buff[strlen(buff) - 1] = '\0';
				strcpy((gradeBook + i)->lastName, buff);
				
				fgets(buff, 100, pFile);
				//convert integer value to be stored in int Buffer
				iBuff = atoi(buff);
				(gradeBook + i)->date.birthYear = iBuff;
					
				fgets(buff, 100, pFile);
				iBuff = atoi(buff);
				(gradeBook + i)->date.birthMonth = iBuff;
					
				fgets(buff, 100, pFile);
				iBuff = atoi(buff);
				(gradeBook + i)->date.birthDay = iBuff;
					
				fgets(buff, 100, pFile);
				buff[strlen(buff) - 1] = '\0';
				strcpy((gradeBook + i)->addressDetails.streetAddress, buff);
					
				fgets(buff, 100, pFile);
				buff[strlen(buff) - 1] = '\0';
				strcpy((gradeBook + i)->addressDetails.city, buff);
				

				fgets(buff, 100, pFile);
				fBuff = atof(buff);
				(gradeBook + i)->grade = fBuff;

			
			}

			//close the file
			fclose(pFile);

			//add the number of students from file to the base number 
			numberOfStudents += studentsInFile;

			//send user back to the options tag
			goto OPTIONS;
			
		}


	return 0;
}