#include <stdio.h>

int main() {
    char code[5001];
    scanf("%s", code);

    int ans = 1; // 아래 반복문을 거치지 않는 0을 제외한 한 자리 수의 경우
    if (code[0] == '0') ans = 0;
    else {
        int dp[5001] = {};
        dp[0] = dp[1] = 1;

        for (int i = 1; code[i] != '\0'; i++) { // i = 1 부터 시작. dp배열 접근할 때는 보정하기.
            int cur = code[i]-'0', prev = code[i-1]-'0';

            if (cur == 0 && (prev == 0 || prev > 2)) {
                ans = 0;
                break;
            }

            if (cur) dp[i+1] += dp[i]; // 1의 자리가 0이 아니면
            int twoNum = prev*10 + cur;
            if (10 <= twoNum && twoNum <= 26) dp[i+1] += dp[i-1]; // 두 자리 수가 가능하면

            dp[i+1] %= 1000000;
            ans = dp[i+1];
        }
    }

    printf("%d", ans);
    return 0;
}