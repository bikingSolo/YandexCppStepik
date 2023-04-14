// 1.7

#include <iostream>
using namespace std;

int main() {
    int n, k;
    cin >> n >> k;
    int l[k], r[k];
    bool b[n];
    fill(b, b + n, true);
    // read
    for (int i = 0; i < k; ++i) {
        cin >> l[i] >> r[i];
        --l[i], --r[i];
    }
    // sort (l,r) with l1 <= l2 <= ...
    for (int i = 0; i < k - 1; ++i) {
        int min_num = i;
        for (int j = i; j < k; ++j) {
            if (l[j] <= l[min_num]) {
                min_num = j;
            }
        }
        // swap
        int t1 = l[i], t2 = r[i];
        l[i] = l[min_num], r[i] = r[min_num];
        l[min_num] = t1, r[min_num] = t2;
    }
    // make interval
    int l_p = -1, r_p = -1; // first segment will be entirely removed
    for (int i = 0; i < k; ++i) {
        if (r_p < l[i]) { // Segments doesnt intercept
            l_p = l[i];
            r_p = r[i];
        } else if (r[i] > r_p) { // Segments intercept
            l_p = r_p + 1;
            r_p = r[i];
        } else {
            continue;
        }
        
        for (int i = l_p; i <= r_p; ++i) {
            b[i] = false;
        }
    }
    // out
    for (int i = 0; i < n; ++i) {
        if (b[i]) {cout << 'I';} 
        else {cout << '.';} 
    }
    
    return 0;
}