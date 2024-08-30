#include <stdio.h>
#include <string.h>
int main() {
	char N[1000];
	int B, len, t=1, k=0;
	scanf("%s%d", N, &B);
	len = strlen(N);
	for (int i=1; i<=len; i++) {
		if (N[len-i]<='9') {
			k += t*(N[len-i]-48);
		} else if (N[len-i]>='A') {
			k += t*(N[len-i]-55);
		}
		t *= B;
	}
	printf("%d", k);
}