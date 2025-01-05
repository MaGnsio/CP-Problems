/**
 *    author:  MaGnsi0
 *    created: 05.01.2025 02:06:49
**/
#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int T; cin >> T;
    while (T--) {
        int n; cin >> n;
        string s; cin >> s;
        int64_t ans = 0;
        for (int i = 0; i < n; ++i) {
            for (int j = i; j < n; ++j) {
                int m = (j - i + 1);
                string t = s.substr(i, m);
                string p = "";
                for (int k = 0; k < m; ++k) {
                    if (t[k] == '1' && (k - 1 < 0 || p[k - 1] == '0') && (k - 2 < 0 || p[k - 2] == '0')) {
                        p += '1';
                    } else {
                        p += '0';
                    }
                }
                ans += count(p.begin(), p.end(), '1');
            }
        }
        cout << ans << "\n";
    }
}
