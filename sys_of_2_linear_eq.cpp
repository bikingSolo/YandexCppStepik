// 1.6

#include <iostream>
using namespace std;

int main() {
    double a, b, c, d, e, f, det, min1, min2;
    cin >> a >> b >> c >> d >> e >> f;
    det = a * d - b * c;
    min1 = e * d - b * f;
    min2 = a * f - e * c;
    if (det != 0) { // ед реш rank(A) = 2
        cout << 2 << " " << min1 / det;
        cout << " " << min2 / det << endl;
    } else { // rank(A) < 2
        if (min1 != 0 || min2 != 0) { // rank([A|b]) = 2 
            cout << 0;
        } else if (a == 0 && b == 0 && c == 0 && d == 0) { // rank(A) = 0
            if (e == 0 && f == 0) {cout << 5;} // rank([A|b]) = 0
            else {cout << 0;} // rank([A|b]) = 1
        }
        else { // rank(A) = rank([A|b]) = 1
            if (a == 0 && b == 0 && e == 0) {
                a = c, b = d, e = f;
            }
            if (a == 0 && c == 0) {
                cout << 4 << " "<< e / b << endl;
            } else if (b == 0 && d == 0) {
                cout << 3 << " " << e / a << endl;
            } else {
                cout << 1 << " " << -a / b << " " << e / b << endl;
            }
        }
    }
    return 0;
}