/**
 *    author:  MaGnsi0
 *    created: 14.10.2022 19:49:31
**/
#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int T;
    cin >> T;
    while (T--) {
        int Q;
        cin >> Q;
        vector<vector<int64_t>> a(2, vector<int64_t>(26));
        a[0][0] = a[1][0] = 1;
        for (int q = 0; q < Q; ++q) {
            int j, x;
            string s;
            cin >> j >> x >> s;
            for (int i = 0; i < (int)s.size(); ++i) {
                a[j - 1][s[i] - 'a'] += x;
            }
            bool ok = false, only_a = true;
            for (int i = 1; i < 26; ++i) {
                ok |= a[1][i] != 0;
                only_a &= a[0][i] == 0;
            }
            cout << (ok || (a[0][0] < a[1][0] && only_a) ? "YES" : "NO") << "\n";
        }
    }
}
