#include <stdio.h>

int compute_percentile(int);
float compute_iqscore(int, int);

int main(void) {

	int verbal, math, writing, percentile; // user's input
	float iqscore;

	printf("Enter scores: ");
	scanf("%d %d %d", &verbal, &math, &writing);

	percentile = compute_percentile(verbal + math + writing);
	iqscore = compute_iqscore(verbal, math);

	printf("The SAT score is in the %d percentile.\nThe IQ score is %.2f\n", percentile, iqscore);

	if ((math > 600 && verbal > 600 && writing > 600) || iqscore >= 120)
		printf("Wow, this is amazing!\n");

	return 0;
}

int compute_percentile(int total) {
	if (total >= 2200)
		return 99;
	else if (total >= 2000)
		return 95;
	else if (total >= 1500)
		return 50;
	else
		return 10;
}

float compute_iqscore(int verbal, int math) {
	return (0.095 * math) + (0.003 * verbal) + 50.24l;
}
