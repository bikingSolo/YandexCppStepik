#include <iostream>
#include <set>
using namespace std;

void swap(int &a, int &b) {
    int t = a;
    a = b, b = t;
}

void print_arr(int *a, int n) {
    for (int i = 0; i < n; ++i) {
        cout << a[i] << " ";
    }
    cout << endl;
}

void select_sort(int *a, int n) {
    for (int i = 0; i < n; ++i) {
        int min = i;
        for (int j = i + 1; j < n; ++j) {
            if (a[j] < a[min]) {
                min = j;
            }
        }
        swap(a[min], a[i]);
    }
}

void select_sort_rec(int *a, int n, int i = 0) {
    if (i == n - 1) {return;}
    int min_id = i;
    for (int j = i; j < n; ++j) {
        if (a[j] < a[min_id]) {
            min_id = j;
        }
    }
    swap(a[i], a[min_id]);
    select_sort_rec(a, n, i + 1);
}

multiset <int> tree_sort() {
    int n, a;
    multiset <int> res;
    cin >> n;
    for (int i = 0; i < n; ++i) {
        cin >> a;
        res.insert(a);
    }
    return res;
}

int main() {
    int n;
    cin >> n;
    int a[n];
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    select_sort(a, n);
    print_arr(a, n);
    return 0;
}