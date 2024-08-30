#include <iostream>
using namespace std;
int main() {
	int n, rab[46]{1, 1}, t;
    for (int i=2; i<46; i++) {
        rab[i] = rab[i-2]+rab[i-1];
    }
    cin >> n;
    for (int i=0; i<n; i++) {
        cin >> t;
        cout << rab[t] << '\n';
    }
	return 0;
}