main() {
	int n, k, i, c=0;
	scanf("%d%d", &n, &k);
	for (i=1; i<=n; i++) {
		if (!(n%i)) {
			c++;
			if (c==k)
				break;
		}
	}
	printf("%d", c-k?0:i);
}