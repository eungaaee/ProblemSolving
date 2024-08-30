#include <cstdio>
using namespace std;

int main() {
    char e, robot, box, target;
    for (int i = 0; i < 10; i++) {
        e = getchar();
        if (e == '@') robot = i;
        else if (e == '#') box = i;
        else if (e == '!') target = i;
    }
    int ans = -1;
    if (robot < box && box < target) ans = target - robot - 1;
    else if (target < box && box < robot) ans = robot - target - 1;
    printf("%d", ans);
    return 0;
}