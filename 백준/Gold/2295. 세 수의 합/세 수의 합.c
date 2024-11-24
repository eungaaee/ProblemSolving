#include <stdio.h>
#include <stdlib.h>

int compare(const void *a, const void *b) {
    return *(int *)a - *(int *)b;
}

_Bool binary_search(int arr[], int size, int target) {
    int left = 0, right = size-1, mid;

    while (left <= right) {
        mid = (left + right) / 2;
        
        if (arr[mid] < target) left = mid+1;
        else if (arr[mid] > target) right = mid-1;
        else return 1;
    }

    return 0;
}

int main() {
    int N;
    scanf("%d", &N);

    int U[N];
    for (int i = 0; i < N; i++) {
        scanf("%d", U+i);
    }

    int sum_of_two[N*(N+1)/2], sum_idx = 0;
    for (int i = 0; i < N; i++) {
        for (int j = i; j < N; j++) {
            sum_of_two[sum_idx++] = U[i] + U[j];
        }
    }

    qsort(U, N, sizeof(int), compare);
    qsort(sum_of_two, sum_idx, sizeof(int), compare);

    for (int i = N-1; i >= 0; i--) {
        for (int j = i; j >= 0; j--) {
            int target = U[i] - U[j];
            
            if (binary_search(sum_of_two, sum_idx, target)) {
                printf("%d", U[i]);
                return 0;
            }
        }
    }

    return 1;
}