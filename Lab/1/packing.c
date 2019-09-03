/**
 * CS1010 AY2017/8 Semester 1 Lab1 Ex3
 * packing.c
 * Given the dimensions of a tray and a slab, this program aims to find
 * the maximum number of slabs that can fit into the tray.
 * Kingston Kuan Jun Xiang
 * C09
 */

#include <stdio.h>

int compute_max_slabs(int, int, int, int);

int main(void) {
	int max_slabs, tray_length, tray_width, slab_length, slab_width;

	printf("Enter dimension of tray: ");
	scanf("%d %d", &tray_length, &tray_width);

	printf("Enter dimension of slab: ");
	scanf("%d %d", &slab_length, &slab_width);
	
	max_slabs = compute_max_slabs(tray_length, tray_width, slab_length, slab_width);
	
	printf("Maximum number of slabs = %d\n", max_slabs);

	return 0;
}

// This function will take in the tray and slab dimensions and compute
// the maximum number of slabs that can fit into the tray.
int  compute_max_slabs(int tray_length, int tray_width, int slab_length, int slab_width){
	int rows, cols, vertical_max, horizontal_max;
	
	// If we were to arrange the slabs vertically.
	rows = tray_length / slab_length;
	cols = tray_width / slab_width;
	vertical_max = rows * cols;

	// If we were to arrange the slabs horizontally.
	rows = tray_length / slab_width;
	cols = tray_width / slab_length;
	horizontal_max = rows * cols;

	// Find which max is higher and return that number.
	if (vertical_max > horizontal_max) {
		return vertical_max;
	}

	return horizontal_max;
}
