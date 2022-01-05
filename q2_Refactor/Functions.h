//Thi Huong Tra Le
//PROG71985F20
//Assignment 4 Refactor
//Question 2
//Fall 2020
//Feedback:
//--program will fail if datafile doesnt exist when starts
//--your functions are oddly divided(across functions.c and source.c) and inconsistent.

#define _CRT_SECURE_NO_WARNINGS
#pragma once
#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#define CAPACITY 12
#define MAXLEN 20
#define SEATNUMBERLENGTH 3
#define ASSIGN "booked"
#define FILENAMELEN 8


typedef struct seat {
	char seatNumber[MAXLEN];
	char assigned[MAXLEN];
	char lastName[MAXLEN];
	char firstName[MAXLEN];
}SEAT, *PSEAT;


void flightMenu();
void invalidInput();
void createSeatFileForEachFlight();
void loadSeatFromDisk(SEAT[], FILE*);
void printSelectionMenu();
void printNumberOfEmptySeat();
void printListEmptySeat(char[]);
void printAlphabeticalListOfSeat(char[]);
char getUserInput(char[]);
void askForNewSeatInfo(char [], char[], char[]);
void seatAssigment(char[],char[], char[], char[]);
bool confirmSeatAssignment();
bool matchingSeat(SEAT [], char []);
void saveDataToFile(char[] , SEAT []);
char deleteSeat(char[], char[]);
void selectDeleteSeat(char[]);
void invalidSeat();

