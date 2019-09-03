#include <stdio.h>

int main(void){
	printf("Enter hours and minutes since power failure: ");

	int h, m;

	scanf("%d %d", &h, &m);

	float t = h + (m/60.0);

	float T = ((4*(t*t))/(t+2))-20;

	printf("Temperature in freezer = %.2f\n", T);

	return 0;
}
