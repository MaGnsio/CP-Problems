/**
 *    author:  MaGnsi0
 *    created: 23.10.2023 01:47:20
**/
#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n; cin >> n; cin.ignore();
    string s; getline(cin, s);
    bool low = true; string t = "";
    int Q; cin >> Q;
    while (Q--) {
        string c; cin >> c;
        if (c == "CapsLock") {
            low ^= true;
        } else if (c == "Backspace") {
            if (!t.empty()) { t.pop_back(); }
        } else if (c == "Space") {
            t += " ";
        } else {
            t += (low ? tolower(c[0]) : toupper(c[0]));
        }
    }
    cout << (s == t ? "Correct" : "Incorrect");
}
