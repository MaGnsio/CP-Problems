/**
 *    author:  MaGnsi0
 *    created: 19.08.2024 21:21:50
**/
#include <bits/stdc++.h>

using namespace std;
using P = pair<int64_t, int64_t>;

bool is_collinear(P a, P b, P c) {
    auto [x1, y1] = a;
    auto [x2, y2] = b;
    auto [x3, y3] = c;
    return (y2 - y1) * (x3 - x2) == (y3 - y2) * (x2 - x1);
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n; cin >> n;
    vector<P> points(n);
    for (auto& [x, y] : points) {
        cin >> x >> y;
    }
    map<pair<int, int>, int> mp;
    for (int i = 0; i < n; ++i) {
        for (int j = i + 1; j < n; ++j) {
            mp[make_pair(i, j)] = 2;
            for (int k = j + 1; k < n; ++k) {
                if (is_collinear(points[i], points[j], points[k])) {
                    mp[make_pair(i, j)]++;
                }
            }
        }
    }
    int max_line = 0;
    for (auto [_, c] : mp) {
        max_line = max(max_line, c);
    }
    int ans = min(n / 3, n - max_line);
    cout << ans;
}
