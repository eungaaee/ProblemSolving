#include <stdio.h>
#include <string.h>

int main() {
	char a[30];
	char r[226] = "";
	for (int i = 0; i < 15; i++) {
		gets(a);
		for (int i = 0; a[i] != '\0'; i++) {
			if (a[i] != ' ') {
				char temp[2] = {a[i], '\0'};
				strcat(r, temp);
			}
		}
	}
	for (int i = 0; r[i] != '\0'; i++) {
		switch (r[i])
		{
		case 'w':
			printf("chunbae");
			return 0;
		case 'b':
			printf("nabi");
			return 0;
		case 'g':
			printf("yeongcheol");
			return 0;
		default:
			break;
		}
	}
}