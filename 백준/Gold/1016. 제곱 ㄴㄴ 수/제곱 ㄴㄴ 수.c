#include <stdio.h>

int main() {
    long long min, max;
    scanf("%lld%lld", &min, &max);

    _Bool isDivided[1000001] = {};

    for (long long i = 2; i*i <= max; i++) {
        long long q = min / (i*i);
        if (min % (i*i)) q++; // 나머지가 있으면 몫에 +1처리

        while (i*i * q <= max) { // i*i * q = min 이상인 i*i의 배수 = min 이상인 현재 제곱수의 배수
            isDivided[i*i * q - min] = 1;
            q++; // 다음 i*i의 배수로 넘어가기
        }
    }

    int ans = 0;
    for (int i = 0; i <= max-min; i++)
        if (!isDivided[i]) ans++;
    printf("%d", ans);

    return 0;
}