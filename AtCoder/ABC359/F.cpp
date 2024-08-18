/**
 *    author:  MaGnsi0
 *    created: 18.08.2024 21:31:35
**/
#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n; cin >> n;
    int64_t ans = 0;
    set<tuple<int64_t, int64_t, int64_t, int>> increase;
    for (int i = 0; i < n; ++i) {
        int64_t x; cin >> x; ans += x;
        increase.emplace(3LL * x, 1, x, i);
    }
    for (int i = 0; i < n - 2; ++i) {
        auto [delta, deg, x, j] = *increase.begin();
        increase.erase(increase.begin()); ans += delta;
        increase.emplace((deg + 2) * (deg + 2) * x - (deg + 1) * (deg + 1) * x, deg + 1, x, j);
    }
    cout << ans;
}
