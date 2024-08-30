#include <stdio.h>
int main() {
	int n;
	scanf("%d", &n);
	for (int i=0; i<n; i++) {
		if (i + i/1000000 + i%1000000/100000 + i%100000/10000 + i%10000/1000 + i%1000/100 + i%100/10 + i%10==n) {
			printf("%d", i);
			return 0;
		}
	}
	printf("%d", 0);
}