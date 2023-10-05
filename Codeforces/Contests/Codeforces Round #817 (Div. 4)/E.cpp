/**
 *    author:  MaGnsi0
 *    created: 30.08.2022 16:34:14
**/
#include <bits/stdc++.h>

using namespace std;

const int N = 1e3 + 5;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int T;
    cin >> T;
    while (T--) {
        int n, q;
        cin >> n >> q;
        vector<pair<int64_t, int64_t>> a(n);
        for (int i = 0; i < n; ++i) {
            cin >> a[i].first >> a[i].second;
        }
        sort(a.begin(), a.end());
        vector<vector<int64_t>> adj(N), sum(N);
        for (int i = 0; i < n; ++i) {
            adj[a[i].first].push_back(a[i].second);
        }
        sum = adj;
        for (int i = 0; i < N; ++i) {
            for (int j = 1; j < (int)adj[i].size(); ++j) {
                sum[i][j] += sum[i][j - 1];
            }
        }
        for (int i = 0; i < q; ++i) {
            int64_t hs, ws, hb, wb;
            cin >> hs >> ws >> hb >> wb;
            int64_t ans = 0;
            for (int64_t j = hs + 1; j < hb; ++j) {
                if (adj[j].empty()) {
                    continue;
                }
                int l = 0, r = adj[j].size() - 1, L = -1, R = -1;
                while (l <= r) {
                    int mid = (l + r) / 2;
                    if (adj[j][mid] <= ws) {
                        L = mid;
                        l = mid + 1;
                    } else {
                        r = mid - 1;
                    }
                }
                l = 0, r = adj[j].size() - 1;
                while (l <= r) {
                    int mid = (l + r) / 2;
                    if (adj[j][mid] < wb) {
                        R = mid;
                        l = mid + 1;
                    } else {
                        r = mid - 1;
                    }
                }
                if (L >= R) {
                    continue;
                }
                if (R == -1) {
                    continue;
                }
                ans += j * (sum[j][R] - (L != -1 ? sum[j][L] : int64_t(0)));
            }
            cout << ans << "\n";
        }
    }
}
