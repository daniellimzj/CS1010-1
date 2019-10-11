#include <stdio.h>

int is_prime(int);

int main(void){
	int num;

	printf("Enter a positive integer: ");
	scanf("%d", &num);

	if(is_prime(num)){
		printf("%d is a prime.\n", num);
	} else {
		printf("%d is not a prime.\n", num);
	}
	
	return 0;
}

int is_prime(int num){
	int i;
	for (i = num - 1; i > 1; i--){
		if (num % i == 0){
			return 0;
		}
	}

	return 1;
}
