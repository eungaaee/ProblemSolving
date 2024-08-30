#include <cmath>
#include <iostream>
#include <vector>
using namespace std;
int init(vector<int> &a, vector<int> &tree, int node, int start, int end) {
    if (start == end)
        return tree[node] = a[start];
    else
        return tree[node] = init(a, tree, node * 2, start, (start + end) / 2) * init(a, tree, node * 2 + 1, (start + end) / 2 + 1, end);
}
int update(vector<int> &tree, int node, int start, int end, int &idx, int &value) {
    if (idx < start || idx > end)
        return tree[node];
    else if (start == end)
        return tree[node] = value;
    else
        return tree[node] = update(tree, node * 2, start, (start + end) / 2, idx, value) * update(tree, node * 2 + 1, (start + end) / 2 + 1, end, idx, value);
}
int query(vector<int> &tree, int node, int start, int end, int &left, int &right) {
    if (left > end || right < start)
        return 1;
    else if (left <= start && right >= end)
        return tree[node];
    else
        return query(tree, node * 2, start, (start + end) / 2, left, right) * query(tree, node * 2 + 1, (start + end) / 2 + 1, end, left, right);
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, k;
    while (cin >> n >> k) {
        vector<int> a(n);
        int h = (int)ceil(log2(n));
        int tree_size = (1 << (h + 1));
        vector<int> tree(tree_size);
        int t;
        for (int i = 0; i < n; i++) {
            cin >> t;
            if (t > 0)
                a[i] = 1;
            else if (t < 0)
                a[i] = -1;
            else
                a[i] = 0;
        }
        init(a, tree, 1, 0, n - 1);
        char o1;
        int o2, o3;
        while (k--) {
            cin >> o1 >> o2 >> o3;
            if (o1 == 'C') {
                if (o3 > 0)
                    o3 = 1;
                else if (o3 < 0)
                    o3 = -1;
                else
                    o3 = 0;
                o2--;
                update(tree, 1, 0, n - 1, o2, o3);
            } else if (o1 == 'P') {
                o2--, o3--;
                int q = query(tree, 1, 0, n - 1, o2, o3);
                if (q > 0)
                    cout << '+';
                else if (q < 0)
                    cout << '-';
                else
                    cout << '0';
            }
        }
        cout << '\n';
    }
    return 0;
}