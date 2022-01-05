//Thi Huong Tra Le
//PROG71985F20
//Assignment 4 Refactor
//Question 2
//Fall 2020
//Feedback:
//--program will fail if datafile doesnt exist when starts
//--your functions are oddly divided(across functions.c and source.c) and inconsistent.

#include "Functions.h"

void createSeatFileForEachFlight()
{
	FILE* fp1 = fopen("102.txt", "w+");
	FILE* fp2 = fopen("311.txt", "w+");
	FILE* fp3 = fopen("444.txt", "w+");
	FILE* fp4 = fopen("519.txt", "w+");

	for (int i = 0; i < CAPACITY; i++)
	{
		fprintf(fp1, "A%d unbook ___ ___\n", i);
		fprintf(fp2, "A%d unbook ___ ___\n", i);
		fprintf(fp3, "A%d unbook ___ ___\n", i);
		fprintf(fp4, "A%d unbook ___ ___\n", i);
	}
	fclose(fp1);
	fclose(fp2);
	fclose(fp3);
	fclose(fp4);

}

void flightMenu()
{
	printf("List of flights:\n");
	printf("a) 102\n");
	printf("b) 311\n");
	printf("c) 444\n");
	printf("d) 519\n");
	printf("e) Quit\n");
}

void printSelectionMenu()
{
	printf("To choose a function, enter its letter label:\n");
	printf("\ta) Show number of empty seats\n");
	printf("\tb) Show list of empty seats\n");
	printf("\tc) Show alphabetical list of seats\n");
	printf("\td) Assign a customer to a seat assignment\n");
	printf("\te) Delete a seat assignment\n");
	printf("\tf) Back to the flight list\n");
}

char getUserInput(char message[])
{
	char input;
	char scannedInput;

	printf("%s", message);

	scannedInput = scanf("%c", &input);
	char buf;
	while ((buf = getchar()) != '\n' && input != EOF);
	return input;
}

void loadSeatFromDisk(SEAT seatList[], FILE* file)
{

	for (int i = 0; i < CAPACITY; i++)
	{
		SEAT seat;
		fscanf(file, "%s %s %s %s", seat.seatNumber, seat.assigned, seat.firstName, seat.lastName); 
		seatList[i] = seat;		//assign every single line to the seatArray

	}
}



void printNumberOfEmptySeat(SEAT seatList[])
{
	int countEmptySeat = CAPACITY;
	printf("\Number of empty seats:\n");
	for (int i = 0; i < CAPACITY; i++)
	{
		if (strcmp(seatList[i].assigned, ASSIGN) == 0)
			countEmptySeat--;
	}

	printf("Empty seats: %d\n\n", countEmptySeat);

}

void printListEmptySeat(SEAT seatList[])
{
	printf("\nList of empty seats:\n");
	for (int i = 0; i < CAPACITY; i++)
	{
		if (strcmp(seatList[i].assigned, ASSIGN) != 0)
			printf("%s %s %s %s\n", seatList[i].seatNumber, seatList[i].assigned, seatList[i].firstName, seatList[i].lastName);
	}

}

void printAlphabeticalListOfSeat(SEAT seatList[])
{
	if (seatList == NULL)
		printf("There is no seat in this plane.\n");
	else
	{
		printf("Alphabetical list of seat:\n");
		for (int i = 0; i < CAPACITY - 1; i++)
		{
			SEAT temp[CAPACITY];
			for (int j = i + 1; j < CAPACITY; j++)
			{
				if (strcmp(seatList[i].firstName, seatList[j].firstName) > 0)  //compare only seat number but....
				{
					temp[i] = seatList[i];			//move the whole line (there are 12 lines) because it is whole data
					seatList[i] = seatList[j];
					seatList[j] = temp[i];
				}
			}
		}
		for (int i = 0; i < CAPACITY; i++)
		{

			printf("%s %s %s %s\n", seatList[i].seatNumber, seatList[i].assigned, seatList[i].firstName, seatList[i].lastName);
		}
	}
}

void askForNewSeatInfo(char assignSeat[], char firstName[], char lastName[])
{
	char* seatNum;
	printf("Which seat do you want to book ? \nEnter here: ");
	scanf("%s",assignSeat);
	printf("What is the customer's first name? \nEnter here: ");
	scanf("%s", firstName);
	printf("What is the customer's last name? \nEnter here: ");
	scanf("%s", lastName);
	getchar();
}

void seatAssigment(SEAT seatList[], char seatNum[], char firstName[], char lastName[])
{
	int i = 0;
	while (i < CAPACITY)
	{
		if (strcmp(seatList[i].seatNumber, seatNum) == 0)   //find the seat number that match with the user's input, if invalid, the fuction will return the same thing that were in the file
		{
			strcpy(seatList[i].seatNumber, seatNum);		//replace the old data
			strcpy(seatList[i].firstName, firstName);
			strcpy(seatList[i].lastName, lastName);
			strcpy(seatList[i].assigned, "booked");
			break;
		}
		i++;
	}
}
bool matchingSeat(SEAT seatList[], char seatNum[])
{
	int countSimilarSeats = 0;
	for(int i=0;i<CAPACITY;i++)
	{
		if (strcmp(seatList[i].seatNumber, seatNum) == 0)   //find the seat number that match with the user's input, if invalid, the fuction will return the same thing that were in the file
		{
			countSimilarSeats++;
		}
	}
		if (countSimilarSeats == 0)
			return false;
		else
			return true;
}

void invalidSeat()
{
	printf("Cannot find the matching seat!\n");
}

bool confirmSeatAssignment()
{
	char answer[MAXLEN];
	puts("Are you sure you want to save the chages to original file? (Yes/No): ");
	scanf("%s", answer);
	getchar();
	if(strcmp(answer,"Yes") ==0)
		return true;
	else
		return false;
}

void saveDataToFile(char fileName[], SEAT seatList[])
{
	FILE* fp = fopen(fileName, "w+");
	for (int i = 0; i < CAPACITY; i++)
	{ 
	
		fprintf(fp,"%s %s %s %s\n", seatList[i].seatNumber, seatList[i].assigned, seatList[i].firstName, seatList[i].lastName);

	}
	printf("Data is updated successfully.\n\n");
	fclose(fp);
}

char deleteSeat(SEAT seatList[], char seatNum[])
{
	int i = 0;
	while (i < CAPACITY)
	{
		if (strcmp(seatList[i].seatNumber, seatNum) == 0)//.seatNumber, seatNum) == 0)  //find the matching seat, if invalid, return the same thing that were in the file
		{
			strncpy(seatList[i].firstName, "___", MAXLEN);  //remove customer's name
			strncpy(seatList[i].lastName, "___", MAXLEN);
			strncpy(seatList[i].assigned, "unbook", MAXLEN);
			break;
		}
		i++;
	}
}

void selectDeleteSeat(char seat[])
{
	printf("Which seat do you want to delete ? \nEnter here: ");
	scanf("%s", seat);
	getchar();
	printf("\n");
}

void invalidInput()
{
	printf("\nYour input is invalid.Try again.\n");
}