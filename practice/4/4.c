#include <stdio.h>

int luhn_ah(int);

int main(void) {
	int uCardNo, checkNumber; 

	printf("Enter uCard Number: ");
	scanf("%d", &uCardNo);

	checkNumber = luhn_ah(uCardNo);
	printf("The check number is %d\n", checkNumber);

	if(checkNumber % 7 == 0) {
		printf("Valid\nIssued by ");
		while(uCardNo > 99) {
			uCardNo /= 10;
		}
		if (uCardNo > 30 && uCardNo < 36)
			printf("East branch\n");
		else if (uCardNo > 50 && uCardNo < 56)
			printf("West branch\n");
		else
			printf("Central branch\n");
	}
	else 
		printf("Invalid\n");


	return 0;
}

int luhn_ah(int card) {
	int sum = 0, digit;
	
	while(card != 0) {
		sum += card % 10;
		card /= 10;
		digit = 2 * (card % 10);
	//	printf("%d\n", digit);
		card /= 10;
		if (digit > 9) {
			sum += digit % 10;
			sum += digit / 10;
		}
		else
			sum += digit;
	}

	return sum;
}
