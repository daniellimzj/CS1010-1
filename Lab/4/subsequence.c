/**
 * CS1010 AY2019/20 Semester 1 Lab4 Ex2
 * subsequence.c
 * This program reads in a list of integers and find the
 * k-interval subsequence with the largest sum.
 * Kingston Kuan Jun Xiang
 * C09
 */

#include <stdio.h>

int scan_list(int[]);
void sum_subsequence(int[], int, int[]);

int main(void)
{
	int list[10], size; // array and actual number of elements entered
	int answers[3];		// stores the required answers

	size = scan_list(list);

	sum_subsequence(list, size, answers);

	printf("Max sum %d of %d-interval subsequence starting at position %d.\n",
		   answers[0], answers[1], answers[2]);

	return 0;
}

// Read in elements for the array arr and returns the
// number of elements read.
// Postcond: i > 0
int scan_list(int arr[])
{
	int num, i;

	printf("Enter number of elements: ");
	scanf("%d", &num);
	printf("Enter %d element%s: ", num, (num > 1) ? "s" : "");
	for (i = 0; i < num; i++)
	{
		scanf("%d", &arr[i]);
	}

	return num;
}

// This function splits the sequence into subsequences of different intervals and finds which has the highest sum.
// ans[0] = maximum sum of solution subsequence
// ans[1] = interval k of the solution subsequence
// ans[2] = start position of the solution subsequence
void sum_subsequence(int arr[], int size, int ans[])
{
	int k, i, j, sum = 0;

	// Start from 1 interval subsequence until a max size interval subsequence.
	for (k = 1; k <= size; k++) {
		// Repeat for different starting positions k times.
		for (i = 0; i < k; i++) {
			// Move the position by k spaces and sum the values.
			for (j = 0; j < size; j += k) {
				sum += arr[j];
			}

			// If the sum is higher than the current max, replace the values in ans.
			if (sum > ans[0]) {
				ans[0] = sum;
				ans[1] = k;
				ans[2] = j;
			}

			// Reset the sum to 0 for the next subsequence.
			sum = 0;
		}
	}
}
