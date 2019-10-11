/**
 * CS1010 AY2019/20 Semester 1 Lab3 Ex1
 * candles.c
 * This aim of this program is to figure out the total number of candles that can be burnt given an initial
 * number of candles and the number of residuals from candles burnt that can make a new candle.
 * Kingston Kuan Jun Xiang
 * C09
 */

#include <stdio.h>

int count_candles(int, int);

int main(void) {
	int candles, residuals, burnt;

	printf("Enter number of candles and \n");
	printf("number of residuals to make a new candle: ");

	scanf("%d %d", &candles, &residuals);

	// Call the function count_candles to find the number of candles burnt.
	burnt = count_candles(candles, residuals);

	printf("Total candles burnt = %d\n", burnt);

	return 0;
}

/**
 * This function takes the number of candles and the number of residuals
 * that make a new candle to compute and return the total number of candles that can be burnt.
 * Precondition: candles >= 0, residuals > 0
 */
int count_candles(int candles, int residuals){
	int count = 0;

	// Repeat the burning process while the number of candles is still enough to make a new candle from residuals.
	while(candles >= residuals) {
		// Candles left after residuals are burnt and made into a new candle.
		candles = candles - residuals + 1; 		

		// Add in the candles burnt for residuals into the count.
		count += residuals;
	} 
	// Add the last few candles that cannot make a new candle into the count.
	count += candles;

	return count;
}
