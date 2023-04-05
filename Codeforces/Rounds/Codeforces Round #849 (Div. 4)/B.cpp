/**
 *    author:  MaGnsi0
 *    created: 03.02.2023 17:09:30
**/
#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int T;
    cin >> T;
    while (T--) {
        int n;
        string s;
        cin >> n >> s;
        bool ok = false;
        int x = 0, y = 0;
        for (int i = 0; i < n; ++i) {
            if (s[i] == 'U') {
                y++;
            }
            if (s[i] == 'D') {
                y--;
            }
            if (s[i] == 'R') {
                x++;
            }
            if (s[i] == 'L') {
                x--;
            }
            ok |= x == 1 && y == 1;
        }
        cout << (ok ? "YES" : "NO") << "\n";
    }
}
