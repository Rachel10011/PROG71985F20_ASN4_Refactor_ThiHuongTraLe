//Thi Huong Tra Le
//PROG71985F20
//Assignment 4
//Question 2
//Fall 2020

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include "Functions.h"
#include <stdbool.h>

int main(void)
{
	
	char assignSeat[SEATNUMBERLENGTH];
	char customerFirstName[MAXLEN];
	char customerLastName[MAXLEN];
	bool repeat = true;
	char input;
	FILE* originalFile;
	FILE* newFile1;
	FILE* newFile2;

	originalFile = fopen("seatslist.txt", "r");
	
	SEAT seatArray[CAPACITY];			//create an empty array with the SEAT format

	for (int i = 0; i < CAPACITY; i++)
	{
		SEAT seat;
		fscanf(originalFile, "%s %s %s %s", seat.seatNumber, seat.assigned, seat.firstName, seat.lastName);  //copy data from the file to the "seat" array , 1 "seat" is for 1 single line    		
		seatArray[i] = seat;		//assign every single line to the seatArray
	}


	while (repeat) {
		printSelectionMenu();
		input = getUserInput("\nEnter here: ");

		switch (input)
		{
			case 'a':
			{
				
				printNumberOfEmptySeat(seatArray);
				break;
			}
			case 'b':
			{
				printf("\nList of empty seats:\n");
				printListEmptySeat(seatArray);
				printf("\n");
				break;
			}
			case 'c':
			{
				printf("Alphabetical list of seat:\n");
				printAlphabeticalListOfSeat(seatArray);
				printf("\n");
				break;
			}
			case 'd':
			{
				newFile1 = fopen("seatslist_temp.txt", "w");		//create a new file to replace the old file after the process

				printf("Which seat do you want to book ? \nEnter here: ");
				scanf("%s", &assignSeat);		
				printf("What is the customer's first name? \nEnter here: ");
				scanf("%s", &customerFirstName);
				printf("What is the customer's last name? \nEnter here: ");
				scanf("%s", &customerLastName);

				seatAssigment(seatArray,assignSeat,customerFirstName, customerLastName);
				getchar();   //to remove the '\n' character from the input so when user enters the next input, there will not be an extra '\n' character in front
				//because when user entering data, user types in the input then presses the enter key.The enter key adds the \n.but scanf does not read that character
				
				for (int i = 0; i < CAPACITY; i++)
				{
					//copy all updated data to a new file
					fprintf(newFile1, "%s %s %s %s\n", seatArray[i].seatNumber, seatArray[i].assigned, seatArray[i].firstName, seatArray[i].lastName);
					//data is also be printed on the screen so user can sees the file's content easier 
					printf("%s %s %s %s\n", seatArray[i].seatNumber, seatArray[i].assigned, seatArray[i].firstName, seatArray[i].lastName);
				}
				fclose(newFile1);				
				fclose(originalFile);
				remove("seatslist.txt");						//remove the old file and rename the new file
				rename("seatslist_temp.txt", "seatslist.txt");
				printf("\nData is successfully updated in the file.\n\n");
				break;
			} 
			case 'e':
			{
				newFile2 = fopen("seatslist_temp.txt", "w");

				printf("Which seat do you want to delete ? \nEnter here: ");
				scanf("%s", &assignSeat);
				getchar();
				printf("\n");

				deleteSeat(seatArray, assignSeat);

				for (int i = 0; i < CAPACITY; i++)
				{
					fprintf(newFile2, "%s %s %s %s\n", seatArray[i].seatNumber, seatArray[i].assigned, seatArray[i].firstName, seatArray[i].lastName);
					printf("%s %s %s %s\n", seatArray[i].seatNumber, seatArray[i].assigned, seatArray[i].firstName, seatArray[i].lastName); 
				}
				fclose(newFile2);
				fclose(originalFile);
				remove("seatslist.txt");
				rename("seatslist_temp.txt", "seatslist.txt");
				printf("\nData is successfully updated in the file.\n");
				break;
			}
			case 'f':
			{
				printf("Bye\n");
				repeat = false;
				break;
			}
			default:
			{
				printf("\nYour input is invalid.\n\n");
				break;
			}
		}
	}
	fclose(originalFile);

	return 0;
}