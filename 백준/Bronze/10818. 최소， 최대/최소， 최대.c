#include <stdio.h>
int main(n) {
	int m=1000000, M=-1000000, k;
	scanf("%d", &n);
	for (int i=0; i<n; i++) {
		scanf("%d", &k);
		m = m>k?k:m;
		M = M>k?M:k;
	}
	printf("%d %d", m, M);
}