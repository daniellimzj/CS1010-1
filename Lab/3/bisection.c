/**
 * CS1010 AY2019/20 Semester 1 Lab3 Ex3
 * bisection.c
 * Kingston Kuan Jun Xiang
 * C09
 * This program uses the Bisection method to find a root of a 3 degree polynomial between two endpoints of different signs.
 */

#include <stdio.h>
#include <math.h>

#define THRESHOLD 0.0001 // define the threshold value for the difference between a and b


double polynomial(double, int, int, int, int);

int main(void) {
	int    c3, c2, c1, c0; // coefficients of polynomial
	double a, b,           // endpoints
		   pA, pB;         // function values at endpoints
	double m, pM;          // midpoint and function value at midpoint

	printf("Enter coefficients (c3,c2,c1,c0) of polynomial: ");
	scanf("%d %d %d %d", &c3, &c2, &c1, &c0);

	printf("Enter endpoints a and b: ");
	scanf("%lf %lf", &a, &b);

	// Get the first function value of the midpoint;
	m = (a+b)/2;
	pM = polynomial(m, c3, c2, c1, c0);

	// Repeat the bisection until pM is 0 or the difference between a and b is less than the threshold.
	while (pM != 0 && fabs(a-b) > THRESHOLD) {
		pA = polynomial(a, c3, c2, c1, c0);
		pB = polynomial(b, c3, c2, c1, c0);

		// Find which endpoint to replace with the midpoint by comparing the signs of their function values.
		if ((pA < 0 && pB > 0 &&  pM > 0) || (pA > 0 && pB < 0 && pM < 0)) {
			b = m;
		}
		else {
			a = m;
		}

		m = (a+b)/2;
		pM = polynomial(m, c3, c2, c1, c0);
	}

	printf("root = %.6lf\n", m);
	printf("p(root) = %.6lf\n", pM);

	return 0;
}

// This function calculates the y value of a 3 degree polynomial given its coefficients and an x value.
double polynomial(double xVal, int c3, int c2, int c1, int c0) {
	double yVal;

	// Find the corresponding y value using the polynomial equation.
	yVal = c3 * pow(xVal, 3) + c2 * pow(xVal, 2) + c1 * xVal + c0;

	return yVal;
}
