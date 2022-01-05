//Thi Huong Tra Le
//PROG71985F20
//Assignment 4
//Question 2
//Fall 2020

#define _CRT_SECURE_NO_WARNINGS
#pragma once
#include <stdlib.h>
#include <stdio.h>
#define CAPACITY 12
#define MAXLEN 20
#define SEATNUMBERLENGTH 3
#define ASSIGN "booked"


typedef struct seat {
	char seatNumber[MAXLEN];
	char assigned [MAXLEN];
	char lastName[MAXLEN];
	char firstName[MAXLEN];
}SEAT;

SEAT createSeat(char[], char[], char[], char[]);
void printSelectionMenu();
void printNumberOfEmptySeat();
void printListEmptySeat(char[]);
void printAlphabeticalListOfSeat(char[]);
char getUserInput(char[]);
char seatAssigment(char[], char[], char[], char[]);
char deleteSeat(char[], char[]);
