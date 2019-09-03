/**
 * CS1010 AY2019/20 Semester 1 Lab1 Ex1
 * invest.c
 * This program calculates the final amount given principal amount,
 * interest rate, and number of years, based on compound interest.
 * Kingston Kuan Jun Xiang
 * C09
 */

#include <stdio.h>
#include <math.h>

int main(void) {
	int principal, rate, numYears;

	printf("Enter principal amount: ");
	scanf("%d", &principal);

	printf("Enter interest rate   : ");
	scanf("%d", &rate);

	printf("Enter number of years : ");
	scanf("%d", &numYears);

	float amtEarned = (principal * (1.0 - pow((rate / 100.0),(numYears + 1.0)))) / (1.0 - (rate / 100.0));

	printf("Amount = $%.2f\n", amtEarned);

	return 0;
}

