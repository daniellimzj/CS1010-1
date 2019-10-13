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
#define MAX_ENTRIES 100
#define MAX_COLUMNS 2

/* Function prototypes */
void print_help();
void insert_table(int[][MAX_COLUMNS], int);
int sum(int[][MAX_COLUMNS], int);
int ave(int[][MAX_COLUMNS], int);
void rank(int[][MAX_COLUMNS], int);
void bubble_sort(int[][MAX_COLUMNS], int);

int main(void) {
  
  // The string for input command, do not modify...
  char input[MAX_COMMAND_LENGTH];

  // TO BE IMPLEMENTED
  // How to represent the table and other information...
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

void insert_table(int table[][MAX_COLUMNS], int size) {
  printf("Please input the student's ID...\n")
  scanf("%d", &table[size][0])
  printf("Please input the student's score...\n")
  scanf("%d", &table[size][1])
}

int sum(int table[][MAX_COLUMNS], int size) {
  int i, sum_score = 0;
  
  for(i = 0; i < size; i++) {
    sum_score += table[i][1];
  }

  return sum_score;
}

int ave(int table[][MAX_COLUMNS], int size) {
  int sum_score, ave_score;

  sum_score = sum(table, size);

  ave_score = sum / size;

  return ave_score;
}

void rank(int table[][MAX_COLUMNS], int size) {
  int rank;

  printf("Please input the rank (1 - %d)...\n", size);
  scanf("%d", &rank);

  while (rank > size) {
    printf("Invalid rank: %d\n", rank);
    printf("Please input the rank (1 - %d)...\n", size);
    scanf("%d", &rank);
  }

  bubble_sort(table, size);

  printf("ID: %d, Score: %d\n", table[rank][0], table[rank][1]);
}

// Bubble sort table in increasing order of score
void bubble_sort(int table[][MAX_COLUMNS], int size) {
  int i, j, limit, temp;
  
  for (limit = size-2; limit >= 0; limit--) {
    // limit is where the inner loop variable i should end
    for (i=0; i<=limit; i++) {
      if (table[i][1] > table[i+1][1]) {
        // swap table[i] with table[i+1]
        for (j = 0; j < MAX_COLUMNS; j++) {
          temp = table[i][j];
          table[i][j] = table[i+1][j];
          table[i+1][j] = temp;
        }
      }
    }
  }  
}
  