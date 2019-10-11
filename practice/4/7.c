#include <stdio.h>

int computeHappyNumbers(int, int);
int isHappy(int);

int main(void){
	int lower1, upper1, lower2, upper2, number1, number2;

	printf("Enter first range: ");
	scanf("%d %d", &lower1, &upper1);

	number1 = computeHappyNumbers(lower1, upper1);

	printf("Enter second range: ");
	scanf("%d %d", &lower2, &upper2);

	number2 = computeHappyNumbers(lower2, upper2);

	printf("The numbers of happy numbers in the two ranges are: %d %d\n", number1, number2);

	if (number1 > number2)
		printf("There are more happy numbers in the first range.\n");
	else if (number1 < number2)
		printf("There are more happy numbers in the second range.\n");
	else
		printf("The numbers of happy numbers in both ranges are the same.\n");

	return 0;
}

int computeHappyNumbers(int lower, int upper) {
	int i, count = 0;

	for (i = lower; i <= upper; i++) {
		if (isHappy(i))
			count++;
	}

	return count;
}

int isHappy(int num) {
	int sum = 0;
	while (num > 0) {
		sum += (num % 10) * (num % 10);
		num /= 10;
	}
//	printf("%d\n", sum);
	if (sum == 1)
		return 1;
	else if (sum == 0 || sum == 4 || sum == 16 || sum == 20 || sum == 37
			|| sum == 42 || sum == 58 || sum == 89 || sum == 145)
		return 0;
	return isHappy(sum);
}

