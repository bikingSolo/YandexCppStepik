// 1.7

#include <iostream>
using namespace std;

int main() {
    int n;
    cin >> n;
    int a[n], b[n]; // в b[n] строим новый (сдвинутый массив); a[n] не обязателен - его можно брать из stdin
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    for (int i = 0; i < n; i++) {
        b[(i + 1) % n] = a[i];      // в нужное место нового массива помещаем эл-ты старого; (i + k), k - длина шага
    }
    for (int i : b) {
        cout << i << " ";
    }
    
    return 0;
}


#include <iostream>
using namespace std;

int main() {
    int n;
    cin >> n;
    int a[n];
    for (int i = 0; i < n; i++) {
        cin >> a[(i + 1) % n];
    }
    for (int i : a) {
        cout << i << " ";
    }
    
    return 0;
}