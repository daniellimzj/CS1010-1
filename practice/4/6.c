#include <stdio.h>
#include <math.h>

#define WEEKDAYFOURSEVEN 2.00
#define WEEKDAYSEVENSIX 1.20
#define WEEKDAYSIXMID 5.00
#define SATURDAYFOURSEVEN 2.50
#define SATURDAYSEVENSIX 1.50
#define SATURDAYSIXMID 7.00

double computeFee(int, int, int);
double timeFourSeven(double, double);
double timeSevenSix(double, double);
double timeToHours(int);

int main(void){
	int day, timeIn, timeOut;
	double fee;

	printf("Enter day: ");
	scanf("%d", &day);

	printf("Enter time-in: ");
	scanf("%d", &timeIn);

	printf("Enter time-out: ");
	scanf("%d", &timeOut);

	fee = computeFee(day, timeIn, timeOut);

	printf("Parking fee is $%.2f.\n", fee);

	return 0;
}

double computeFee(int day, int timeIn, int timeOut) {
	double fee = 0, fee47, fee76, fee6m, surcharge;

	double hourIn = timeToHours(timeIn);
	double hourOut = timeToHours(timeOut);

	if ((hourOut*60 - hourIn*60) <= 10)
		return 0;

	switch (day) {
		case 6:
			fee47 = SATURDAYFOURSEVEN;
			fee76 = SATURDAYSEVENSIX;
			fee6m = SATURDAYSIXMID;
			surcharge = 20.0/100;
			break;
		case 7:
			fee += 5.00;
			fee47 = 0;
			fee76 = 0;
			fee6m = 0;
			surcharge = 0;
			break;
		default:
			fee47 = WEEKDAYFOURSEVEN;
			fee76 = WEEKDAYSEVENSIX;
			fee6m = WEEKDAYSIXMID;
			surcharge = 10.0/100;
			break;
	}

	if (timeIn > 700) {
		if (timeIn > 1800)
			fee += 5;
		else {
			if (timeOut <= 1800)
				fee += fee76 * timeSevenSix(hourIn, hourOut);
			else
				fee += fee76 * timeSevenSix(hourIn, 18) + fee6m;
		}
	}
	else {
		if (timeOut > 700) {
			fee += fee47 * timeFourSeven(hourIn, 7);
			if (timeOut > 1800)
				fee += fee76 * 22 + fee6m;
			else
				fee += fee76 * timeSevenSix(7, hourOut);
		}
		else
			fee += fee47 * timeFourSeven(hourIn, hourOut);
	}

	if (hourOut - hourIn > 10)
		fee = ((1 + surcharge) * fee);

	if (timeOut > 2200)
		fee += 3.00;

	return fee;
}

double timeFourSeven(double timeIn, double timeOut) {
	double hours = ceil((timeOut - timeIn));

	return hours;
}

double timeSevenSix(double timeIn, double timeOut) {
	double halfHours = ceil((timeOut - timeIn)/0.5);

	return halfHours;
}

double timeToHours(int time) {	
	int minutes = time % 100;
	double hours = (time / 100) + (minutes / 60.0);

	return hours;
}
