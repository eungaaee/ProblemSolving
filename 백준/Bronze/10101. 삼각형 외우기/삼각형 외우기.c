main() {
	int a, b, c;
	scanf("%d%d%d", &a,&b,&c);
	printf("%s", a+b+c-180?"Error":(a-b)*(b-c)*(c-a)?"Scalene":a-b?"Isosceles":b-c?"Isosceles":c-a?"Isosceles":"Equilateral");
}