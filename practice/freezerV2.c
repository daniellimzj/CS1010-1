#include <stdio.h>
#include <math.h>

int main(void){
	printf("Enter hours and minutes since power failure: ");

	int h, m;

	scanf("%d %d", &h, &m);

	double t = h + (m/60.0);

	double T = ((4*(pow(t,10.0)))/(pow(t,9.0)+2))-20;

	printf("Temperature in freezer = %.2f\n", T);

	return 0;
}
