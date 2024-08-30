#include <stdio.h>

int main(){
    int K, nums[100000], p = 0, sum = 0;
    scanf("%d", &K);
    while (K--) {
        scanf("%d", nums+p);
        if (nums[p]) p++;
        else p--;
    }
    while (p--) sum += nums[p];
    printf("%d", sum);
    return 0;
}