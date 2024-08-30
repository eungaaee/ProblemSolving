#include <stdio.h>
int main() {
	int n, f;
	scanf("%d", &n);
	f = n/5 + n/25 + n/125;
	printf("%d", f);
}