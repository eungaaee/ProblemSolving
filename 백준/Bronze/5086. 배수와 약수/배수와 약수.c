main() {
	int a=-1, b=-1;
	while (1) {
		scanf("%d%d", &a, &b);
		if (!a&&!b)
			return 0;
		printf("%s\n", a>b?a%b?"neither":"multiple":b%a?"neather":"factor");
	}
}