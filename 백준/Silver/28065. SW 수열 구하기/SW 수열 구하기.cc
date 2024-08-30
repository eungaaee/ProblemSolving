#include <cstdio>
int main() {
    int n, sw;
    scanf("%d", &n);
    sw = 1;
    for (int i = 1; i <= n; i++)
    {
        printf("%d ", sw);    
        sw += i%2?n-i:i-n; 
    }
    return 0;
}