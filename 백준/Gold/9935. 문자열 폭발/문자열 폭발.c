#include <stdio.h>
#include <string.h>

int main() {
    char str[1000001], bombStr[37], afterStr[1000001];
    scanf("%s%s", str, bombStr);

    int bombLength = strlen(bombStr);

    for (int beforeIdx = 0, afterIdx = 0; str[beforeIdx] != '\0'; beforeIdx++, afterIdx++) {
        afterStr[afterIdx] = str[beforeIdx];

        if (afterIdx >= bombLength-1 && afterStr[afterIdx] == bombStr[bombLength-1]) {
            int isBomb = 1;
            for (int j = 1; j < bombLength; j++) {
                if (afterStr[afterIdx-j] != bombStr[bombLength-1-j]) {
                    isBomb = 0;
                    break;
                }
            }

            if (isBomb) afterIdx -= bombLength;
        }
        
        afterStr[afterIdx+1] = '\0';
    }

    printf("%s", strlen(afterStr) ? afterStr : "FRULA");
    
    return 0;
}