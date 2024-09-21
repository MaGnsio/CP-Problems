/**
 *    author:  MaGnsi0
 *    created: 21.09.2024 15:00:28
**/
#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    string s; cin >> s;
    for (char c : s) {
        if (c == '.') { continue; }
        cout << c;
    }
}
