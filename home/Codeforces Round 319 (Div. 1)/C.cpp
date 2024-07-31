/**
 *    author:  MaGnsi0
 *    created: 31.07.2024 20:33:51
**/
#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n; cin >> n;
    map<int, vector<tuple<int, int, int>>> subgrids;
    for (int i = 0; i < n; ++i) {
        int x; cin >> x;
        int y; cin >> y;
        int j = x / 1000;
        subgrids[j].emplace_back(x, y, i);
    }
    for (auto& [j, points] : subgrids) {
        sort(points.begin(), points.end(), [&](tuple<int, int, int> a, tuple<int, int, int> b) {
                return (j & 1 ? get<1>(a) > get<1>(b) : get<1>(a) < get<1>(b));
            });
        for (auto [x, y, i] : points) {
            cout << i + 1 << " ";
        }
    }
}
