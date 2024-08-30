#include <stdio.h>
int main(n) {
	scanf("%d", &n);
	printf("%d", n%4?0:n%100?1:n%400?0:1);
}