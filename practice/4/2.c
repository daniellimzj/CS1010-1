#include <stdio.h>

int main(void)
{
	int i, temp, count = 0, factor, mustHave, participants;
	printf("Enter factor-digit: ");
	scanf("%d", &factor);
	printf("Enter must-have-digit: ");
	scanf("%d", &mustHave);
	printf("Enter number of participants: ");
	scanf("%d", &participants);

	for (i = 1; i <= participants; i++) {
		if (i % factor == 0) {
			temp = i;
			while (temp > 0) {
				if (temp % 10 == mustHave) {
					count++;
					break;
				}
				temp /= 10;
			}
		}
	}

	printf("Number of winners: %d\n", count);
	return 0;
}
