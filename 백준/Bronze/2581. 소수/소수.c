main() {
	int m, n, s=0, l, k;
	scanf("%d%d", &m, &n);
	l = n;
	m = m-1?m:2;
	for (int i=m; i<=n; i++) {
		k=1;
		for (int j=2; j<i; j++) {
			if (i%j==0)
				k=0;
		}
		if (k) {
			s+=i;
			l = i<l?i:l;
		}
	}
	if (s)
		printf("%d\n%d", s, l);
	else
		puts("-1");
}