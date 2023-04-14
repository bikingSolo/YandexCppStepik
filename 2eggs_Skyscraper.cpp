// 1.9 13

#include <iostream>
#include <vector>
using namespace std;

// Brute-Force solution
int MinMax(int n) {
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

// Brute-Force solution with memoization
int MinMaxMemo(int n, vector <int> &memo) {
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

// Binary-search solution 
// Optimal criterion: i == MinMax(n - i) + 1, i: [1, n-1]
int MaxMinBinSrch(int n){
    if (n <= 3) {
        return n - 1;
    }
    
    int down = 1, up = n - 1, res;
    while (down <= up) {
        int mid = (up + down) / 2;
        int res = MaxMinBinSrch(n - mid) + 1;

        if (res < mid) {
            up = mid - 1;
        }
        else if (mid < res) {
            down = mid + 1;
            // kind of edge case ??
            if (res == down) {
                return res;
            }
        }
        else {
            return res;
        }
    }
    return res;
}

//...3 more solutions...

int main() {
    int n;
    cin >> n;
    vector <int> memo(n + 1, 0);
    cout << MinMaxMemo(n, memo) << endl;
    return 0;
}