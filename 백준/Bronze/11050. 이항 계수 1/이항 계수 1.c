#include <stdio.h>
int main() {
	//nCk
	int n, k, a=1, b=1;
	scanf("%d %d", &n, &k);
	while (k--) {
		a *= n--;
		b *= k+1;
	}
	printf("%d", a/b);
}