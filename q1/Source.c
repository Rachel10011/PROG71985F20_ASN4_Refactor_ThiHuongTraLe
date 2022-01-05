//Thi Huong Tra Le
//PROG71985F20
//Assignment 4
//Question 1
//Fall 2020

#define _CRT_SECURE_NO_WARNINGS 
#include <stdio.h>
#include <ctype.h>
#define MAX 1000
int main(void)
{
	int lower, upper;
	char sourceFile[MAX], outputFile [MAX];
	FILE* fpointer;
	FILE* output;

	printf("Enter source file: ");
	scanf("%s", &sourceFile);						//store suer's filename in at the address of fileName
	printf("\nEnter output file: ");
	scanf("%s", &outputFile);
	
	fpointer = fopen(sourceFile, "r");			//read the file that user entered
	output = fopen(outputFile, "w");

	while ((lower = getc(fpointer)) != EOF)     //as long as it is not the end of the file, 
	{
		upper = toupper(lower);					//revert charaters from lowercase to uppercase
		fprintf(output, "%c", upper);
	}
	printf("\n");
	fclose(fpointer); 
	fclose(output);

	return 0;
}