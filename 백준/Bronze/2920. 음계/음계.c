#include <stdio.h>
int main() {
	int n[8];
	for (int i=0; i<8; i++) {
		scanf("%d", n+i);
		if ((n[0]==1 && n[i]!=i+1)||(n[0]==8 && n[i]!=8-i)||(n[0]!=1 && n[0]!=8)) {
			puts("mixed");
			return 0;
		}
	}
	if (n[0]==1)
		puts("ascending");
	else if (n[0]==8)
		puts("descending");
}