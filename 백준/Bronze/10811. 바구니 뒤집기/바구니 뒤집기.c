#include <stdio.h>
int main() {
	int a[100];
	int n, m, i, j, t;
	scanf("%d%d", &n, &m);
	for (int p = 0; p < n; p++) {
		a[p] = p+1;
	}
	for (int p = 0; p < m; p++) {
		scanf("%d%d", &i, &j);
		for (; i < j; i++,j--) {
			t = a[i-1];
			a[i-1] = a[j-1];
			a[j-1] = t;
		}
	}
	for (int p = 0; p < n; p++) {
		printf("%d ", a[p]);
	}
}