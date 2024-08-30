main() {
	int n,b,o,i;
	char a[100];
	scanf("%d%d", &n,&b);
	while (n>0) {
		o = n%b;
		n /= b;
		a[i++] = o>9?o+55:o+48;
	}
	for (int j=i-1; j>=0; j--)
		putchar(a[j]);
}