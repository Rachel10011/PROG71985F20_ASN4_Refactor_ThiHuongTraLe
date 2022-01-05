//Thi Huong Tra Le
//PROG71985F20
//Assignment 4
//Question 2
//Fall 2020

#include "Functions.h"

SEAT createSeat(char number[MAXLEN], char status[MAXLEN], char first_name[MAXLEN], char last_name[MAXLEN])
{
	SEAT seat;
	strncpy(seat.seatNumber, number, MAXLEN);
	strncpy(seat.assigned, status, MAXLEN);
	strncpy(seat.firstName, first_name, MAXLEN);
	strncpy(seat.lastName, last_name, MAXLEN);
	return seat;
}

void printSelectionMenu()
{
	printf("To choose a function, enter its letter label:\n");
	printf("\ta) Show number of empty seats\n");
	printf("\tb) Show list of empty seats\n");
	printf("\tc) Show alphabetical list of seats\n");
	printf("\td) Assign a customer to a seat assignment\n");
	printf("\te) Delete a seat assignment\n");
	printf("\tf) Quit\n");
}

char getUserInput(char message[])
{
	char input;
	char scannedInput;

		printf("%s", message);

		scannedInput = scanf_s("%c", &input);
		char buf;
		while ((buf = getchar()) != '\n' && input != EOF);
	return input;
}

void printNumberOfEmptySeat(SEAT seatList[])
{
	int countEmptySeat=CAPACITY;

	for (int i=0; i<CAPACITY; i++)
	{
		if (strcmp(seatList[i].assigned, ASSIGN)==0)
			countEmptySeat--; 
	}

	printf("Empty seats: %d\n\n", countEmptySeat);
	
}

void printListEmptySeat(SEAT seatList[])
{
	
	for (int i = 0; i < CAPACITY; i++)
	{
		if (strcmp(seatList[i].assigned, ASSIGN) !=0)
			printf("%s %s %s %s\n", seatList[i].seatNumber, seatList[i].assigned, seatList[i].firstName, seatList[i].lastName);
	}
	
}

void printAlphabeticalListOfSeat(SEAT seatList[])
{
	
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
	for (int i = 0; i< CAPACITY; i++)
	{
		
		printf("%s %s %s %s\n", seatList[i].seatNumber, seatList[i].assigned ,seatList[i].firstName, seatList[i].lastName);
	}
}

char seatAssigment(SEAT seatList[],char seatNum[], char firstName[], char lastName[])
{
	int i = 0;
	while( i<CAPACITY)
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

	return seatList;

}
char deleteSeat(SEAT seatList[], char seatNum[])
{
	int i = 0;
	while (i < CAPACITY)
	{
		if (strcmp(seatList[i].seatNumber, seatNum) == 0)  //find the matching seat, if invalid, return the same thing that were in the file
		{
			strncpy(seatList[i].firstName, "__", MAXLEN);  //remove customer's name
			strncpy(seatList[i].lastName, "__",MAXLEN);
			strncpy(seatList[i].assigned, "unbooked", MAXLEN);
			break;
		}
		i++;
	}
	return seatList;
}
