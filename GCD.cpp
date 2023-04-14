// 1.9

#include <iostream>
using namespace std;

int GCD(int a, int b) {
    if (a < b) {
        int temp = a;
        a = b;
        b = temp;
    }
    while (b != 0) {
        int c = a % b;
        a = b;
        b = c;
    }
    return a;
}

int main() {
    int a, b;
    while(true) {
        cin >> a >> b;
        cout << GCD(a, b) << endl;
    }
    return 0;
}