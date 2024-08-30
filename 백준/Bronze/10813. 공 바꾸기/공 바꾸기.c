#include <stdio.h>
int main(n,m,i,j,t) {
	int a[100];
	scanf("%d%d", &n, &m);
	for (int k = 0; k < n; k++)
		a[k] = k + 1;
	for (int k = 0; k < m; k++) {
		scanf("%d%d", &i, &j);
		t = a[i-1];
		a[i-1] = a[j-1];
		a[j-1] = t;
	}
	for (int k = 0; k < n; k++) {
		printf("%d ", a[k]);
	}
}