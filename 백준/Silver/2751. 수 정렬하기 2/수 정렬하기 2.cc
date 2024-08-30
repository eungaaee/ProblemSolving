#include <iostream>
using namespace std;
void Merge(int *a, int left, int center, int right) {
    int b[1000000], i = left, j = center + 1, k{};
    while (i <= center && j <= right) {
        if (a[i] > a[j])
            b[k++] = a[j++];
        else
            b[k++] = a[i++];
    }
    while (i <= center)
        b[k++] = a[i++];
    while (j <= right)
        b[k++] = a[j++];
    while (k--)
        a[left + k] = b[k];
}
void MergeSort(int *a, int left, int right) {
    int center;
    if (left < right) {
        center = (left + right) / 2;
        MergeSort(a, left, center);
        MergeSort(a, center + 1, right);
        Merge(a, left, center, right);
    }
}
int main() {
    int a[1000000], n;
    cin >> n;
    for (int i = 0; i < n; i++) cin >> a[i];
    MergeSort(a, 0, n - 1);
    for (int i = 0; i < n; i++) cout << a[i] << "\n";
    return 0;
}