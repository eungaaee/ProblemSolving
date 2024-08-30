#include <stdio.h>
int main() {
	char s[15];
	int t=0, k;
	scanf("%s", s);
	for (int i=0; s[i]!=0; i++) {
		k = s[i]-65;
		if (k<3) {
			t+=3;
		} else if (k<6) {
			t+=4;
		} else if (k<9) {
			t+=5;
		} else if (k<12) {
			t+=6;
		} else if (k<15) {
			t+=7;
		} else if (k<19) {
			t+=8;
		} else if (k<22) {
			t+=9;
		} else if (k<26) {
			t+=10;
		}
	}
	printf("%d", t);
}