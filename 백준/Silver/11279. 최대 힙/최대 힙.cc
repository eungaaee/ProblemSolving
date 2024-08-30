#include <iostream>
using namespace std;
int *heap, heap_size;
int top() {
    return heap[1];
}
void push(int x) {
    heap_size++;
    int cur = heap_size;
    while (cur > 1 && x > heap[cur / 2]) {
        heap[cur] = heap[cur / 2];
        cur /= 2;
    }
    heap[cur] = x;
}
int pop() {
    if (heap_size < 1) return 0;
    int parent = 1, child = 2, top, res, last;
    res = heap[1];
    last = heap[heap_size];
    heap_size--;
    while (child <= heap_size) {
        if (child + 1 <= heap_size && heap[child + 1] > heap[child])
            child++;
        if (heap[child] > last) {
            heap[parent] = heap[child];
            parent = child;
            child *= 2;
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