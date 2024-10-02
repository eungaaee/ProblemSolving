#include <stdio.h>
#include <stdlib.h>

const int INF = 0x3f3f3f3f;

struct rgb {
    int R, G, B;
};

int main() {
    int N;
    scanf("%d", &N);
    
    struct rgb *cost, *dp;
    cost = (struct rgb *)malloc(sizeof(struct rgb) * (N+1));
    dp = (struct rgb *)malloc(sizeof(struct rgb) * (N+1));

    for (int i = 1; i <= N; i++)
        scanf("%d%d%d", &cost[i].R, &cost[i].G, &cost[i].B);

    int min = INF;

    for (int s = 0; s < 3; s++) {
        // reset to INF
        struct rgb RGB_INF = {INF, INF, INF};
        for (int i = 1; i <= N; i++) dp[i] = RGB_INF;
        
        // set start color's cost
        if (s == 0) dp[1].R = cost[1].R;
        else if (s == 1) dp[1].G = cost[1].G;
        else dp[1].B = cost[1].B;

        // dp
        for (int i = 2; i <= N; i++) {
            dp[i] = cost[i];

            // next R
            if (dp[i-1].G < dp[i-1].B) dp[i].R += dp[i-1].G;
            else dp[i].R += dp[i-1].B;
            // next G
            if (dp[i-1].R < dp[i-1].B) dp[i].G += dp[i-1].R;
            else dp[i].G += dp[i-1].B;
            // next B
            if (dp[i-1].R < dp[i-1].G) dp[i].B += dp[i-1].R;
            else dp[i].B += dp[i-1].G;
        }

        // compare min
        int smaller;

        if (s == 0) { // started from R
            if (dp[N].G < dp[N].B) smaller = dp[N].G;
            else smaller = dp[N].B;
        } else if (s == 1) { // started from G
            if (dp[N].R < dp[N].B) smaller = dp[N].R;
            else smaller = dp[N].B;
        } else { // started from B
            if (dp[N].R < dp[N].G) smaller = dp[N].R;
            else smaller = dp[N].G;
        }

        if (smaller < min) min = smaller;
    }

    printf("%d", min);

    free(dp);
    return 0;
}