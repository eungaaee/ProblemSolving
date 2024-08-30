#include <stdio.h>
int main(t,i) {
	int M=0;
	for (int k = 0; k < 9; k++) {
		scanf("%d", &t);
		if (t > M) {
			M=t;
			i=k;
		}
	}
	printf("%d %d", M,i+1);
}