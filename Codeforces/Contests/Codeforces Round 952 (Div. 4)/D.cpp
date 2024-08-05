/**
 *    author:  MaGnsi0
 *    created: 15.06.2024 18:28:28
**/
#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int T; cin >> T;
    while (T--) {
        int n; cin >> n;
        int m; cin >> m;
        pair<int, int> low = {n + 1, m + 1};
        pair<int, int> high = {0, 0};
        for (int i = 1; i <= n; ++i) {
            for (int j = 1; j <= m; ++j) {
                char x; cin >> x;
                if (x == '.') { continue; }
                low = min(low, {i, j});
                high = max(high, {i, j});
            }
        }
        assert(low.second == high.second);
        cout << (low.first + high.first) / 2 << " " << low.second << "\n";
    }
}
