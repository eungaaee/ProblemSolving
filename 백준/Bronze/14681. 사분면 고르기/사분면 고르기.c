#include <stdio.h>
int main(x,y) {
	scanf("%d%d", &x,&y);
	printf("%d", x>0?y>0?1:4:y>0?2:3);
}