/**
 *    author:  MaGnsi0
 *    created: 21.10.2023 19:10:39
**/
#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n; cin >> n;
    int m; cin >> m;
    int k; cin >> k;
    vector<string> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    int64_t x = n - 1, y = 0, time = 1;
    vector<tuple<bool, int, int, int, int64_t>> event(k);
    for (int i = 0; i < k; ++i) {
        string dir; cin >> dir;
        int dis; cin >> dis;
        if (dir == "up") {
            event[i] = {false, y, x, x - dis, time};
            x = x - dis, y = y, time = time + dis;
        } else if (dir == "down") {
            event[i] = {false, y, x, x + dis, time};
            x = x + dis, y = y, time = time + dis;
        } else if (dir == "left") {
            event[i] = {true, x, y, y - dis, time};
            x = x, y = y - dis, time = time + dis;
        } else {
            event[i] = {true, x, y, y + dis, time};
            x = x, y = y + dis, time = time + dis;
        }
    }
    reverse(event.begin(), event.end());
    vector<set<int>> unprocessedR(n), unprocessedC(m);
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            unprocessedR[i].insert(j);
            unprocessedC[j].insert(i);
        }
    }
    vector<vector<int64_t>> T(n, vector<int64_t>(m, 0));
    for (auto [r, j, from, to, t] : event) {
        if (r) {
            int y = min(from, to);
            while (true) {
                auto it = unprocessedR[j].lower_bound(y);
                if (it == unprocessedR[j].end()) { break; }
                int i = *it;
                if (i > max(from, to)) { break; }
                T[j][i] = t + abs(i - from);
                unprocessedR[j].erase(i);
                unprocessedC[i].erase(j);
                y = i;
            }
        } else {
            int x = min(from, to);
            while (true) {
                auto it = unprocessedC[j].lower_bound(x);
                if (it == unprocessedC[j].end()) { break; }
                int i = *it;
                if (i > max(from, to)) { break; }
                T[i][j] = t + abs(i - from);
                unprocessedC[j].erase(i);
                unprocessedR[i].erase(j);
                x = i;
            }
        }
    }
    int64_t low = 0, high = get<4>(event[0]) + abs(get<3>(event[0]) - get<2>(event[0]));
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            if (a[i][j] == '.') {
                if (T[i][j]) {
                    high = min(high, T[i][j] - 1);
                }
            } else {
                if (T[i][j]) {
                    low = max(low, T[i][j]);
                } else {
                    cout << -1 << " " << -1;
                    return 0;
                }
            }
        }
    }
    if (low > high) {
        cout << -1 << " " << -1;
    } else {
        cout << low << " " << high;
    }
}
