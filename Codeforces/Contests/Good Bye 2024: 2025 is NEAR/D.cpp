/**
 *    author:  MaGnsi0
 *    created: 29.12.2024 23:54:45
**/
#include <bits/stdc++.h>

using namespace std;

const int64_t MOD = 998244353;

int64_t power(int64_t b, int64_t p) {
    int64_t res = 1;
    while (p) {
        if (p & 1) { res = res * b % MOD; }
        b = b * b % MOD; p /= 2;
    }
    return res;
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int T; cin >> T;
    while (T--) {
        int n; cin >> n;
        int Q; cin >> Q;
        vector pos(2, vector<int>(n));
        vector a(2, vector<pair<int64_t, int>>(n));
        for (int t = 0; t < 2; ++t) {
            for (int i = 0; i < n; ++i) {
                int64_t x; cin >> x;
                a[t][i] = {x, i};
            }
            sort(a[t].begin(), a[t].end());
            for (int i = 0; i < n; ++i) {
                pos[t][a[t][i].second] = i;
            }
        }
        int64_t ans = 1;
        function<void(int, bool)> do_ = [&](int j, bool multiply) {
            int64_t val = min(a[0][j].first, a[1][j].first);
            ans *= (multiply ? val : power(val, MOD - 2));
            ans %= MOD;
        };
        function<void(int, int)> op = [&](int t, int j) {
            int i = pos[t][j];
            do_(i, false);
            int to_move = lower_bound(a[t].begin(), a[t].end(), make_pair(a[t][i].first + 1, 0)) - a[t].begin() - 1;
            a[t][i].first++;
            if (to_move == n) { to_move = i; }
            do_(to_move, false);
            swap(pos[t][a[t][i].second], pos[t][a[t][to_move].second]);
            swap(a[t][i], a[t][to_move]);
            do_(i, true);
            do_(to_move, true);
        };
        for (int i = 0; i < n; ++i) {
            do_(i, true);
        }
        cout << ans << " ";
        while (Q--) {
            int t; cin >> t; t--;
            int j; cin >> j; j--;
            op(t, j);
            cout << ans << " ";
        }
        cout << "\n";
    }
}
