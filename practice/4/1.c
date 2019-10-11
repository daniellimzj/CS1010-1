/**
 * CS1010 AY2019/20 Semester 1 Lab2 Ex1
 * nanotable0.c
 * This program is the first iteraiton towards a Nanotable, a data storage for exam records.
 * Firstly, we will parse user input as different commands for different functions.
 * For data analysis, we also allow users to sum and average different integers.
 * Made by: Kingston Kuan Jun Xiang
 * Group: C09
 */

#include <stdio.h>

int printCentury(int);

int printOrdinal(int);


int main() {
	int year;

	// print welcome information
	printf("Enter year: ");
	scanf("%d", &year);

	printf("The year %d falls in the ", year);
	int century = printCentury(year);
	printOrdinal(century);
	printf(" century.\n");

	return 0;
}


// This function will first ask for the number of intergers to be summed and then find the sum of the integers inputted.
int printOrdinal(int i) { 
	// First lets check for the special cases for numbers ending with 11, 12 or 13.
	if (i % 100 == 11 || i % 100 == 12 || i % 100 == 13) {
		printf("%dth", i);
	}
	else {
		// Now more general cases can be done for the rest of the numbers.
		switch (i % 10) {
			case 1:
				printf("%dst", i);
				break;
			case 2:
				printf("%dnd", i);
				break;
			case 3:
				printf("%drd", i);
				break;
			default:
				printf("%dth", i);
				break;
		}
	}

	return 0;
}

int printCentury(int year) {
	year /= 100;
	year += 1;
	

	return year;
}
