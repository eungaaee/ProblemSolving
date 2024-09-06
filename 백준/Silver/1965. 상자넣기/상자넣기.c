#include <stdio.h>

int main() {
    int n, box[1000], cnt[1000], max = 0;

    scanf("%d", &n);
    for (int i = 0; i < n; i++) scanf("%d", box+i);

    for (int i = 0; i < n; i++) cnt[i] = 1;

    for (int i = 1; i < n; i++) {
        for (int j = 0; j < i; j++) {
            if (box[j] < box[i] && cnt[j]+1 > cnt[i]) cnt[i] = cnt[j]+1;
        }
        if (cnt[i] > max) max = cnt[i];   
    }

    printf("%d", max);

    return 0;
}