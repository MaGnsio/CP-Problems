/**
 *    author:  MaGnsi0
 *    created: 18/06/2021 16:27:04
**/
#include <bits/stdc++.h>
#define int long long
using namespace std;

int32_t main() {
    ios_base::sync_with_stdio (0); cin.tie (0); cout.tie (0);
    int T;
    cin >> T;
    while (T--) {
        int n, m, x, y;
        cin >> n >> m >> x >> y;
        int cur = -1;
        pair<int, int> v[4] = {{1, 1}, {1, m}, {n, 1}, {n, m}}, a = {-1, -1}, b = {-1, -1};
        for (int i = 0; i < 4; ++i) {
            for (int j = i + 1; j < 4; ++j) {
                if (cur == -1) {
                    a = v[i], b = v[j];
                    cur = abs(x - v[i].first) + abs(y - v[i].second) + abs(v[i].first - v[j].first) + abs(v[i].second - v[j].second) + abs(v[j].first - x) + abs(v[j].second - y);
                    continue;
                }
                int dist = abs(x - v[i].first) + abs(y - v[i].second) + abs(v[i].first - v[j].first) + abs(v[i].second - v[j].second) + abs(v[j].first - x) + abs(v[j].second - y);
                if (dist > cur) {
                    a = v[i], b = v[j];
                    cur = dist;
                }
            }
        }
        cout << a.first << " " << a.second << " " << b.first << " " << b.second << "\n";
    }
}
