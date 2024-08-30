main() {
	int n, a, b, la=-10000, sa=10000, lb=-10000, sb=10000;
	scanf("%d", &n);
	while (n--) {
		scanf("%d%d", &a, &b);
		la = a>la?a:la;
		sa = a<sa?a:sa;
		lb = b>lb?b:lb;
		sb = b<sb?b:sb;
	}
	printf("%d", (la-sa)*(lb-sb));
}