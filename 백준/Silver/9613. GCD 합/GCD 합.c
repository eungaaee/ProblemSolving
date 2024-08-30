#include <stdio.h>

int GCD(int x, int y) { // x > y
    int r;
    while (y) {
        r = x%y;
        x = y;
        y = r;
    }
    return x;
}

int main() {
    int t;
    scanf("%d", &t);
    while (t--) {
        int n, nums[100];
        scanf("%d", &n);
        for (int i = 0; i < n; i++) scanf("%d", nums+i);

        unsigned long long sum = 0;
        for (int i = 0; i < n-1; i++) {
            for (int j = i+1; j < n; j++) {
                sum += GCD(nums[i], nums[j]);
            }
        }
        printf("%llu\n", sum);
    }
    return 0;
}