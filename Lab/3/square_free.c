/**
 * CS1010 AY2019/20 Semester 1 Lab3 Ex2
 * square_free.c
 * This program will take in two ranges of integers and find which range has a higher number of square-free
 * numbers or whether they have the same number of square-free numbers.
 * Kingston Kuan Jun Xiang
 * C09
 */

#include <stdio.h>
#include <math.h>

int check_square_free(int);
int count_square_free(int, int);

int main(void) {
	int lower1, upper1, lower2, upper2, count1, count2;

	printf("Enter four positive integers: ");
	scanf("%d %d %d %d", &lower1, &upper1, &lower2, &upper2);

	// Use the function count_square_free to count the number of square-free numbers in each range.
	count1 = count_square_free(lower1, upper1);
	count2 = count_square_free(lower2, upper2);

	// Find the range with more square-free numbers and print it.
	// If they have the same number of square-free numbers print that information as well.
	if (count1 > count2)
		printf("Range [%d, %d] has more square-free numbers: %d\n", lower1, upper1, count1);
	else if (count1 < count2)
		printf("Range [%d, %d] has more square-free numbers: %d\n", lower2, upper2, count2);
	else
		printf("Both ranges have the same number of square-free numbers: %d\n", count1);

	return 0;
}

// This function will check if a number is square-free by iterating through its factors.
int check_square_free(int number) {
	int i;

	// 1 is an exception to the rule and is sqaure-free by default.
	// We also know that 1, 2, 3 are square-free since the smallest square number that isnt 1 is 4.
	if (number < 4)
		return 1;

	// Try to find a factor greater than 3 that is a square number.
	for (i = 4; i <= number; i++) {
		// Find the factors of the number.
		if (number % i == 0) {
			// Check if the number is a square number.
			if ((int)sqrt((double)i) * (int)sqrt((double)i) == i)
				// If any factor is a square just return false.
				return 0;
		}
	}

	// If none of the factors are square numbers, then the number is square-free.
	return 1;
}

// This function will count the number of square-free numbers in a range of numbers.
int count_square_free(int lower, int upper) {
	int i, count = 0;

	// Check all integers from the lower bound to the upper bound.
	for (i = lower; i <= upper; i++) {
		if (check_square_free(i))
			// If it is square free then increment the count.
			count++;
	}

	return count;
}
