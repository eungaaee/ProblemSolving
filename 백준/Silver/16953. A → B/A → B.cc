#include <iostream>
using namespace std;
int main() {
    int a, b, c{1};
    cin >> a >> b;
    while (b > a) {
        if (b % 2 == 0)
            b /= 2;
        else if (b % 10 == 1 && b != 1)
            b /= 10;
        else {
            c = -1;
            break;
        }
        c++;
    }
    if (b < a) c = -1;
    cout << c;
    return 0;
}