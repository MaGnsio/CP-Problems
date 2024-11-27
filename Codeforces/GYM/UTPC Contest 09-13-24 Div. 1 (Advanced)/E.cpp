/**
 *    author:  MaGnsi0
 *    created: 27.11.2024 19:32:54
**/
#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int64_t n; cin >> n;
    int64_t m; cin >> m;
    int64_t k; cin >> k; k = min(n, k);
    vector<pair<int64_t, int64_t>> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i].second;
    }
    for (int i = 0; i < n; ++i) {
        cin >> a[i].first;
    }
    sort(a.rbegin(), a.rend());
    int64_t ans = 0, to_take = m * k;
    for (int i = 0; i < n; ++i) {
        int64_t to_eat = min({m, a[i].second, to_take});
        ans += to_eat * a[i].first;
        to_take -= to_eat;
    }
    cout << ans;
}
