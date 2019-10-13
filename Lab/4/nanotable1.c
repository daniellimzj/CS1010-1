/**
 * CS1010 AY2017/8 Semester 1 Lab4 Ex1
 * nanotable1.c
 * <Type your program description here>
 * <Type your name here>
 * <Type your discussion group here>
 */

#include <stdio.h>
#include <string.h>
#include <math.h>

#define TRUE 1
#define MAX_COMMAND_LENGTH 100

/* Function prototypes */
void print_help();

int main(void) {
  
  // The string for input command, do not modify...
  char input[MAX_COMMAND_LENGTH];

  // TO BE IMPLEMENTED
  // How to represent the table and other information...


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
      if (TRUE)/* Need to determine whether the table is empty...*/ {
	printf("The table is empty\n");
      } else {
	// TO BE IMPLEMENTED
	printf("The sum of score is %d\n", 1);
      }
    } else if (strcmp(input,"ave") == 0) {
      if (TRUE) {
	printf("The table is empty\n");
      } else {
	// TO BE IMPLEMENTED
	printf("The average of score is %d\n", 1);
      }
    } else if (strcmp(input,"insert") == 0) {
      // TO BE IMPLEMENTED
    } else if (strcmp(input,"init") == 0) {
      // TO BE IMPLEMENTED
    } else if (strcmp(input,"rank") == 0) {
      if (TRUE) {        
	printf("The table is empty\n");
      } else {
	// TO BE IMPLEMENTED
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

