#include <stdio.h>
int main() {
	int t, k, n;
	scanf("%d", &t);
	while (t--) {
		int a[14] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14};
		int b[14] = {0,};
		scanf("%d %d", &k, &n);
		for (int i=0; i<k; i++) {
			for (int j=0; j<n; j++) {
				for (int h=0; h<=j; h++) {
					b[j] += a[h];
				}
			}
			for (int j=0; j<n; j++) {
				a[j] = b[j];
				b[j] = 0;
			}
		}
		printf("%d\n", a[n-1]);
	}
}