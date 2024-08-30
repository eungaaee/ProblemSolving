main() {
	int n, k, c;
	scanf("%d", &n);
	c = n;
	while (n--) {
		scanf("%d", &k);
		if (k==1) {
			c--;
			continue;
		}
		for (int i=2; i<k; i++) {
			if (k%i==0) {
				c--;
				break;
			}
		}
	}
	printf("%d", c);
}