#include <stdio.h>
#define INF 0x7FFFFFFF

int main() {
    char word[2002];
    scanf("%s", word+1);

    int wordLen;
    for (wordLen = 1; word[wordLen+1] != '\0'; wordLen++);

    // i to j is palindrome ? 1 : 0
    _Bool isPalindrome[2001][2001] = {};

    // i to i
    for (int i = 1; i <= wordLen; i++) isPalindrome[i][i] = 1;
    
    // i-1 to i
    for (int i = 2; i <= wordLen; i++)
        if (word[i-1] == word[i]) isPalindrome[i-1][i] = 1;
    
    // L to R
    for (int R = 3; R <= wordLen; R++)
        for (int L = 1; L <= R-2; L++)
            if (word[L] == word[R] && isPalindrome[L+1][R-1]) isPalindrome[L][R] = 1;

    // minimum partition count until idx
    int minPart[2001];
    minPart[0] = 0;
    for (int R = 1; R <= wordLen; R++) {
        minPart[R] = INF;
        for (int L = 1; L <= R; L++) {
            if (isPalindrome[L][R] && minPart[L-1] + 1 < minPart[R])
                minPart[R] = minPart[L-1] + 1;
        }
    }

    printf("%d", minPart[wordLen]);

    return 0;
}