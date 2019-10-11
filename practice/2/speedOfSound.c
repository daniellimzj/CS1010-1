#include <stdio.h>
#include <math.h>

double speed_of_sound(double);

int main(void) {
	double T;

	printf("Temperature in degree Fahrenheit: ");
	scanf("%lf", &T);
	double s = speed_of_sound(T);

	printf("Speed of sound in air of %.2lf degree = %.2lf ft/sec\n", T, s);

	return 0;
}

double speed_of_sound(double T){

	double s = 1086.0*sqrt(((5.0*T)+297.0)/247.0);

	return s;
}
