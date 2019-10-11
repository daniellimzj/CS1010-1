#include <stdio.h>

int countJumps(int [], int);

int main(void) {
	int jumps, i, num_rocks, rocks[20];            // including opposite bank

	printf("Enter number of rocks: ");
	scanf("%d", &num_rocks);

	for (i = 0; i < num_rocks; i++) 
		scanf("%d", &rocks[i]);		

	jumps = countJumps(rocks, num_rocks);

	printf("%d\n", jumps);

	return 0;
}

// Counts the minimum number of jumps the rabbit needs
// to take to get to the other side of the river.
// Precond: size > 0
int countJumps(int rocks[], int size) {
	int i, count = 0, pos = 0;
	while (pos + 50 <= rocks[size - 1]) {
		for (i = size - 1; i >= 0; i--) {
			if (rocks[i] - rocks[i-1] > 50)
				return -1;
			if (rocks[i] <= pos + 50) {
				pos = rocks[i];
				count++;
				break;
			}
		}
	}

	return count + 1; // this is just a stub; replace it with the correct value
}

