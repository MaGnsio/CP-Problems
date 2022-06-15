/**
 *    author:  MaGnsi0
 *    created: 14.05.2022 17:23:45
**/
#include <bits/stdc++.h>

using namespace std;

pair<bool, vector<int64_t>> solve(int64_t X, int64_t Y, vector<tuple<int64_t, int64_t, int64_t>> a, vector<pair<int64_t, int64_t>> b) {
    int64_t n = (int64_t)a.size();
    vector<bool> visited(n, false);
    vector<int64_t> ans(n);
    for (int64_t i = 0; i < n; ++i) {
        int64_t best = -1, x = X, y = Y;
        for (int64_t j = 0; j < n; ++j) {
            if (visited[j]) {
                continue;
            }
            int64_t d1 = (get<0>(a[i]) - x) * (get<0>(a[i]) - x) + (get<1>(a[i]) - y) * (get<1>(a[i]) - y);
            int64_t d2 = (get<0>(a[i]) - b[j].first) * (get<0>(a[i]) - b[j].first) + (get<1>(a[i]) - b[j].second) * (get<1>(a[i]) - b[j].second);
            int64_t d3 = (b[j].first - X) * (b[j].first - X) + (b[j].second - Y) * (b[j].second - Y);
            int64_t d4 = (x - X) * (x - X) + (y - Y) * (y - Y);
            if (d2 < d1 || (d1 == d2 && d3 >= d4)) {
                best = j, x = b[j].first, y = b[j].second;
            }
        }
        if (best == -1) {
            return make_pair(false, vector<int64_t>());
        } else {
            ans[i] = best;
            visited[best] = true;
        }
    }
    return make_pair(true, ans);
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int64_t T;
    cin >> T;
    for (int64_t t = 1; t <= T; ++t) {
        int64_t n;
        cin >> n;
        vector<tuple<int64_t, int64_t, int64_t>> a(n);
        vector<pair<int64_t, int64_t>> b(n);
        for (int64_t i = 0; i < n; ++i) {
            int64_t x, y;
            cin >> x >> y;
            a[i] = make_tuple(x, y, i);
        }
        sort(a.begin(), a.end());
        int64_t X, Y;
        cin >> X >> Y;
        for (int64_t i = 0; i < n; ++i) {
            cin >> b[i].first >> b[i].second;
        }
        bool good = true;
        for (int64_t i = 0; i < n; ++i) {
            bool ok = false;
            for (int64_t j = 0; j < n; ++j) {
                int64_t d1 = (get<0>(a[i]) - X) * (get<0>(a[i]) - X) + (get<1>(a[i]) - Y) * (get<1>(a[i]) - Y);
                int64_t d2 = (get<0>(a[i]) - b[j].first) * (get<0>(a[i]) - b[j].first) + (get<1>(a[i]) - b[j].second) * (get<1>(a[i]) - b[j].second);
                if (d1 >= d2) {
                    ok = true;
                }
            }
            good &= ok;
        }
        if (!good) {
            cout << "Case #" << t << ": " << "IMPOSSIBLE\n";
            continue;
        }
        bool ok = false;
        vector<int64_t> ans;
        do {
            auto res = solve(X, Y, a, b);
            if (res.first) {
                ans = res.second;
                ok = true;
                break;
            }
        } while (next_permutation(a.begin(), a.end()));
        if (ok) {
            cout << "Case #" << t << ": " << "POSSIBLE\n";
            for (int64_t i = 0; i < n; ++i) {
                cout << get<2>(a[i]) + 1 << " " << ans[i] + 2 << "\n";
            }
        } else {
            cout << "Case #" << t << ": " << "IMPOSSIBLE\n";
        }
    }
}
