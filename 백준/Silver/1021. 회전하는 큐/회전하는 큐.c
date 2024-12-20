#include <stdio.h>
#define min(a, b) (a < b ? a : b)

int main() {
    int N, M;
    scanf("%d%d", &N, &M);

    int queue[1275]; // 1 + .. + 50 = 50(50+1)/2 = 1275
    int front = 0, back = N;

    for (int i = 0; i < N; i++) {
        queue[i] = i+1;
    }

    int count = 0;
    while (M--) {
        int target;
        scanf("%d", &target);

        int right_count = 0;

        while (queue[front] != target) {
            queue[back++] = queue[front++];
            right_count++;
        }

        int left_count = back-front - right_count;
        count += min(left_count, right_count);
        
        front++;
    }

    printf("%d", count);

    return 0;
}