// 1.9 14

#include <iostream>
#include <vector>
using namespace std;

int queen_cnt_rec(int n, int row, vector<int> &x, vector<int> &d1, vector<int> &d2) {
    if (row == n) {
        return 1;
    }
    int cnt = 0;
    for (int i = 0; i < n; ++i) {
        if (!x[i] and !d1[i + row] and !d2[i - row + n - 1]) {
            x[i] = d1[i + row] = d2[i - row + n - 1] = 1;
            cnt += queen_cnt_rec(n, row + 1, x, d1, d2);
            x[i] = d1[i + row] = d2[i - row + n - 1] = 0;
        }
    }
    return cnt;
}

int queen_cnt(int n) {
    vector<int> x(n, 0), d1(2 * n - 1, 0), d2(2 * n - 1, 0);
    return queen_cnt_rec(n, 0, x, d1, d2);
}

int main() {
    int n;
    cin >> n;
    cout << queen_cnt(n);
    return 0;
}