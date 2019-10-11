/**
 * CS1010 AY2017/8 Semester 1 Lab3 Ex4
 * montecarlo.c
 * <Type your name here>
 * <Type your discussion group here>
 * <Fill in a description of this program>
 */

#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <time.h>

// Given function prototype must not be changed
int throwDarts(int);

int main(void) {
	int darts_total,   // number of darts to be thrown
	    darts_inside;  // number of darts inside quadrant

	double pi;
	
	srand(time(0));

	printf("How many darts? ");
	scanf("%d", &darts_total);

	darts_inside = throwDarts(darts_total);

	printf("Darts inside = %d\n", darts_inside);
	
	pi = (4.0*darts_inside)/darts_total;

	printf("Approximated pi = %.4lf\n", pi);

	return 0;
}

int throwDarts(int total) {
	int i, inside = 0;
	double x, y;

	for (i = 0; i < total; i++) {
		x = (double)rand()/RAND_MAX;
		y = (double)rand()/RAND_MAX;

		if (pow(x, 2) + pow(y, 2) <= 1) {
			inside++;
		}
	}

	return inside;
}

