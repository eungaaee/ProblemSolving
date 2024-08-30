#include <stdio.h>
int main() {
	char a[5][16] = {'\0'};
	for (int i=0; i<5; i++) {
		gets(a[i]);
	}
	for (int i=0; i<15; i++) {
		for (int j=0; j<5; j++) {
			if (a[j][i]!='\0')
				printf("%c", a[j][i]);
		}
	}
}