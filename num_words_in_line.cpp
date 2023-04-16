#include <iostream>
#include <string>
using namespace std;

int main() {
    int cnt_word = 0, cnt_char = 0;
    string s;
    getline(cin, s);
    for (auto c: s) {
        if (c != ' ') {
            cnt_char++;
        } else {
            if (cnt_char > 0) {
                cnt_word++;
            }
            cnt_char = 0;
        }
    }
    if (cnt_char > 0) {
        cnt_word++;
    }
    cout << cnt_word;
    return 0;
}