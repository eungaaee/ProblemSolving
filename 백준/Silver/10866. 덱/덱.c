#include <malloc.h>
#include <stdio.h>
#include <string.h>
int main() {
    int n, *deque, front, back, t, isFirst = 1;
    char command[11];
    scanf("%d", &n);
    deque = (int*)malloc(sizeof(int) * n * 2);
    front = n;
    back = n;
    for (int i = 0; i < n; i++) {
        scanf("%s", command);
        if (!strcmp(command, "push_front")) {
            scanf("%d", &t);
            deque[--front] = t;
        } else if (!strcmp(command, "push_back")) {
            scanf("%d", &t);
            deque[back++] = t;
        } else if (!strcmp(command, "pop_front")) {
            printf("%d\n", back - front > 0 ? deque[front++] : -1);
        } else if (!strcmp(command, "pop_back")) {
            printf("%d\n", back - front > 0 ? deque[--back] : -1);
        } else if (!strcmp(command, "size")) {
            printf("%d\n", back - front);
        } else if (!strcmp(command, "empty")) {
            printf("%d\n", back - front > 0 ? 0 : 1);
        } else if (!strcmp(command, "front")) {
            printf("%d\n", back - front > 0 ? deque[front] : -1);
        } else if (!strcmp(command, "back")) {
            printf("%d\n", back - front > 0 ? deque[back-1] : -1);
        }
    }
    return 0;
}