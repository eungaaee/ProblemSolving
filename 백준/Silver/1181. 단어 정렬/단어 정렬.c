#include <stdio.h>
#include <stdlib.h>
#include <string.h>
struct WORDINFO {
	int len;
	char word[51];
} wi[20001];
int strcomp(struct WORDINFO *w1, struct WORDINFO *w2) {
	return w1->len < w2->len ? -1 : w1->len > w2->len ? 1 : strcmp(w1->word,w2->word);
}
int main() {
	int n;
	scanf("%d", &n);
	for (int i=0; i<n; i++) {
		scanf("%s", wi[i].word);
		wi[i].len = strlen(wi[i].word);
	}
	qsort(wi, n, sizeof(struct WORDINFO), (int(*)(const void *, const void *))strcomp);
	for (int i=0; i<n; i++) {
		if (strcmp(wi[i].word, wi[i+1].word))
			puts(wi[i].word);
	}
}