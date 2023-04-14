// 1.7

#include <iostream>
#include <vector>
#include <string>
using namespace std;

int main() {
    int a, b, n = 8, shift = n - 1;
    string ans = "NO\n";
    vector <int> x(8), y(8), d1(2*n-1), d2(2*n-1);
    for (int i = 0; i < 8; ++i) {
        cin >> a >> b;
        --a, --b;
        if (x[a] == 1 || y[b] == 1 || d1[a + b] == 1 || d2[a - b + shift] == 1) {
            ans = "YES\n";
        } else {
            x[a] = y[b] = d1[a + b] = d2[a - b + shift] = 1;
        }
    }
    cout << ans;

    return 0;
}