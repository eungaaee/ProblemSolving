#include <stdio.h>
int main(n,x) {
	int t;
	scanf("%d%d", &n,&x);
	for (int i = 0; i < n; i++) {
		scanf("%d", &t);
		if (t < x)
			printf("%d ", t);
	}
}