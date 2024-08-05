/**
 *    author:  MaGnsi0
 *    created: 29.04.2024 17:38:53
**/
#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int T; cin >> T;
    while (T--) {
        string s; cin >> s;
        int64_t n = (int)s.size(), ans = 0, ones = 0;
        for (int i = 0; i < n; ++i) {
            if (s[i] == '0') {
                if (ones) { ans += ones + 1; }
            } else {
                ones++;
            }
        }
        cout << ans << "\n";
    }
}
