#include <stdio.h>
#include <stdlib.h>

int compare(const void *a, const void *b) {
    return *(int *)a - *(int *)b;
}

int main() {
    int N;
    scanf("%d", &N);

    int value[N];
    for (int i = 0; i < N; i++) scanf("%d", value+i);

    qsort(value, N, sizeof(int), compare);

    int min_left_value = 1e9, min_right_value = 1e9;
    int left = 0, right = N-1;

    while (left < right) {
        if (abs(value[left] + value[right]) < abs(min_left_value + min_right_value)) {
            min_left_value = value[left];
            min_right_value = value[right];
        }

        if (value[left] + value[right] < 0) left++;
        else if (value[left] + value[right] > 0) right--;
        else break;
    }

    printf("%d %d", min_left_value, min_right_value);

    return 0;
}