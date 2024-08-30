#include <stdio.h>
int main() {
	int a[9][9];
	int m=0, mi, mj;
	for (int i=0; i<9; i++) {
		for (int j=0; j<9; j++) {
			scanf("%d", &a[i][j]);
			if (a[i][j]>=m) {
				m=a[i][j];
				mi=i;
				mj=j;
			}
		}
	}
	printf("%d\n%d %d", m, mi+1, mj+1);
}