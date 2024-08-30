#include <cstdio>
#include <vector>
void mergeSort(std::vector<std::pair<int, int>> &v, int left, int mid, int right) {
    std::vector<std::pair<int, int>> t(right - left + 1);
    int i = left, j = mid + 1, k{};
    while (i <= mid && j <= right) {
        t[k++] = v[i] <= v[j] ? v[i++] : v[j++];
    }
    while (i <= mid) {
        t[k++] = v[i++];
    }
    while (j <= right) {
        t[k++] = v[j++];
    }
    for (int i = left; i <= right; i++) {
        v[i] = t[i - left];
    }
}
void merge(std::vector<std::pair<int, int>> &v, int left, int right) {
    if (left < right) {
        int mid = (left + right) / 2;
        merge(v, left, mid);
        merge(v, mid + 1, right);
        mergeSort(v, left, mid, right);
    }
}
int main() {
    int n, x, y;
    std::vector<std::pair<int, int>> v;
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%d%d", &x, &y);
        v.push_back(std::pair(y, x));
    }
    merge(v, 0, n - 1);
    for (int i = 0; i < n; i++) {
        printf("%d %d\n", v[i].second, v[i].first);
    }
    return 0;
}