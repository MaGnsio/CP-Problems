/**
 *    author:  MaGnsi0
 *    created: 27.01.2024 14:50:38
**/
#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n; cin >> n;
    int m; cin >> m;
    vector<int> a(m);
    for (int i = 0; i < m; ++i) {
        cin >> a[i]; a[i]--;
    }
    vector<vector<int>> start(n), end(n);
    for (int i = 1; i < m; ++i) {
        int u = a[i], v = a[i - 1];
        if (u > v) { swap(u, v); }
        start[u].push_back(v);
        end[v].push_back(u);
    }
    int64_t ans = 0, base = 0;
    for (int i = 1; i < m; ++i) {
        ans += abs(a[i] - a[i - 1]);
        base += abs(a[i] - a[i - 1]);
    }
    for (int i = 1; i < n; ++i) {
        for (int j : end[i - 1]) {
            base -= n - abs(i - j - 1);
            base += abs(i - j - 1);
        }
        for (int j : start[i - 1]) {
            base -= abs(j - i + 1);
            base += n - abs(j - i + 1);
        }
        ans = min(ans, base);
    }
    cout << ans;
}
