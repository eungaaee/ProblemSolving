#include <stdio.h>
int main() {
	double s, ss, ts=0, ms=0;
	char g[3], n[51];
	for (int i=0; i<20; i++) {
		scanf("%s%lf%s", n, &s, g);
		if (g[0]=='P')
			continue;
		ts+=s;
		if (g[0]=='A')
			ss = 4.0;
		else if (g[0]=='B')
			ss = 3.0;
		else if (g[0]=='C')
			ss = 2.0;
		else if (g[0]=='D')
			ss = 1.0;
		else
			ss = 0.0;
		if (g[1]=='+')
			ss += 0.5;
		ms += s*ss;
	}
	printf("%lf", ms/ts);
}