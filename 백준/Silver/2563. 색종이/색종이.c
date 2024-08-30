#include <stdio.h>
int main() {
	int n, x, y, mx=0, my=0, s=0;
	int xy[100][100] = {0};
	scanf("%d", &n);
	for (int i=0; i<n; i++) {
		scanf("%d%d", &x, &y);
		mx = mx>x+10?mx:x+10;
		my = my>y+10?my:y+10;
		for (int j=x; j<x+10; j++) {
			for (int k=y; k<y+10; k++)
				xy[j][k] = 1;
		}
	}
	for (int i=0; i<mx; i++) {
		for (int j=0; j<my; j++) {
			s += xy[i][j]>0?1:0;
		}
	}
	printf("%d", s);
}