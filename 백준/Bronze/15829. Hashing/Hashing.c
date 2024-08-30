#include <stdio.h>
int main() {
	int l;
	long long r=1, t=0;
	char a[51];
	scanf("%d %s", &l, a);
	for (int i=0; i<l; i++) {
		t += (a[i]-96)*r;
		r = r*31%1234567891;
	}
	printf("%d", t%1234567891);
}