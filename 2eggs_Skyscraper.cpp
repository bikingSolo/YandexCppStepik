#include <iostream>
#include <vector>
using namespace std;

int MinMax(int n) {     // Brute-Force solution
    if (n <= 3) {
        return n - 1;
    }
    int t, min = n;
    for (int i = 1; i < n; ++i) {
        t = max(i, MinMax(n - i) + 1);
        if (t < min) {
            min = t;
        }
    }
    return min;
}

int MinMaxMemo(int n, vector <int> &memo) {     // Brute-Force solution with memoization
    if (n <= 3) {
        return n - 1;
    }
    if (memo[n] > 0) {
        return memo[n];
    }
    int t, min = n;
    for (int i = n - 1; i > 0; --i) {
        t = max(i, MinMaxMemo(n - i, memo) + 1);
        if (min < t) {
            min = t;
        }
    }
    memo[n] = min;
    return min;
}

int main() {
    int n;
    cin >> n;
    vector <int> memo(n + 1, 0);
    cout << MinMaxMemo(n, memo) << endl;
    return 0;
}