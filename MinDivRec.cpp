// 1.9 8

#include <iostream>
#include <cmath>
using namespace std;

int MinDivisorRec(int n, int i) {
    if (i > sqrt(n)) {return n;}
    if (n % i == 0) {return i;}
    return MinDivisorRec(n, i + 2);
}

int MinDivisor(int n) {
    if (n % 2 == 0) {return 2;}
    return MinDivisorRec(n, 3);
}

int main() {
    int n;
    cin >> n;
    cout << MinDivisor(n);
    return 0;
}