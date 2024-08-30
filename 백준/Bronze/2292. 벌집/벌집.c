main() {
	long int n;
	int k=1, i=2;
	scanf("%d", &n);
	while (k*6<n-1)
		k+=i++;
	printf("%d", n-1?i:1);
}