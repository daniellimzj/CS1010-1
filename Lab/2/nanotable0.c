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
#include <string.h>
#include <math.h>

#define COMMAND_HELP 0
#define COMMAND_EXIT 1
#define COMMAND_SUM 2
#define COMMAND_AVE 3
#define COMMAND_INVALID 4

/* Function prototypes */
int parse_command();

int check_command(char* input);

void print_help();

int simple_sum();

int simple_average();


int main() {
	int state;

	// print welcome information
	printf("Welcome to Nanotable!\n");
	printf("Type \"help\" for more information...\n");

	state = parse_command();

	// Loops on state 0 until state changes to 1;
	while (state == 0) {
		state = parse_command();
	}

	return 0;
}

// This command parser works in a REPL style, sending the current state to the main function to continue or break the while loop.
int parse_command() {
	char tmp_command[100] = "";
	int command_code;

	printf("Waiting for command...\n");
	scanf("%s", tmp_command);

	command_code = check_command(tmp_command);    

	if (command_code == COMMAND_HELP) {
		print_help();
	}
	else if (command_code == COMMAND_EXIT) {
		printf("See you!\n");
		return 1; // Make the state 1 to exit the while loop in main.
	}
	else if (command_code == COMMAND_SUM) {
		simple_sum();
	}
	else if (command_code == COMMAND_AVE) {
		simple_average();
	}
	else {
		// others
		printf("No such command: %s, please input command again!\n", tmp_command);
	}
	return 0; // Any command except exit will return the state as 0.
}

// This function will first ask for the number of intergers to be summed and then find the sum of the integers inputted.
int simple_sum() {
	int num_of_ints, temp_holder, sum = 0, i; 

	printf("Please indicate the number of integers:\n");
	scanf("%d", &num_of_ints);

	// Ask for the integer as many times as the number of integers indicated.
	for (i = 1; i <= num_of_ints; i++) {
		printf("Please input the ");

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

		printf(" number:\n");
		scanf("%d",&temp_holder);
		sum += temp_holder;	
	}

	printf("sum is %d\n", sum);
	return 0;
}

// This function will first ask for the number of intergers to be averaged
// and then find the average of the integers inputted.
int simple_average() {
	int num_of_ints, temp_holder, sum = 0, i;
	double ave;

	printf("Please indicate the number of integers:\n");
	scanf("%d", &num_of_ints);

	// Ask for the integer as many times as the number of integers indicated.
	for (i = 1; i <= num_of_ints; i++) {
		printf("Please input the ");

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

		printf(" number:\n");
		scanf("%d",&temp_holder);
		sum += temp_holder;
	}

	// Find the average of the numbers and round it up to the nearest integer.
	ave = round((sum)/(num_of_ints*1.0));

	printf("average is %.0f\n", ave);
	return 0;
}

// DO NOT MODIFY THE FOLLOWING PART!

// This function takes a command as input and returns an integer as output.
/* INPUT    OUTPUT
   help     0
   EXIT     1
   SUM      2
   AVE      3
   others   4
 */
int check_command(char* input) {
	if (strcmp(input,"help") == 0) {
		return COMMAND_HELP;
	}
	else if (strcmp(input,"exit") == 0) {
		return COMMAND_EXIT;
	}
	else if (strcmp(input,"sum") == 0) {
		return COMMAND_SUM;      
	}
	else if (strcmp(input,"ave") == 0) {
		return COMMAND_AVE;
	}
	else {
		return COMMAND_INVALID;
	}
}

// This function prints the help information
void print_help() {
	printf("Commands available: sum, ave, help, exit\n");
}

