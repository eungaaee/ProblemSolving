#include <stdio.h>
int main(t) {
	int a[30];
	for (int i = 0; i < 28; i++) {
		scanf("%d", &t);
		a[t-1] = t;
	}
	for (int i = 0; i < 30; i++) {
		if (a[i] != i+1)
			printf("%d ", i+1);
	}
}