main() {
	int x,y,w,h;
	scanf("%d%d%d%d", &x,&y,&w,&h);
	printf("%d", (w-x>x?x:w-x)>(h-y>y?y:h-y)?(h-y>y?y:h-y):(w-x>x?x:w-x));
}