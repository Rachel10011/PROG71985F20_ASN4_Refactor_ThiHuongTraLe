//Thi Huong Tra Le
//PROG71985F20
//Assignment 4 Refactor
//Question 2
//Fall 2020
//Feedback:
//--program will fail if datafile doesnt exist when starts
//--your functions are oddly divided(across functions.c and source.c) and inconsistent.


#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include "Functions.h"
#include <stdbool.h>

int main(void)
{
	char flightNum;
	char assignSeat[SEATNUMBERLENGTH] = { 0 };
	char customerFirstName[MAXLEN];
	char customerLastName[MAXLEN];
	bool repeat = true;
	bool repeat1;
	char input;
	FILE* fp=NULL;
	SEAT seatArray[CAPACITY];			//create an empty array with the SEAT format
	char fileName[FILENAMELEN];

	if (!fopen("102.txt", "r") || !fopen("311.txt", "r") || !fopen("444.txt", "r") || !fopen("519.txt", "r"))
		//if the file is not created. create new files
	{
		createSeatFileForEachFlight();
	}

	while (repeat) 
	{
		repeat1 = true;

		flightMenu();
		flightNum = getUserInput("\nEnter here: ");

		if (flightNum == 'e')
		{
			repeat = false;
			printf("Bye\n");
			break;
		}

		else if (flightNum == 'a'|| flightNum == 'b' || flightNum == 'c' || flightNum == 'd')
		{
			if (flightNum == 'a')
			{
				fp = fopen("102.txt", "r");
				strcpy(fileName, "102.txt");	//get the file name so we can use it to write new data to the same file
			}
			else if (flightNum == 'b')
			{
				fp = fopen("311.txt", "r");
				strcpy(fileName, "311.txt");
			}
			else if (flightNum == 'c')
			{
				fp = fopen("444.txt", "r");
				strcpy(fileName, "444.txt");
			}
			else if (flightNum == 'd')
			{
				fp = fopen("519.txt", "r");
				strcpy(fileName, "519.txt");
			}

			loadSeatFromDisk(seatArray, fp);
			fclose(fp);

			while (repeat1)
			{
				printSelectionMenu();
				input = getUserInput("\nEnter here: ");

				switch (input)
				{
				case 'a':
				{
					printNumberOfEmptySeat(seatArray);
					continue;
				}
				case 'b':
				{
					printListEmptySeat(seatArray);
					printf("\n");
					continue;
				}
				case 'c':
				{
					printAlphabeticalListOfSeat(seatArray);
					printf("\n");
					continue;
				}
				case 'd':
				{
					
					askForNewSeatInfo(assignSeat, customerFirstName, customerLastName);
					if (!matchingSeat(seatArray, assignSeat))
					{
						void invalidSeat();

					}
					else 
					{
						if (confirmSeatAssignment())
						{
							seatAssigment(seatArray, assignSeat, customerFirstName, customerLastName);
							saveDataToFile(fileName, seatArray);
						}
						
					}
					
					continue;
				}
				case 'e':
				{
					selectDeleteSeat(assignSeat);
					if (!matchingSeat(seatArray, assignSeat))
					{
						void invalidSeat();
					}
					else 
					{
						
						if (confirmSeatAssignment())
						{
							deleteSeat(seatArray, assignSeat);
							saveDataToFile(fileName, seatArray);
						}
						
					}
					continue;
				}
				case 'f':
				{
					repeat1 = false;
					break;
				}
				default:
				{
					invalidInput();
					continue;
				}
				}
				
			}
			continue;
		}
		else
		{
		invalidInput();
		continue;
		}
	}
	return 0;
}