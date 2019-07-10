#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>

double what(double num1, double num2, double num3) {
    int mid = num1;
	(mid < num2) && (mid < num3) && (mid = num2);//if max < b then it will run max = b
	(mid > num2) && (mid > num3) && (mid = num2);

    (mid < num1) && (mid < num2) && (mid = num3);//if max < c then it will run max = c
	(mid > num1) && (mid > num2) && (mid = num3);
    
    return mid;
}

int main(void)
{
    printf("%.1f", what(2.0 , 2.0, 1.0));
}
