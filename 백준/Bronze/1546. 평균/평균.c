#include <stdio.h>
int main() {
	int n, k, M=0, a=0;
	scanf("%d", &n);
	for (int i=0; i<n; i++) {
		scanf("%d", &k);
		M = M>k?M:k;
		a += k*100;
	}
	printf("%.14lf", (double)a/M/n);
}