main() {
	int n, i, t, *p;
	while (1) {
		int a[100000]={0};
		p=a;
		t=0;
		scanf("%d", &n);
		if (!(n+1))
			break;
		for (i=1; i<n; i++) {
			if (!(n%i)) {
				*p = i;
				t += i;
				p++;
			}
		}
		if (t!=n)
			printf("%d is NOT perfect.", n);
		else {
			printf("%d = 1", n);
			for (int i=1; a[i]!=0; i++) {
				printf(" + %d", a[i]);
			}
		}
		printf("\n");
	}
}