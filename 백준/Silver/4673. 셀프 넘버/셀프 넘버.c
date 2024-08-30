#include <stdio.h>
int main() {
    int sum, dnums[10000]={0,}, t;
    for (int i = 1; i <= 10000; i++) {
        t = 1;
        while (t <= i) {
            if (t < 10) {
                sum = t * 2;
            } else if (t < 100) {
                sum = t + t / 10 + t % 10;
            } else if (t < 1000) {
                sum = t + t / 100 + (t % 100) / 10 + (t % 100) % 10;
            } else {
                sum = t + t / 1000 + (t % 1000) / 100 + ((t % 1000) % 100) / 10 + ((t % 1000) % 100) % 10;
            }
            if (sum == i) {
                dnums[i-1] = 1;
                break;
            }
            t++;
        }
    }
    for (int i = 1; i <= 10000; i++) {
        if (dnums[i - 1] == 0) {
            printf("%d\n", i);
        }
    }
    return 0;
}