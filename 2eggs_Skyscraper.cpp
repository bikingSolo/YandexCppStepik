// 1.9 13

#include <iostream>
#include <cmath>
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

// Binary-search for optimal i
// Optimal criterion: MinMax(n - i) + 1 == i; i: [1, n-1]
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
            // MinMax(n - i) + 1 == i + 1 -> MinMax(n - i) is not optimal
            // and we must correct it's value returning greater i_optim
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

// Optimal criterion, but faster
int f(int n) {
    if (n < 3) {return n - 1;}
    int m = f(n - 1);
    if (f(n - m) == m) {++m;}
    return m;
}

// Optimal criterion, but more faster
int fast_f(int n) {
    if (n < 3) return n - 1;
    return f(n - f(n - 1)) + 1;
}

// The best solution O(n)
int ArProg(int n) {
    int a = 0, sum = 0;
    while (sum < n - 1) {
        a += 1;
        sum += a;
    }
    return a;
}

// Similar solution to previous but analytical ~ O(1)
int square_root(int n) {
    return ceil(sqrt(2 * n - 1.75) - 0.5);
}


int main() {
    int n;
    cin >> n;
    //vector <int> memo(n + 1, 0);
    cout << square_root(n) << endl;
    return 0;
}