/**
 *    author:  MaGnsi0
 *    created: 01.02.2025 16:25:43
**/
#include <bits/stdc++.h>

using namespace std;

const int OO = 2e9;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int k; cin >> k;
    int m; cin >> m;
    vector<vector<pair<int, int>>> a(m);
    for (int i = 0; i < k; ++i) {
        int x; cin >> x;
        int y; cin >> y;
        a[x - 1].emplace_back(y, i);
    }
    int falls = OO;
    for (int i = 0; i < m; ++i) {
        sort(a[i].begin(), a[i].end());
        falls = min(falls, (int)a[i].size());
    }
    int last_fall = 0;
    vector<int> time(k, OO);
    for (int i = 0; i < falls; ++i) {
        int time_to_fall = last_fall;
        for (int j = 0; j < m; ++j) {
            time_to_fall = max(time_to_fall, a[j][i].first);
        }
        for (int j = 0; j < m; ++j) {
            time[a[j][i].second] = time_to_fall;
        }
        last_fall = time_to_fall;
    }
    int Q; cin >> Q;
    while (Q--) {
        int t; cin >> t;
        int j; cin >> j;
        cout << (t < time[j - 1] ? "Yes" : "No") << "\n";
    }
}
