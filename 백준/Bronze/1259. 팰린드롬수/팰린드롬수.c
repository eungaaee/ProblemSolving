#include <stdio.h>
#include <memory.h>
int main() {
	int k, x;
	while (1) {
		int n[5] ={-1, -1, -1, -1, -1};
		int* p = n;
		scanf("%d", &k);
		if (!k)
			break;
		if (k/10000) {
			*p = k/10000;
			p++;
		}
		if (k%10000/1000) {
			*p = k%10000/1000;
			p++;
		}
		if (k%1000/100) {
			*p = k%1000/100;
			p++;
		}
		if (k%100/10) {
			*p = k%100/10;
			p++;
		}
		*p = k%10;
		x=1;
		for (int i=0; i<(p-n); i++) {
			if (n[i]!=n[p-n-i]) {
				x = 0;
				break;
			}
		}
		puts(x?"yes":"no");
	}
}