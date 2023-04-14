// 1.9 8

#include <iostream>
#include <cmath>
using namespace std;

int MinDivisor(int n) {
    if (n % 2 == 0) {return 2;}
    int stop = sqrt(n);
    for (int i = 3; i <= stop; i += 2) {
        if (n % i == 0) {return i;}
    }
    return n;
}

int main() {
    int n;
    cin >> n;
    cout << MinDivisor(n);
    return 0;
}