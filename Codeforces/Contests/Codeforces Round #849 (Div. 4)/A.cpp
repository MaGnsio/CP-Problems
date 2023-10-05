/**
 *    author:  MaGnsi0
 *    created: 03.02.2023 16:47:10
**/
#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int T;
    cin >> T;
    while (T--) {
        char c;
        cin >> c;
        string s = "codeforces";
        bool ok = false;
        for (auto& x : s) {
            ok |= c == x;
        }
        cout << (ok ? "YES" : "NO") << "\n";
    }
}
