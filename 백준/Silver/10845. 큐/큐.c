#include <malloc.h>
#include <stdio.h>
#include <string.h>
int main() {
    int n, *queue, front = 0, rear = -1, t;
    char command[6];
    scanf("%d", &n);
    queue = (int*)malloc(sizeof(int) * n);
    for (int i = 0; i < n; i++) {
        scanf("%s", command);
        if (!strcmp(command, "push")) {
            scanf("%d", &t);
            queue[++rear] = t;
        } else if (!strcmp(command, "pop")) {
            if (rear - front > -1) {
                printf("%d\n", queue[front++]);
            } else {
                puts("-1");
            }
        } else if (!strcmp(command, "size")) {
            printf("%d\n", rear - front + 1);
        } else if (!strcmp(command, "empty")) {
            printf("%d\n", rear - front > -1 ? 0 : 1);
        } else if (!strcmp(command, "front")) {
            printf("%d\n", rear - front > -1 ? queue[front] : -1);
        } else if (!strcmp(command, "back")) {
            printf("%d\n", rear - front > -1 ? queue[rear] : -1);
        }
    }
    return 0;
}