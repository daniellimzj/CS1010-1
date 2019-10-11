#include <stdio.h>

int get_magic(int);

int main(void) {
	int num1, num2;
	printf("Enter 1st value: ");
	scanf("%d", &num1);
	int magic1 = get_magic(num1);
	printf("Magic number = %d\nEnter 2nd value: ", magic1);
	scanf("%d", &num2);
	int magic2 = get_magic(num2);
	printf("Magic number = %d\n", magic2);

	return 0;
}

int get_magic(int num){
	int magic;
	
	magic = (num/10000 + (num/100)%10 + num%10)%10;

	return magic;
}
