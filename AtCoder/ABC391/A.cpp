/**
 *    author:  MaGnsi0
 *    created: 01.02.2025 16:04:34
**/
#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    string s; cin >> s;
    for (char c : s) {
        if (c == 'N') {
            cout << 'S';
        } else if (c == 'S') {
            cout << 'N';
        } else if (c == 'E') {
            cout << 'W';
        } else {
            cout << 'E';
        }
    }
}
