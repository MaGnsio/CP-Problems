/**
 *    author:  MaGnsi0
 *    created: 10.11.2024 17:14:43
**/
#include <bits/stdc++.h>

using namespace std;

const int OO = 2e9;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n; cin >> n;
    int m; cin >> m;
    int Q; cin >> Q;
    vector<vector<int>> a(m, vector<int>(n));
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            cin >> a[j][i];
        }
    }
    for (int i = 1; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            a[j][i] |= a[j][i - 1];
        }
    }
    while (Q--) {
        int k; cin >> k;
        map<int, pair<int, int>> c;
        while (k--) {
            int r; cin >> r; r--;
            char s; cin >> s;
            int x; cin >> x;
            if (!c.count(r)) {
                if (s == '<') {
                    c[r] = {-1, x - 1};
                } else {
                    c[r] = {x + 1, OO};
                }
            }
            if (s == '>') {
                c[r].first = max(c[r].first, x + 1);
            } else {
                c[r].second = min(c[r].second, x - 1);
            }
        }
        int low = 0, high = n - 1;
        for (auto [r, i] : c) {
            int L = i.first;
            int R = i.second;
            L = lower_bound(a[r].begin(), a[r].end(), L) - a[r].begin();
            R = upper_bound(a[r].begin(), a[r].end(), R) - a[r].begin() - 1;
            low = max(low, L);
            high = min(high, R);
        }
        cout << (low > high ? -1 : low + 1) << "\n";
    }
}
