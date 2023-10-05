/**
 *    author:  MaGnsi0
 *    created: 29.08.2023 17:18:04
**/
#include <bits/stdc++.h>

using namespace std;

const int N = 2e6 + 6;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    set<int> S;
    for (int i = 0; i <= N; ++i) {
        S.insert(i);
    }
    int T;
    cin >> T;
    while (T--) {
        int n, m;
        cin >> n >> m;
        vector<pair<int, int>> a(m);
        for (int i = 0; i < m; ++i) {
            cin >> a[i].first >> a[i].second;
        }
        sort(a.rbegin(), a.rend());
        int ans = 0;
        for (int i = 0; i < m; ++i) {
            ans = max(ans, a[i].second + n + 1);
        }
        vector<bool> ok(n + 1, true);
        for (int i = 0; i < m; ++i) {
            if (a[i].first == a[i].second) {
                ok[a[i].first] = false;
            }
        }
        for (int i = 1; i <= n; ++i) {
            ok[i] = ok[i - 1] && ok[i];
        }
        vector<set<int>> b(n + 1);
        for (int i = 0; i < m; ++i) {
            b[a[i].first].insert(a[i].second);
        }
        for (int i = n, j = 0; i >= 0; --i) {
            if (ok[i] == false) { continue; }
            while (j < m && a[j].first > i) {
                S.erase(a[j].second - a[j].first);
                j++;
            }
            int X = *S.lower_bound(0) + i;
            if (b[i].lower_bound(i) != b[i].end() && *b[i].lower_bound(i) <= X) {
                continue;
            }
            ans = min(ans, n + X - i + 1);
        }
        for (int i = 0; i < m; ++i) {
            S.insert(a[i].second - a[i].first);
        }
        cout << ans << "\n";
    }
}
