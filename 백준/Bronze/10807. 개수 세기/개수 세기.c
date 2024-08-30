#include <stdio.h>
int main(n,v) {
	scanf("%d", &n);
	int k[100], c=0;
	for (int i = 0; i < n; i++) {
		scanf("%d", &k[i]);
	}
	scanf("%d", &v);
	for (int i=0; i<n; i++) {
		if (k[i]==v)
			c++;
	}
	printf("%d", c);
}