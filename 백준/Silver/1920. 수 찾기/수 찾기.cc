#include <algorithm>
#include <cstdio>
using namespace std;
void binarySearch(int arr[], int n, int key) {
    int start = 0, end = n;
    while (end - start >= 0) {
        int mid = (start + end) / 2;
        if (key == arr[mid]) {
            puts("1");
            return;
        } else if (key < arr[mid]) {
            end = mid - 1;
        } else {
            start = mid + 1;
        }
    }
    puts("0");
}
int main() {
    int n, m, arr[100000], t;
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }
    sort(arr, arr + n);
    scanf("%d", &m);
    for (int i = 0; i < m; i++) {
        scanf("%d", &t);
        binarySearch(arr, n - 1, t);
    }
    return 0;
}