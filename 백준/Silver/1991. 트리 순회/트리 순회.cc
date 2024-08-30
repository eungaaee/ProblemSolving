#include <iostream>
using namespace std;

pair<char, char> node[26];

void preorder(char cur) {
    if (cur=='.') return;
    cout << cur;
    preorder(node[cur-'A'].first);
    preorder(node[cur-'A'].second);
}
void inorder(char cur) {
    if (cur=='.') return;
    inorder(node[cur-'A'].first);
    cout << cur;
    inorder(node[cur-'A'].second);
}
void postorder(char cur) {
    if (cur=='.') return;
    postorder(node[cur-'A'].first);
    postorder(node[cur-'A'].second);
    cout << cur;
}
int main() {
    int N;
    cin >> N;
    for (int i = 0; i < N; i++) {
        char p, l, r;
        cin >> p >> l >> r;
        node[p-'A'].first = l;
        node[p-'A'].second = r;
    }
    preorder('A');
    cout << '\n';
    inorder('A');
    cout << '\n';
    postorder('A');
    return 0;
}