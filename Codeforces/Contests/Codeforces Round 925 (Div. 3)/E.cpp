/**
 *    author:  MaGnsi0
 *    created: 13.02.2024 17:08:04
**/
#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int T; cin >> T;
    while (T--) {
        int n; cin >> n;
        int m; cin >> m;
        vector<pair<int, int>> a(n);
        for (int i = 0; i < n; ++i) {
            string s; cin >> s;
            for (int j = (int)s.size() - 1; j >= 0; --j) {
                if (s[j] != '0') { break; }
                a[i].first++;
            }
            a[i].second = (int)s.size();
        }
        sort(a.rbegin(), a.rend());
        int cnt = 0;
        for (int i = 0; i < n; i += 2) {
            cnt += a[i].second - a[i].first;
            if (i + 1 < n) { cnt += a[i + 1].second; }
        }
        cout << (cnt <= m ? "Anna" : "Sasha") << "\n";
    }
}
