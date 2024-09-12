#include <stdio.h>

void postorder(int l, int r, int* pre) {
    if (l >= r) return;

    int rNode;
    for (rNode = l+1; rNode < r; rNode++)
        if (pre[rNode] > pre[l]) break;

    postorder(l+1, rNode, pre);
    postorder(rNode, r, pre);

    printf("%d\n", pre[l]);
}

int main() {
    int preorder[10000], nodeCnt = -1;
    while (scanf("%d", preorder + ++nodeCnt) != EOF);
    
    postorder(0, nodeCnt, preorder);
}