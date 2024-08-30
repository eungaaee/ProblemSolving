#include <stdio.h>

int main() {
	int n, a, b, t;
	scanf("%d", &n);

	for (int i = 0; i < n; i++) {
		scanf("%d %d", &a, &b);
		t = a;
		for (int j = 1; j < b; j++) {
			t = t * a % 10;
		}
		if (t % 10 == 0) {
			printf("%d\n", 10);
		}
		else {
			printf("%d\n", t % 10);
		}
	}
	return 0;
}