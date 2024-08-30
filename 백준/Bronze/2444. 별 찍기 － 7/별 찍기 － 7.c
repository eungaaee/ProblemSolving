#include <stdio.h>
int main() {
	int n, i=1, k=0;
	scanf("%d", &n);
	while (i) {
		for (int j=0; j<n-i; j++) {
			putchar(' ');
		}
		for (int j=0; j<(2*i-1); j++) {
			putchar('*');
		}
		putchar('\n');
		if (i>=n)
			k=1;
		k?i--:i++;
	}
}