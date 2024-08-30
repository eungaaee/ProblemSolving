#include <stdio.h>
int main() {
	int n, c=0, k=0, t;
	scanf("%d", &n);
	while (c<n) {
		k++;
		t=k;
		while (t) {
			if (t%1000==666) {
				c++;
				break;
			} else
				t /= 10;
		}
	}
	printf("%d", k);
}