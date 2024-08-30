#include <stdio.h>
int main() {
	int a[42];
	int k, d=10;
	memset(a, -1, sizeof(int)*42);
	for (int i = 0; i < 10; i++) {
		scanf("%d", &k);
		d -= a[k%42]==k%42;
		a[k%42] = k%42;
	}
	printf("%d", d);
}