/**
 * CS1010 AY2017/8 Semester 1 Lab4 Ex1
 * nanotable1.c
 * This program allows users to insert student ID and scores into a database.
 * The user may then analyse the data using commands which can be found by entering help.
 * Kingston Kuan Jun Xiang
 * C09
 */

#include <stdio.h>
#include <string.h>
#include <math.h>

#define TRUE 1
#define MAX_COMMAND_LENGTH 100
#define MAX_ENTRIES 100
#define MAX_COLUMNS 2

/* Function prototypes */
void print_help();
void insert_table(int[][MAX_COLUMNS], int);
int sum(int[][MAX_COLUMNS], int);
int ave(int[][MAX_COLUMNS], int);
void rank(int[][MAX_COLUMNS], int);

int main(void) {

	// The string for input command, do not modify...
	char input[MAX_COMMAND_LENGTH];

	// Represent the table as a two-dimensional array.
	// The first column stores the student ID while the second stores the score.
	// Use another variable to track the number of entries in the table.
	int table[MAX_ENTRIES][MAX_COLUMNS], num_entries = 0, sum_score, ave_score, i;

	// print welcome information
	printf("Welcome to Nanotable!\n");
	printf("Type \"help\" for more information...\n");

	while (TRUE) {
		printf("Waiting for command...\n");
		scanf("%s", input);

		if (strcmp(input,"help") == 0) {
			print_help();
		} else if (strcmp(input,"exit") == 0){
			printf("See you!\n");
			break;
		} else if (strcmp(input,"sum") == 0) {
			if (num_entries == 0) {
				printf("The table is empty\n");
			} else {
				sum_score = sum(table, num_entries);
				printf("The sum of score is %d\n", sum_score);
			}
		} else if (strcmp(input,"ave") == 0) {
			if (num_entries == 0) {
				printf("The table is empty\n");
			} else {
				ave_score = ave(table, num_entries);
				printf("The average of score is %d\n", ave_score);
			}
		} else if (strcmp(input,"insert") == 0) {
			insert_table(table, num_entries);
			num_entries++;
		} else if (strcmp(input,"init") == 0) {
			printf("Initializing table...\n");

			// Empty the table and set the number of entries back to 0.
			for (i = 0; i < num_entries; i++) {
				table[i][0] = 0;
				table[i][1] = 0;
			}
			num_entries = 0;
		} else if (strcmp(input,"rank") == 0) {
			if (num_entries == 0) {        
				printf("The table is empty\n");
			} else {
				rank(table, num_entries);
			}
		} else {
			printf("No such command: %s, please input command again!\n", input);
		}
	}
	return 0;
}

// This function prints the help information
void print_help() {
	printf("Commands available: insert, init, sum, ave, rank, help, exit\n");
}

// This function allows the user to insert a student's ID and score into the table according to rank.
void insert_table(int table[][MAX_COLUMNS], int size) {
	int i, id, score, rank;
	
	printf("Please input the student's ID...\n");
	scanf("%d", &id);
	printf("Please input the student's score...\n");
	scanf("%d", &score);

	// Find the rank at which the new ID and score should be inserted.
	for (rank = 0; rank < size; rank++) {
		if (table[rank][1] > score) {
			break;
		}
	}
	
	// While the score is the same as the entry before then the rank is dependent on the ID.
	while (rank != 0 && table[rank - 1][1] == score) {
		if (table[rank - 1][0] < id)
			break;
		rank--;
	}

	// Shift all the entries after this rank down by 1.
	for (i = size; i > rank; i--) {
		table[i][0] = table[i-1][0];
		table[i][1] = table[i-1][1];
	}

	// Finally, add the ID and score at the desired rank.
	table[rank][0] = id;
	table[rank][1] = score;
}

// This function sums up the scores in the table.
int sum(int table[][MAX_COLUMNS], int size) {
	int i, sum_score = 0;

	// Iterate through all the scores and add them to the sum.
	for(i = 0; i < size; i++) {
		sum_score += table[i][1];
	}

	return sum_score;
}

// This function finds the average of the scores in the table
int ave(int table[][MAX_COLUMNS], int size) {
	int sum_score, rounded_score;
	double ave_score;

	// First use the sum function to sum all the scores in the table.
	sum_score = sum(table, size);

	// Find the average by dividing the sum by the number of scores.
	ave_score = (double)sum_score / size;

	// Round up or down to the nearest integer.
	if (ave_score - floor(ave_score) >= 0.5)
		rounded_score = ceil(ave_score);
	else
		rounded_score = floor(ave_score);

	return rounded_score;
}

// This function prints the  ID and score of a student at a selected rank.
void rank(int table[][MAX_COLUMNS], int size) {
	int rank;

	printf("Please input the rank (1 - %d)...\n", size);
	scanf("%d", &rank);

	while (rank > size) {
		printf("Invalid rank: %d\n", rank);
		printf("Please input the rank (1 - %d)...\n", size);
		scanf("%d", &rank);
	}

	printf("ID: %d, Score: %d\n", table[rank - 1][0], table[rank - 1][1]);
}

