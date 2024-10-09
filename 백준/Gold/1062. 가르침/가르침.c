// 비트마스크로 집합 이용
#include <stdio.h>
#include <stdlib.h>

int N, K;
int *word;  // 남극 단어별 구성 알파벳들의 집합을 비트로 표현
int max;

void backtrack(int startIdx, int learned, int cnt) {  // startIdx: 이전 재귀에서 선택된 단어 중복 선택 방지, learned: 배운 알파벳 집합, cnt: 배운 알파벳 수
    if (cnt >= K) { // 몇 개의 남극단어를 읽을 수 있는지 확인
        int readable = 0;
        for (int i = 0; i < N; i++)
            if ((word[i] & learned) == word[i]) readable++;

        if (readable > max) max = readable;

        return;
    }

    for (int i = startIdx; i < 26; i++) {
        if (learned & (1 << i)) continue; // 이미 배운 알파벳이면 continue

        backtrack(i+1, learned | (1 << i), cnt+1);
    }
}

int main() {
    scanf("%d%d", &N, &K);
    if (K < 5 && putchar('0')) return 0;
    else if (K == 26 && printf("%d", N)) return 0;

    word = (int *)calloc(N, 4);

    for (int i = 0; i < N; i++) {
        char tempWord[16];
        scanf("%s", tempWord);

        for (int j = 0; tempWord[j] != '\0'; j++) { // 단어의 알파벳들을 word[i]에 비트로 표현
            word[i] |= 1 << tempWord[j]-'a';
        }
    }

    // anta, tica는 모든 남극단어에 들어가므로 a, n, t, i, c 5개는 무조건 배워야 함
    int learned = 0;
    learned |= 1 << ('a'-'a');
    learned |= 1 << ('n'-'a');
    learned |= 1 << ('t'-'a');
    learned |= 1 << ('i'-'a');
    learned |= 1 << ('c'-'a');

    backtrack(0, learned, 5); // antic 5개는 배웠으므로 cnt도 5부터 시작
    printf("%d", max);

    free(word);
    return 0;
}