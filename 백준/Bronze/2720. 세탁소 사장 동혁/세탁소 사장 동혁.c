main() {
	int t, c;
	scanf("%d", &t);
	while (t--) {
		scanf("%d", &c);
		printf("%d %d %d %d\n", c/25, c%25/10, c%25%10/5, c%25%10%5/1);
	}
}