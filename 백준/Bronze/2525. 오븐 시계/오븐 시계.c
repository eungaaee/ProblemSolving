#include <stdio.h>

int main() {
	short a1, a2, b;
	scanf("%hd %hd", &a1, &a2);
	scanf("%hd", &b);
	while (1) {
		if (a2 + b >= 60) {
			a1++;
			b -= 60;
			if (a1 == 24) {
				a1 = 0;
			}
		}
		else {
			a2 += b;
			break;
		}
	}
	printf("%hd %hd", a1, a2);
	return 0;
}