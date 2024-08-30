#include <stdio.h>
int main(n,m,i,j,k) {
	int a[100] = {0};
	scanf("%d%d", &n, &m);
	for (int p = 0; p < m; p++) {
		scanf("%d%d%d", &i, &j, &k);
		i--;
		for (; i < j; i++) {
			a[i] = k;
		}
	}
	for (int p = 0; p < n; p++) {
		printf("%d ", a[p]);
	}
}