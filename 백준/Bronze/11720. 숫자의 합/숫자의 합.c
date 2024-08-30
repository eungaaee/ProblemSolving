#include <stdio.h>
int main() {
	int n, s=0;
	char k[100];
	scanf("%d%s", &n, &k);
	for (int i=0; i<n; i++) {
		s += (int)k[i]-48;
	}
	printf("%d", s);
}