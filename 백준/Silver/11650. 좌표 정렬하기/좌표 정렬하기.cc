#include <iostream>
#include <vector>

using namespace std;

void merge(vector<pair<int, int>>& v, int left, int mid, int right) {
    vector<pair<int, int>> t(right - left + 1);
    int i = left, j = mid + 1, k = 0;
    while (i <= mid && j <= right) {
        if (v[i] <= v[j]) {
            t[k++] = v[i++];
        } else {
            t[k++] = v[j++];
        }
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

void mergeSort(vector<pair<int, int>>& v, int left, int right) {
    if (left < right) {
        int mid = (left + right) / 2;
        mergeSort(v, left, mid);
        mergeSort(v, mid + 1, right);
        merge(v, left, mid, right);
    }
}

int main() {
    int n, x, y;
    vector<pair<int, int>> v;
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> x >> y;
        v.push_back(make_pair(x, y));
    }
    mergeSort(v, 0, n - 1);
    for (int i = 0; i < n; i++) {
        cout << v[i].first << ' ' << v[i].second << '\n';
    }
    return 0;
}