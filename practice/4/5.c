#include <stdio.h>

int stackArea(int, int, int, int);
int min_unused_area(int, int,int ,int);
float min_perimeter(int, int);

int main(void) {
	int trayHeight, trayWidth, slabHeight, slabWidth;

	printf("Enter size of tray: ");
	scanf("%d %d", &trayHeight, &trayWidth);

	printf("Enter size of slab: ");
	scanf("%d %d", &slabHeight, &slabWidth);

	printf("Minimum unused area = %d\n", min_unused_area(stackArea(trayHeight, trayWidth, slabHeight, slabWidth), stackArea(trayHeight,trayWidth,slabWidth,slabHeight), trayHeight, trayWidth)); // incomplete

	printf("Minimum perimeter after folding = %.2f\n", min_perimeter(trayHeight, trayWidth)); // incomplete

	return 0;
}

int stackArea(int trayHeight, int trayWidth, int slabHeight, int slabWidth) {
	int row, cols, area;

	row = trayHeight / slabHeight;
	cols = trayWidth / slabWidth;

	area = row * cols * slabHeight * slabWidth;

	return area;
}


int min_unused_area(int vert, int hori, int trayHeight, int trayWidth) {
	int unused1, unused2;

	unused1 = trayHeight * trayWidth - vert;
	unused2 = trayHeight * trayWidth - hori;

	if (unused1 > unused2)
		return unused2;

	return unused1;
}

float min_perimeter(int height, int width) {
	int i;
	float h , w;
	h = (float) height;
	w = (float) width;

	for (i = 0; i < 3; i++) {
		if (h > w) 
			h /= 2;
		else
			w /= 2;
	}

	return 2*h + 2*w;
}
