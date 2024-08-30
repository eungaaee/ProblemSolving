int main() {
	int x, i, c=0, a, b;
	scanf("%d", &x);
	for (i=1; x>0; i++) {
		x-=i;
		c++;
	}
	a = c+x;
	b = c-a+1;
	printf("%d/%d", c%2?b:a, c%2?a:b);
}