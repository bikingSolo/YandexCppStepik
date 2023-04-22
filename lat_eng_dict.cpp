// 1.11 6

#include <iostream>
#include <map>
#include <set>
#include <string>
using namespace std;

int main() {
    int n, cnt;
    map <string, set <string>> dict;
    string line, eng, s;
    cin >> n >> ws;

    for (int i = 0; i < n; ++i) {
        cnt = 0, s = "";
        getline(cin, line);
        for (char c : line) {
            if (c != ' ' && c != '-' && c != ',') {
                s += c;
            } else if (!s.empty()) {
                cnt++;
                if (cnt == 1) {eng = s;} 
                else {dict[s].insert(eng);}
                s = "";
            }
        }
        if (!s.empty()) {
            dict[s].insert(eng);
        }
    }
    cout << dict.size() << endl;
    bool is_first = true;
    for (auto i : dict) {
        is_first = true;
        cout << i.first << " - ";
        for (auto j : i.second) {
            cout << (is_first ? j : ", " + j);
            is_first = false;
        }
        cout << endl;
    }
    return 0;
}