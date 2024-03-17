/**
 *    author:  MaGnsi0
 *    created: 19.12.2023 12:26:22
**/
#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int T; cin >> T;
    while (T--) {
        string s; cin >> s;
        int n = (int)s.size();
        int64_t oldR = -1, newR = -1;
        for (int i = 0; i < n - 1; ++i) {
            if (s[i + 1] == '0') { continue; }
            int64_t x = stoll(s.substr(0, i + 1));
            int64_t y = stoll(s.substr(i + 1));
            if (x < y) {
                oldR = x;
                newR = y;
            }
        }
        if (oldR == -1) {
            cout << -1 << "\n";
        } else {
            cout << oldR << " " << newR << "\n";
        }
    }
}
