/**
 *    author:  MaGnsi0
 *    created: 08/09/2021 16:07:22
**/
#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio (0); cin.tie (0); cout.tie (0);
    int T;
    cin >> T;
    while (T--) {
        int n, m, k;
        cin >> n >> m >> k;
        vector<int> x(n), y(m);
        for (int i = 0; i < n; ++i) {
            cin >> x[i];
        }
        for (int i = 0; i < m; ++i) {
            cin >> y[i];
        }
        long long res = 0;
        map<int, long long> cnt_x, cnt_y;
        map<pair<int, int>, long long> s_x, s_y;
        for (int i = 0; i < k; ++i) {
            int r, c;
            cin >> r >> c;
            int lx = *lower_bound(x.begin(), x.end(), r);
            int ly = *lower_bound(y.begin(), y.end(), c);
            if (r == lx && c == ly) {
                continue;
            }
            if (r == lx) {
                res += cnt_y[ly] - s_x[{lx, ly}];
                s_x[{lx, ly}]++;
                cnt_y[ly]++;
            } else {
                res += cnt_x[lx] - s_y[{lx, ly}];
                s_y[{lx, ly}]++;
                cnt_x[lx]++;
            }
        }
        cout << res << "\n";
    }
}
