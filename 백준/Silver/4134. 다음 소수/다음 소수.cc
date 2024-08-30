#include <cstdio>
#include <complex>
using namespace std;

bool isPrime(unsigned int &n) {
    if (!(n>>1)) return 0;
    for (unsigned i = 2; i*i <= n; i++)
        if (n%i==0) return 0;
    return 1;
}

int main() {
    int tc;
    scanf("%d", &tc);
    while (tc--) {
        unsigned int n;
        scanf("%u", &n);
        while (1) {
            if(isPrime(n)) break;
            n++;
        }
        printf("%u\n", n);
    }
    return 0;
}