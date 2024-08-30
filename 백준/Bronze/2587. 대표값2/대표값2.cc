#include <cstdio>
#include <algorithm>
using namespace std;

int main() {
    int n[5], average=0;
    for (int i = 0; i < 5; i++) {
        scanf("%d", n+i);
        average += n[i];
    }
    sort(n, n+5);
    printf("%d\n%d", average/5, n[2]);
    return 0;
}