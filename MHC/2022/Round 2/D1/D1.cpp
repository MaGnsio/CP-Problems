/**
 *    author:  MaGnsi0
 *    created: 24.09.2022 21:06:49
**/
#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    freopen("D1.in", "r", stdin);
    freopen("D1.out", "w", stdout);
    int T;
    cin >> T;
    for (int t = 1; t <= T; ++t) {
        int n, m;
        cin >> n >> m;
        vector<int> a(n);
        for (int i = 0; i < n; ++i) {
            cin >> a[i];
        }
        vector<vector<int>> b(4 * n, vector<int>(3, 0));
        function<void(int, int, int)> update = [&](int i, int j, int x) {
            int k = 0, l = 0, r = n - 1;
            while (l <= r) {
                b[k][j] += x;
                if (l == r) { return; }
                int m = (l + r) / 2;
                if (l <= i && i <= m) { k = 2 * k + 1, r = m; }
                else { k = 2 * k + 2, l = m + 1; }
            }
        };
        function<vector<int>(int, int, int, int, int)> query = [&](int j, int l, int r, int L, int R) {
            if (L <= l && r <= R) { return b[j]; }
            if (R < l || r < L) { return vector<int>(3, 0); }
            int m = (l + r) / 2;
            vector<int> x = query(2 * j + 1, l, m, L, R);
            vector<int> y = query(2 * j + 2, m + 1, r, L, R);
            vector<int> z(3, 0);
            for (int i = 0; i < 3; ++i) { z[i] = x[i] + y[i]; }
            return z;
        };
        function<vector<int>(int, int)> F = [&](int L, int R) {
            return query(0, 0, n - 1, L, R);
        };
        for (int i = 0; i < n; ++i) {
            update(i, a[i] - 1, 1);
        }
        int64_t ans = 0;
        for (int i = 0; i < m; ++i) {
            int x, y, z;
            cin >> x >> y >> z;
            update(x - 1, a[x - 1] - 1, -1);
            a[x - 1] = y;
            update(x - 1, a[x - 1] - 1, +1);
            vector<int> L = F(0, z - 1);
            vector<int> H = F(z, n - 1);
            int fL = 1 * L[0] + 2 * L[1] + 3 * L[2];
            int fH = 1 * H[0] + 2 * H[1] + 3 * H[2];
            if (fL < fH) {
                swap(L, H);
                swap(fL, fH);
            }
            int diff = fL - fH;
            if (diff == 0) {
                continue;
            }
            if (diff & 1) {
                ans += -1;
                continue;
            }
            int add = 0;
            if (min(L[2], H[0]) >= diff / 4) {
                int cnt = diff / 4;
                L[2] -= cnt, H[0] -= cnt, add += cnt, diff -= 4 * cnt;
            } else {
                int cnt = min(L[2], H[0]);
                L[2] -= cnt, H[0] -= cnt, add += cnt, diff -= 4 * cnt;
            }
            if (0 < diff && diff < 4) {
                if ((L[1] && H[0]) || (L[2] && H[1])) {
                    add += 1;
                } else if ((L[2] && H[0]) && ((L[0] && H[1]) || (L[1] && H[2]))) {
                    add += 2;
                } else {
                    add = -1;
                }
            } else {
                int cnt = min(L[1], H[0]) + min(L[2], H[1]);
                if (cnt >= diff / 2) {
                    add += diff / 2;
                } else {
                    add = -1;
                }
            }
            ans += add;
        }
        cout << "Case #" << t << ": " << ans << "\n";
    }
}
