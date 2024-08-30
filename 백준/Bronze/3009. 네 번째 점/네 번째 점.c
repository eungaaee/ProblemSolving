main() {
	int a,b,c,d;
	scanf("%d%d", &c,&d);
	a=c, b=d;
	scanf("%d%d", &c,&d);
	a = a-c?a+c:a-c;
	b = b-d?b+d:b-d;
	scanf("%d%d", &c,&d);
	printf("%d %d", a?a-c:c, b?b-d:d);
}