#include <algorithm>
#include <cstdio>
using namespace std;
int main() {
    int n, t, s = 0, arr[500000], freq[8001], max = 0, maxidx, isDuplicated = 0;
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &t);
        s += t;
        arr[i] = t;
        freq[t + 4000]++;
    }
    sort(arr, arr + n);
    for (int i = 0; i <= 8000; i++) {
        if (freq[i] > max) {
            isDuplicated = 0;
            max = freq[i];
            maxidx = i;
        } else if (freq[i] == max && max != 0) {
            isDuplicated = 1;
        }
    }
    if (isDuplicated) {
        freq[maxidx] = 0;
        max = 0;
        for (int i = 0; i <= 8000; i++) {
            if (freq[i] > max) {
                max = freq[i];
                maxidx = i;
            }
        }
    }
    printf("%.0lf\n%d\n%d\n%d", (double)s / n < 0 && (double)s / n > -1 ? -((double)s / n) : (double)s / n, arr[(n - 1) / 2], maxidx - 4000, arr[n - 1] - arr[0]);
    return 0;
}