/**
 * CS1010 AY2019/20 Semester 1 Lab1 Ex2
 * box.c
 * This program will take the length, width and height of a box and find
 * the surface area of the box and the length of the diagonal between the 
 * two vertices that are furthest apart.
 * Kingston Kuan Jun Xiang
 * C09
 */

#include <stdio.h>
#include <math.h>

int compute_surface_area(int, int, int);
double compute_diagonal(int, int, int);

int main(void) {

	int length, width, height;

	printf("Enter length: ");
	scanf("%d", &length);

	printf("Enter width : ");
	scanf("%d", &width);

	printf("Enter height: ");
	scanf("%d", &height);

	printf("Surface area = %d\n", compute_surface_area(length, width, height));
	printf("Diagonal = %.2f\n", compute_diagonal(length, width, height));

	return 0;
}

// This function will take in the length, width and height of a box and compute its surface area.
int compute_surface_area(int length, int width, int height) {
	int surface_area = 2*(length*width + width*height + height*length);
	return surface_area;
}

// This function will take in the length, width and height of a box and compute the diagonal between the two furthest apart vertices.
double compute_diagonal(int length, int width, int height) {
	double diagonal = sqrt(pow(length,2.0) + pow(width,2.0) + pow(height, 2.0));
	return diagonal;
}
