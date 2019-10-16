/**
 * CS1010 AY2019/20 Semester 1 Lab4 Ex3
 * frogs.c
 * This program simulates two groups of frogs crossing a bridge where there is one empty space
 * and each frog can only either jump left or right but can jump one or two spaces.
 * Kingston Kuan Jun Xiang
 * C09
 */

#include <stdio.h>

void printBridge(int, int[]);
int jump(int, int, int[]);
void swapPosition(int, int, int[]);
int checkGameState(int, int[]);

int main(void) {

	int bridge[1000];
	int i;
	int lengthOfBridge;
	int position, jumpState;

	int numMoves = 0;
	int gameState;

	printf("Please enter the length of the bridge: ");
	scanf("%d", &lengthOfBridge);

	for (i=0; i<lengthOfBridge; i++) {
		int frogType;

		printf("Please insert frogs at position %d: ", i);
		scanf("%d", &frogType);

		bridge[i] = frogType;
	}

	printf("Input completed\n");
	printBridge(lengthOfBridge, bridge);

	printf("Please start moving the frogs\n");

	gameState = checkGameState(lengthOfBridge, bridge);

	// Repeat the simulation while the gameState is still 0.
	while (gameState == 0) {
		printf("Move the frog at position: ");
		scanf("%d", &position);

		// Store the result of the jump if it was valid or invalid.
		jumpState = jump(position, lengthOfBridge, bridge);
		if (jumpState == 1) {
			numMoves++;
			printBridge(lengthOfBridge, bridge);
		}
		else {
			printf("Invalid move!\n");
		}

		// Find the new gameState to end the game or keep on going.
		gameState = checkGameState(lengthOfBridge, bridge);
	}

	// Print the result based on the last gameState.
	if (gameState == 1)
		printf("Congratulations! The frogs took %d jumps to cross the bridge!\n", numMoves);
	else
		printf("Oh no! It seems like the two clans of frogs are stuck!\n");

	return 0;
}

//This function is provided for you
/**
 * Prints out the current state on the bridge
 * @param size (int) represents the size of bridge
 * @param bridge[] contains the current state of the bridge
 **/
void printBridge(int size, int bridge[]) {

	int i;
	printf("Position: ");
	for (i=0; i<size; i++) {
		printf("%2d ", i);
	}
	printf("\n");

	printf("Bridge:   ");
	for (i=0; i<size; i++) {
		printf("%2d ", bridge[i]);
	}
	printf("\n");
}

// This function allows the frog at the selected position to jump.
// If it cannot jump anywhere, an invalid state will be returned.
int jump(int position, int size, int bridge[]) {
	if (bridge[position] == 1) {
		// If the frog facing right is at the last position the move is invalid.
		if (position == size)
			return 0;

		// If the next position on the right is empty, move there.
		if (bridge[position + 1] == 0) {
			swapPosition(position, position + 1, bridge);
			return 1;
		}

		// If it is in the second last position and the last position isn't empty then the move is invalid.
		if (position == size - 1)
			return 0;

		// If the position 2 spaces on the right is empty, move there.
		if (bridge[position + 2] == 0) {
			swapPosition(position, position + 2, bridge);
			return 1;
		}
	}

	if (bridge[position] == -1) {
		// If the frog facing left is at the first position the move is invalid.
		if (position == 0)
			return 0;

		// If the next position on the left is empty, move there.
		if (bridge[position - 1] == 0) {
			swapPosition(position, position - 1, bridge);
			return 1;
		}

		// If it is in the second position and the first position isn't empty then the move is invalid.
		if (position == 1)
			return 0;

		// If the position 2 spaces on the left is empty, move there.
		if (bridge[position - 2] == 0) {
			swapPosition(position, position - 2, bridge);
			return 1;
		}
	}

	// If none of the correct conditions are met, return 0 for invalid move.
	return 0;
}

// This function swaps the position of two frogs on the bridge.
void swapPosition(int pos1, int pos2, int bridge[]) {
	int temp;

	temp = bridge[pos1];
	bridge[pos1] = bridge[pos2];
	bridge[pos2] = temp;
}

// This function will check whether the game has ended and what the result is.
// Precond: There is only 1 empty space.
int checkGameState(int size, int bridge[]) {
	int i, empty, leftCheck = 1, rightCheck = 1;

	// Firstly, find the position of the empty space.
	for (i = 0; i < size; i++) {
		if (bridge[i] == 0) {
			empty = i;
			break;
		}
	}

	// This first part checks if all frogs have made it across the bridge.
	// If there is a frog facing right on the left of the empty space, not all have made it across.
	for (i = empty; i >= 0; i--) {
		if (bridge[i] == 1)
			leftCheck = 0;
	}

	// If there is a frog facing left on the right of the empty space, not all have made it across.
	for (i = empty; i < size; i++) {
		if (bridge[i] == -1)
			rightCheck = 0;
	}

	// If both checks are unchanged, the frogs have made it across.
	if (rightCheck + leftCheck == 2) {
		return 1;
	}

	// The next part will check if the frogs are stuck.
	// If both spaces on the left of the empty space have frogs facing left, neither of can jump to it.
	// Also need to check if the empty space is at or near the start.
	if (bridge[empty - 1] == -1 && (empty == 1 || (empty > 1 && bridge[empty - 2] == -1)))
		leftCheck = -1;

	// If both spaces on the right of the empty space have frogs facing right, neither of can jump to it.
	// Also need to check if the empty space is at or near the end.
	if (bridge[empty + 1] == 1 && (empty == size - 2 || (empty < size - 2 && bridge[empty + 2] == 1)))
		rightCheck = -1;

	// If none of the frogs on the 2 left and right spaces next to the empty space can jump to it, they are stuck.
	if ((leftCheck + rightCheck == -2) || (empty == 0 && rightCheck == -1) || (empty == size - 1 && leftCheck == -1))
		return -1;

	// If neither end states are true, return 0 to keep the simulation running
	return 0;
}
