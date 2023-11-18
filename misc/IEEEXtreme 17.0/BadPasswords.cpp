/**
 *    author:  MaGnsi0
 *    created: 28.10.2023 06:11:02
**/
#pragma GCC optimize("O3")
#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")
#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n; cin >> n;
    map<string, int> mp;
    for (int i = 0; i < n; ++i) {
        int m; cin >> m;
        for (int j = 0; j < m; ++j) {
            string s; cin >> s; mp[s] |= (1 << i);
        }
    }
    int Q; cin >> Q;
    while (Q--) {
        string s; cin >> s;
        string t; cin >> t;
        if ((int)s.size() > (int)t.size()) { swap(s, t); }
        function<bool(bool)> solve = [&](bool reversed) {
            int m1 = (int)s.size();
            int m2 = (int)t.size();
            int m = min(m1, m2);
            vector<bool> pre(m);
            vector<bool> suf(m);
            for (int i = 0; i < m; ++i) {
                pre[i] = s[i] == t[i];
            }
            for (int i = m - 1, j = 1; i >= 0; --i, ++j) {
                suf[i] = s[m1 - j] == t[m2 - j];
            }
            for (int i = 1; i < m; ++i) {
                pre[i] = pre[i] && pre[i - 1];
            }
            for (int i = m - 2; i >= 0; --i) {
                suf[i] = suf[i] && suf[i + 1];
            }
            bool ok = false;
            for (int i = 0; i < m; ++i) {
                if (i && pre[i - 1] == false) { continue; }
                for (int j = 1; i + j - 1 < m2 && i + (j - (m2 - m1)) - 1 < m1 && j <= 10; ++j) {
                    int s1 = j;
                    int s2 = j - (m2 - m1);
                    if (s2 <= 0) { continue; }
                    string x = s.substr(i, s2);
                    string y = t.substr(i, s1);
                    if (reversed) {
                        reverse(x.begin(), x.end());
                        reverse(y.begin(), y.end());
                    }
                    if (!mp.count(x) || !mp.count(y) || !(mp[x] & mp[y])) { continue; }
                    assert(m1 - (i + s2) == m2 - (i + s1));
                    ok |= (i + s2 < m ? suf[i + s2] : true);
                }
            }
            return ok;
        };
        bool ok = solve(0);
        reverse(s.begin(), s.end());
        reverse(t.begin(), t.end());
        ok |= solve(1);
        cout << (ok ? "REJECT" : "OK") << "\n";
    }
}
