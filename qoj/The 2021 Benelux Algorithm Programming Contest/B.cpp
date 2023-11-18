/**
 *    author:  MaGnsi0
 *    created: 05.10.2023 16:40:32
**/
#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int64_t n, m;
    cin >> n >> m;
    map<string, int64_t> a, c, d;
    for (int i = 0; i < n; ++i) {
        string s; cin >> s;
        int64_t x; cin >> x;
        a[s] = x;
    }
    int k;
    cin >> k;
    map<string, vector<int64_t>> b;
    for (int i = 0; i < k; ++i) {
        string s; cin >> s;
        int64_t x; cin >> x;
        b[s].push_back(x);
        c[s] = max(c[s], x);
    }
    for (auto [s, x] : c) {
        m -= max(x - a[s], int64_t(0));
    }
    if (m < 0) {
        cout << 0 << "\n";
        return 0;
    }
    for (auto& [s, x] : a) {
        x = max(x, c[s]);
    }
    int64_t max_add = 0;
    for (auto& [s, _] : b) {
        max_add = max(max_add, (int64_t)_.size());
        for (auto& x : _) {
            d[s] += (a[s] > x ? 1 : a[s] + 1);
        }
    }
    set<pair<int64_t, string>> S;
    for (auto [s, x] : d) {
        S.emplace(x, s);
    }
    while (m && !S.empty() && S.rbegin() -> first >= max_add) {
        string s = S.rbegin() -> second;
        S.erase(*S.rbegin());
        a[s]++, m--;
    }
    for (auto& [s, x] : a) {
        if ((int)b[s].size() == max_add) {
            x += m;
            break;
        }
    }
    int64_t ans = 0;
    for (auto [s, _] : b) {
        for (auto x : _) {
            ans += (a[s] > x ? a[s] : 0);
        }
    }
    cout << ans;
}
