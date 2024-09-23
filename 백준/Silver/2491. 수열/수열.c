#include <stdio.h>

int main() {
    int N;
    scanf("%d", &N);

    int prev, cur, increase = 1, decrease = 1, longest = 1;
    scanf("%d", &prev);
    for (int i = 1; i < N; i++) {
        scanf("%d", &cur);

        if (prev <= cur) increase++;
        else {
            if (increase > longest) longest = increase; 
            increase = 1;
        }

        if (prev >= cur) decrease++; 
        else {
            if (decrease > longest) longest = decrease;
            decrease = 1;
        }

        prev = cur;
    }

    if (increase > longest) longest = increase; 
    if (decrease > longest) longest = decrease;

    printf("%d", longest);

    return 0;
}