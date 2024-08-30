#include <iostream>
using namespace std;
int *heap, heap_size;
int compare(int &a, int &b) {
    if ((a < 0 ? -a : a) > (b < 0 ? -b : b))
        return 1;
    else if ((a < 0 ? -a : a) < (b < 0 ? -b : b))
        return -1;
    else if ((a < 0 ? -a : a) == (b < 0 ? -b : b)) {
        if (a > b)
            return 2;
        else
            return -2;
    }
}
void push(int x) {
    heap_size++;
    int cur = heap_size;
    while (cur > 1 && compare(x, heap[cur / 2]) < 0) {
        heap[cur] = heap[cur / 2];
        cur >>= 1;
    }
    heap[cur] = x;
}
int pop() {
    if (heap_size < 1) return 0;
    int parent{1}, child{2}, res, last;
    res = heap[1];
    last = heap[heap_size];
    heap_size--;
    while (child <= heap_size) {
        if (child + 1 <= heap_size && compare(heap[child + 1], heap[child]) < 0) {
            child++;
        }
        if (compare(heap[child], last) < 0) {
            heap[parent] = heap[child];
            parent = child;
            child <<= 1;
        } else
            break;
    }
    heap[parent] = last;
    return res;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n, x;
    cin >> n;
    heap = new int[n];
    for (int i = 0; i < n; i++) {
        cin >> x;
        if (x == 0)
            cout << pop() << '\n';
        else
            push(x);
    }
    delete[] heap;
    return 0;
}